#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST2_H_
#define _LIST2_H_
#define ELEMTYPE int
#include "syst.h"
typedef struct SListNode
{
	ELEMTYPE data;
	struct SListNode *next;
}SListNode;
typedef struct Slist
{
	 SListNode* head; //成员的封装
}Slist;
void SlistInit(Slist* plist);
void SlistPushBack(Slist* plist, ELEMTYPE x);
void SlistPushFront(Slist* plist, ELEMTYPE x);
void SlistShow(Slist* plist);
void SlistPopBack(Slist* plist);
void SlistPopFront(Slist* plist);
int SlistLength(Slist* plist);
void SlistInsert_Val(Slist* plist, ELEMTYPE key);
void SlistDel_Val(Slist* plist, ELEMTYPE key);
SListNode* SlistFind(Slist* plist, ELEMTYPE key);
void SlistReverse(Slist* plist);
void SlistSort(Slist* plist);
void SlistClear(Slist* plist);
void SlistDestroy(Slist* plist);
void SlistRemoveAll(Slist* plist, ELEMTYPE key);
void SlistInit(Slist* plist)
{
	plist->head = NULL;
}
SListNode* _Buynode()
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}
void SlistPushBack(Slist* plist, ELEMTYPE x)
{
	//1.链表一个元素都没有时;
	//2.需要考虑链表已经满的情况吗？节点（结构体）是动态内存生成的，不用考虑。
	assert(plist);
	SListNode * s = _Buynode();
	s->data = x;
	//这句话出现在了_Buynode()里面，所以不用在这里写啦！
	//s->next = NULL;
	SListNode *p = plist->head;
	//当插入的为第一个节点时，程序会报错，因为此时head为空，p指向head
	//对空指针解引用会报错的呢！程序就崩溃了，所以应当考虑当链表为空的情况下。
	if (p == NULL)
	{
		//p = s;
		//这么写是错的哦，因为p指向了新生成的内存区域s,而head还是为空，p再折腾
		//也是个临时指针，你就瞎蹦跶叭！出了函数区域就被销毁了，再折腾也木有用哈！
		plist->head = s;
	}
	else 
	{
		//正确的思路：尾部插入的时候最后一个结点里面的next指针域应该为空，所以我们只需要判断
		//p->next是否为空，如果不为空，证明不是最后一个结点，p指向下一个结点即：p=p->next。
		//直到p->next=NULL,到达最后一个结点，令p->next=s;那么就好啦！
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	
		//******************************************************************//
		//嘿嘿嘿，又是个错误的代码，比如11-12的，这么写没有毛病。
		//问题的关键在那里呢，每次进来的时候临时指针p都是指向了头节点，而不再
		//指向下一个结点，所以如果是11-12，进来滴话，p指向head，然后p->next=s。
		//所以p->next指向的是13，所以就变成11-13啦,和想象中的不太一样呢！
		//而在list.h中，是在函数内部通过for循环生成的，所以p一开始指向head只进来了一次。
		/*s->next = NULL;
		p->next = s;
		p = s;*/
	}
	
}
void SlistShow(Slist* plist)
{
	assert(plist);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d--> ", p->data);
		p = p->next;
	}
	printf("over\n");
}
void SlistPushFront(Slist* plist, ELEMTYPE x)
{
	assert(plist);
	//1.产生头结点空间；
	//2.产生新的节点内存空间
	//2种情况，链表一个节点都没有时候，链表里面已经有子节点的时候。
	SListNode* s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
	//****************************************************//
	//头插的话不需要判断是否为第一个节点，因为尾插的需要找它的next节点，而头部插入不需要。
	//即使第一个节点为空，那么s-next=NULL,s-data=x,此时plist-data指向了新的结点s;
	/*SListNode* p = plist->head;
	if (p == NULL)
	{
		plist->head = s;
	}
	else
	{
		s->next = plist->head;
		plist->head = s;
	}*/
}
void SlistPopBack(Slist* plist)
{
	assert(plist);
	//尾部删除，如果链表为空,那么不能删除的.
	//链表不为空，考虑只有1个结点，以及结点个数大于1的情况。
	SListNode* p = plist->head;
	//当p为空的时候，p->next就已经是错误的写法了！
	if (p != NULL)
	{
		//只含有1个结点
		//写的时候NULL放在前面呀！！我这么写p->next=NULL,相当于p->next=0，为假，所以就没执行。
		if (NULL == p->next)
		{
			plist->head = NULL;//这句话不能少！！少了有问题呢！！
			free(p);
			p = NULL;
			//或者直接free(plist->head),plist->head=NULL;
		}
		else
		{
			SListNode* pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
			free(p);
			p = NULL;
		}
	}
}
void SlistPopFront(Slist* plist)
{
	assert(plist);
	//不需要考虑只有1个结点还是多个节点
	SListNode* p = plist->head;
	if (p != NULL)
	{
		/*p = p->next;
		plist->head = p;*/
		plist->head = p->next;
		free(p);
		p = NULL;
	}
}
int SlistLength(Slist* plist)
{
	assert(plist);
	int len = 0;
	SListNode* p = plist->head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
SListNode* SlistFind(Slist* plist, ELEMTYPE key)
{
	assert(plist);
	SListNode *p = plist->head;
	//与条件
	//第一个和第二个不能交换。
	//因为是在p!=NULL的条件下，再判断p->data是否等于key;
	//查找的结点不存在，程序会崩溃，写反滴话
	//(p->data !=key&&p!=NULL)，多个条件需要判断顺序，这么写当p=NULL的时候，不能对其
	//解引用，程序就会崩溃。
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
void SlistClear(Slist* plist)
{
	//漏算了链表为空的情况
	do
	{
		SListNode *p = plist->head;
		plist->head = p->next;
		free(p);
	} while (plist->head!=NULL);
}
void SlistDel_Val(Slist* plist, ELEMTYPE key)
{
	SListNode *p = plist->head;
	SListNode *pre = NULL;

	//1.首先要查找有没有该元素
	while (p != NULL && p->data != key)
	{

		pre = p;
		p = p->next;
	}

	//如果要查找的元素是第一个元素的话。
	//else不能满足，因为此时pre为空，不能对其解引用next；
	//p不为null,
	if (p != NULL)
	{
		if (pre == NULL)
			plist->head = p->next;
		else
			pre->next = p->next;
		free(p);
	}
}
void SlistInsert_Val(Slist* plist, ELEMTYPE key)
{
		SListNode *s = _Buynode();
		s->data = key;
		SListNode *p = plist->head;
		SListNode *pre = NULL;
		while (p != NULL && s ->data > p->data)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)
		{
			s->next = plist->head;
			plist->head = s;
		}
		else
		{
			s->next = pre->next;
			pre->next = s;
		}
}
void SlistReverse(Slist* plist)
{
	SListNode *p, *q;
	p = plist->head;
	q = p;
	//链表为空时，直接返回；
	if (p == NULL)
		return;
	//如果只有1个结点的话，那么没必要反转
	if (plist->head->next == NULL)
		return;
	//1.切割链表
	p = p->next;
	plist->head->next = NULL;
	//2.头部插入
	while (p!=NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}
void SlistSort(Slist* plist)
{
	assert(plist);
	SListNode *p = plist->head;
	if (p == NULL)
		return;
	
	//要放到循环里面，因为每次进来的话，pre都需要置为空，从头结点开始比较。
	//SListNode *pre = NULL;
	p = plist->head->next;
	plist->head->next = NULL;
	//注意这里的顺序，放在最上面就错了，因为q里面实际上存储的是plist->head的地址，
	//所以下面p虽然向后移动了，但是q里面的地址并没改变，所以q的值和plist->head的值相等。
	SListNode *q = p;
	while (q!=NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode *pre = NULL;
		while (t!= NULL && p->data > t->data)
		{
			//记录t的上一个结点
			pre = t;
			t = t->next;
		}
		if (NULL == pre)
		{
			p->next=plist->head;
			plist->head = p;
		}
		else
		{
			//注意是p而不是t
			p->next = pre->next;
			pre->next = p;
		}
		p = q;
	}
}
void SlistRemoveAll(Slist* plist, ELEMTYPE key)
{
	SListNode *p = plist->head;
	//pre=NULL,不必写入循环内部，因为是删除，只需要向后遍历即可，而排序的话，因为
	//每插入1个元素，要和所有的元素都要进行比较。
	SListNode *pre = NULL;
	//头结点为空时，写在前面，这样一旦为空，就会返回。
	if (plist->head == NULL)
		return;
	while (p != NULL)
	{
		//删除一个值
		while (p != NULL && p->data != key)
		{
			pre = p;
			p = p->next;
		}
		
		if (p != NULL)
		{
			//要删除的元素为第一个元素
			if (pre == NULL)
			{
				plist->head = p->next;
			}
			else
			{
				pre->next = p->next;
			}
			free(p);
		}
		
		if (pre == NULL)
		{
			//要删除的元素为第一个元素，删除完毕之后，让p重新指向头结点，继续寻找。
			p = plist->head;
		}
		else
		{
			//p指向已经被删除结点的下一个结点。
			p = pre->next;
		}

	}
}
#endif