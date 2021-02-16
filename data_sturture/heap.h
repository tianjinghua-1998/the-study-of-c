#define _CRT_SECURE_NO_WARNINGS 
#ifndef HEAP_H_
#define HEAP_H_
#include "syst.h"
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap *hp,int n);
void HeapInit(Heap *hp,int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_capacity = n;
	memset(hp->_a, 0, n);
	hp->_size = 0;
}
//堆的创建
void HeapCreate(Heap* hp, HPDataType* a, int n);
//堆的销毁
void HeapDestory(Heap* hp);
//堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 堆的判满
int HeapFULL(Heap *hp);
void _AdjustDownUp(Heap *hp,int start);
void _AdjustUpDown(Heap *hp, int start);
void HeapShow(Heap *hp);
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}
int HeapFULL(Heap *hp)
{
	return hp->_size >= hp->_capacity ? 1 : 0;
}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(*a) * n);
	assert(hp->_a);
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = *(a + i);
	}
	int curpos = n / 2 - 1;
	while (curpos >= 0)
	{
		_AdjustUpDown(hp,curpos);
		curpos--;
	}
}
//进行扩容
bool _INC(Heap *hp)
{
	HPDataType * new_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*(hp->_capacity * 2));
	if (new_a == NULL)
		return false;
	hp->_a =new_a;
	hp->_capacity *= 2;
	return true;
}
void HeapPush(Heap* hp, HPDataType x)
{
	//两个顺序不能交换，当空间满的情况下：再考虑扩容;如果将！_INC_写在前面，那么无论
	//空间是否满，都会扩容。
	if (HeapFULL(hp)&&!_INC(hp))
	{
		printf("堆已经满，扩容失败，%d不能插入\n", x);
	}
	else
	{
		//顺序表的插入/顺序栈的插入/顺序队列的插入都一样;
		hp->_a[hp->_size] = x;
		_AdjustDownUp(hp, hp->_size);
		 hp->_size++;
	}
}
void HeapShow(Heap *hp)
{
	for (int i = 0; i < hp->_size; i++)
		printf("%d ", hp->_a[i]);
	printf("\n");
}
void _AdjustDownUp(Heap *hp,int start)
{
	int j = start;//代表子节点
	int i = (j - 1) / 2;//代表父节点
	int tmp = hp->_a[j];
	while (j >0 )
	{
		if (hp->_a[i] > tmp)
		{
			hp->_a[j] = hp->_a[i];
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	hp->_a[j] = tmp;
}
//堆的删除
void HeapPop(Heap* hp)
{
	hp->_size--;
	hp->_a[0] = hp->_a[hp->_size];
	_AdjustUpDown(hp, 0);
}
void _AdjustUpDown(Heap *hp, int start)
{
	int i = start;
	int j = 2 * i + 1;
	int tmp = hp->_a[i];
	while (j < hp->_size)
	{
		if (j + 1< hp->_size && hp->_a[j] > hp->_a[j + 1])
			j = j + 1;
		if (hp->_a[j] < tmp)
		{
			hp->_a[i] = hp->_a[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	hp->_a[i] = tmp;
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	return hp->_size;
}
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
#endif