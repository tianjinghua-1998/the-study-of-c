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
//�ѵĴ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
//�ѵ�����
void HeapDestory(Heap* hp);
//�ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// �ѵ�����
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
//��������
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
	//����˳���ܽ��������ռ���������£��ٿ�������;�������_INC_д��ǰ�棬��ô����
	//�ռ��Ƿ������������ݡ�
	if (HeapFULL(hp)&&!_INC(hp))
	{
		printf("���Ѿ���������ʧ�ܣ�%d���ܲ���\n", x);
	}
	else
	{
		//˳���Ĳ���/˳��ջ�Ĳ���/˳����еĲ��붼һ��;
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
	int j = start;//�����ӽڵ�
	int i = (j - 1) / 2;//�����ڵ�
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
//�ѵ�ɾ��
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