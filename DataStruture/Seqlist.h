#include "Sysutil.h"
#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 5
size_t i = 0;
typedef struct Seqlist
{
	//指向这块内存空间的指针。
	ELEMTYPE *base;
	//开辟的内存空间的容量。
	size_t capacity;
	//里面存放数据的大小
	size_t size;

}Seqlist;
//这里的结构体类型的指针，pst为结构体类型的，而不是int*
void SeqlistInit(Seqlist *pst);
void SeqlistPushBack(Seqlist *pst,ELEMTYPE x);
void SeqlistShowList(Seqlist *pst);
void SeqlistPushFront(Seqlist *pst, ELEMTYPE x);
void SeqlistPopBack(Seqlist *pst);
void SeqlistPopFront(Seqlist *pst);
int Seqlistlength(Seqlist *pst);
int SeqlistCapcity(Seqlist *pst);
void SeqlistClear(Seqlist *pst);
void SeqlistDestroy(Seqlist *pst);
void SeqlistSort(Seqlist *pst);
int SeqlistFind(Seqlist *pst, ELEMTYPE x);
void SeqlistDelVal(Seqlist *pst,ELEMTYPE item);
bool IsFull(Seqlist *pst)
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(Seqlist *pst)
{
	return pst->size == 0;
}
void SeqlistInit(Seqlist *pst)
{
	pst->base = (ELEMTYPE*)malloc(SEQLIST_DEFAULT_SIZE * sizeof(ELEMTYPE));
	//pst->base = NULL;
	//申请的空间不为空，再继续往下进行，若为空，代表申请失败，一定要assert。
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
void SeqlistPushBack(Seqlist *pst, ELEMTYPE x)
{
	 assert(pst);
	//满的话，不能插入，如果插入的话相当于是越界了。
	// assert(!IsFull(pst));
	 assert(!IsFull(pst));
	//将x放在第size+1个位置。因为arr[i]代表的是第i+1个元素，因为目前的顺序表的元素
	//大小为size,尾插一个，即在 size+1的地方插入。
	pst->base[pst->size] = x;
	pst->size++;
}
void SeqlistShowList(Seqlist *pst)
{
	assert(pst);
	size_t i = 0;
	for (i = 0; i<pst->size;i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
void SeqlistPushFront(Seqlist *pst, ELEMTYPE x)
{
	//必须要断言一下
	assert(pst!=NULL);
	//这样写是不对的。
	assert(IsFull(pst));
	//判满
	for (i = pst->size; i>0;i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[i] = x;
	pst->size++;
	//错误写法
	//x = pst->base[i];
	//错误写法，应当是把pst->size++,而不是base++;pst->base++;
}
void SeqlistPopBack(Seqlist *pst)
{
	if (IsEmpty(pst))
	{
		printf("顺序表已经空，不能被删除\n");
	}
	pst->size--;
}
void SeqlistPopFront(Seqlist *pst)
{
	if (IsEmpty(pst))
	{
		printf("顺序表已经空，不能被删除\n");
	}
	for (i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	//这一行必须要有；否则size里面的默认大小为0，初始化的时候为0；
	pst->size--;
}
int Seqlistlength(Seqlist *pst){ return pst->size; }
int SeqlistCapcity(Seqlist *pst){ return pst->capacity;}
void SeqlistClear(Seqlist *pst){ pst->size = 0; }
void SeqlistDestroy(Seqlist *pst)
{
	assert(pst);
	free(pst->base);
	//动态开辟的内存要进行释放，否则会进行内存泄漏。
	//将base要置为空指针，否则容易造成内存泄漏。
	pst->base = NULL;
	pst->capacity = 0;
	pst->size = 0;
}
//冒泡排序的思想
//两个循环，外层循环来控制趟数，例如9,8,7；按照从小到大的顺序。
//第一趟，将9放在最后1个，
//第二趟，将8放在最后一个，
//那么不需要第三趟了，因为7自然在第一个。
//i个元素需要i-1趟;
//9，8，7，6，5
//每一趟：9最坏的可能，需要4次比较。
//8的话需要3次比较，因为最大的元素已经在最后。
void SeqlistSort(Seqlist *pst)
{
	size_t j = 0;
	int max = pst->base[i];
	for (i = 0; i <(pst->size)-1; i++)
	{
		//控制每一趟,交换两个数；
		for (j = 0; j < (pst->size) - 1 - i; j++)
		{
			//似乎没有用；
			//max = pst->base[j];
			if (pst->base[j]>pst->base[j + 1])
			{
				//交换两个数;
				int tmp = 0;
				tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}
int SeqlistFind(Seqlist *pst, ELEMTYPE x)
{
	//顺序查找法;
	for (i = 0; i < pst->size; i++)
	{
		if (x == pst->base[i])
			return i+1;
	}
	return -1;
}
void SeqlistDelVal(Seqlist *pst,ELEMTYPE item)
{
	//嘿嘿，这里要注意哦，传入的参数就是为pst,本身就是一个地址；而不用取地址的；
	int index = SeqlistFind(pst, item);
	if (index == -1)
		printf("要删除的元素不存在\n");
	return;
	//for (i = item; i < pst->size; i++)
	//{
	//	pst->base[i] = pst->base[i + 1];
	//	//少了元素个数减少;
	//	pst->size--;
	//}
}