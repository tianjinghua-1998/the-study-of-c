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
	 SListNode* head; //��Ա�ķ�װ
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
	//1.����һ��Ԫ�ض�û��ʱ;
	//2.��Ҫ���������Ѿ���������𣿽ڵ㣨�ṹ�壩�Ƕ�̬�ڴ����ɵģ����ÿ��ǡ�
	assert(plist);
	SListNode * s = _Buynode();
	s->data = x;
	//��仰��������_Buynode()���棬���Բ���������д����
	//s->next = NULL;
	SListNode *p = plist->head;
	//�������Ϊ��һ���ڵ�ʱ������ᱨ����Ϊ��ʱheadΪ�գ�pָ��head
	//�Կ�ָ������ûᱨ����أ�����ͱ����ˣ�����Ӧ�����ǵ�����Ϊ�յ�����¡�
	if (p == NULL)
	{
		//p = s;
		//��ôд�Ǵ��Ŷ����Ϊpָ���������ɵ��ڴ�����s,��head����Ϊ�գ�p������
		//Ҳ�Ǹ���ʱָ�룬���Ϲ���Q�ȣ����˺�������ͱ������ˣ�������Ҳľ���ù���
		plist->head = s;
	}
	else 
	{
		//��ȷ��˼·��β�������ʱ�����һ����������nextָ����Ӧ��Ϊ�գ���������ֻ��Ҫ�ж�
		//p->next�Ƿ�Ϊ�գ������Ϊ�գ�֤���������һ����㣬pָ����һ����㼴��p=p->next��
		//ֱ��p->next=NULL,�������һ����㣬��p->next=s;��ô�ͺ�����
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	
		//******************************************************************//
		//�ٺٺ٣����Ǹ�����Ĵ��룬����11-12�ģ���ôдû��ë����
		//����Ĺؼ��������أ�ÿ�ν�����ʱ����ʱָ��p����ָ����ͷ�ڵ㣬������
		//ָ����һ����㣬���������11-12�������λ���pָ��head��Ȼ��p->next=s��
		//����p->nextָ�����13�����Ծͱ��11-13��,�������еĲ�̫һ���أ�
		//����list.h�У����ں����ڲ�ͨ��forѭ�����ɵģ�����pһ��ʼָ��headֻ������һ�Ρ�
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
	//1.����ͷ���ռ䣻
	//2.�����µĽڵ��ڴ�ռ�
	//2�����������һ���ڵ㶼û��ʱ�����������Ѿ����ӽڵ��ʱ��
	SListNode* s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
	//****************************************************//
	//ͷ��Ļ�����Ҫ�ж��Ƿ�Ϊ��һ���ڵ㣬��Ϊβ�����Ҫ������next�ڵ㣬��ͷ�����벻��Ҫ��
	//��ʹ��һ���ڵ�Ϊ�գ���ôs-next=NULL,s-data=x,��ʱplist-dataָ�����µĽ��s;
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
	//β��ɾ�����������Ϊ��,��ô����ɾ����.
	//����Ϊ�գ�����ֻ��1����㣬�Լ�����������1�������
	SListNode* p = plist->head;
	//��pΪ�յ�ʱ��p->next���Ѿ��Ǵ����д���ˣ�
	if (p != NULL)
	{
		//ֻ����1�����
		//д��ʱ��NULL����ǰ��ѽ��������ôдp->next=NULL,�൱��p->next=0��Ϊ�٣����Ծ�ûִ�С�
		if (NULL == p->next)
		{
			plist->head = NULL;//��仰�����٣��������������أ���
			free(p);
			p = NULL;
			//����ֱ��free(plist->head),plist->head=NULL;
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
	//����Ҫ����ֻ��1����㻹�Ƕ���ڵ�
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
	//������
	//��һ���͵ڶ������ܽ�����
	//��Ϊ����p!=NULL�������£����ж�p->data�Ƿ����key;
	//���ҵĽ�㲻���ڣ�����������д���λ�
	//(p->data !=key&&p!=NULL)�����������Ҫ�ж�˳����ôд��p=NULL��ʱ�򣬲��ܶ���
	//�����ã�����ͻ������
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
void SlistClear(Slist* plist)
{
	//©��������Ϊ�յ����
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

	//1.����Ҫ������û�и�Ԫ��
	while (p != NULL && p->data != key)
	{

		pre = p;
		p = p->next;
	}

	//���Ҫ���ҵ�Ԫ���ǵ�һ��Ԫ�صĻ���
	//else�������㣬��Ϊ��ʱpreΪ�գ����ܶ��������next��
	//p��Ϊnull,
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
	//����Ϊ��ʱ��ֱ�ӷ��أ�
	if (p == NULL)
		return;
	//���ֻ��1�����Ļ�����ôû��Ҫ��ת
	if (plist->head->next == NULL)
		return;
	//1.�и�����
	p = p->next;
	plist->head->next = NULL;
	//2.ͷ������
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
	
	//Ҫ�ŵ�ѭ�����棬��Ϊÿ�ν����Ļ���pre����Ҫ��Ϊ�գ���ͷ��㿪ʼ�Ƚϡ�
	//SListNode *pre = NULL;
	p = plist->head->next;
	plist->head->next = NULL;
	//ע�������˳�򣬷���������ʹ��ˣ���Ϊq����ʵ���ϴ洢����plist->head�ĵ�ַ��
	//��������p��Ȼ����ƶ��ˣ�����q����ĵ�ַ��û�ı䣬����q��ֵ��plist->head��ֵ��ȡ�
	SListNode *q = p;
	while (q!=NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode *pre = NULL;
		while (t!= NULL && p->data > t->data)
		{
			//��¼t����һ�����
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
			//ע����p������t
			p->next = pre->next;
			pre->next = p;
		}
		p = q;
	}
}
void SlistRemoveAll(Slist* plist, ELEMTYPE key)
{
	SListNode *p = plist->head;
	//pre=NULL,����д��ѭ���ڲ�����Ϊ��ɾ����ֻ��Ҫ���������ɣ�������Ļ�����Ϊ
	//ÿ����1��Ԫ�أ�Ҫ�����е�Ԫ�ض�Ҫ���бȽϡ�
	SListNode *pre = NULL;
	//ͷ���Ϊ��ʱ��д��ǰ�棬����һ��Ϊ�գ��ͻ᷵�ء�
	if (plist->head == NULL)
		return;
	while (p != NULL)
	{
		//ɾ��һ��ֵ
		while (p != NULL && p->data != key)
		{
			pre = p;
			p = p->next;
		}
		
		if (p != NULL)
		{
			//Ҫɾ����Ԫ��Ϊ��һ��Ԫ��
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
			//Ҫɾ����Ԫ��Ϊ��һ��Ԫ�أ�ɾ�����֮����p����ָ��ͷ��㣬����Ѱ�ҡ�
			p = plist->head;
		}
		else
		{
			//pָ���Ѿ���ɾ��������һ����㡣
			p = pre->next;
		}

	}
}
#endif