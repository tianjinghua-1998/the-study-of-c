#define _CRT_SECURE_NO_WARNINGS 
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "syst.h"
struct BinaryTreeNode;
#define QueueElemType int
#define QDataType struct BinaryTreeNode*
#define Queue_Default_Size 5
typedef struct SeqQueue
{
	QueueElemType* base;
	//ELEMTYPE data;
	int capacity;
	int front;//��ͷ
	int rear;//��β
}SeqQueue;
void SeqQueueInit(SeqQueue *sq,int sz);
void SeqQueueEn(SeqQueue *sq,int x);
void SeqQueueDe(SeqQueue *sq);
size_t SeqQueueBack(SeqQueue *sq);
size_t SeqQueueFront(SeqQueue *sq);
void SeqQueueDestroy(SeqQueue *sq);
void SeqQueueShow(SeqQueue *sq);
size_t SeqQueueSz(SeqQueue *sq);
size_t SeqQueueSz(SeqQueue *sq)
{
	assert(sq);
	return sq->rear - sq->front;
}
size_t SeqQueueBack(SeqQueue *sq)
{
	assert(sq && (sq->front != sq->rear));
	return sq->base[(sq->rear + sq->capacity)%(sq->capacity+1)];
}
size_t SeqQueueFront(SeqQueue *sq)
{
	assert(sq && (sq->front != sq->rear));
	return sq->base[sq->front];

}
void SeqQueueInit(SeqQueue *sq, int sz)
{
	assert(sq);
	sq->capacity = sz > Queue_Default_Size ? sz : Queue_Default_Size;
	sq->base = (QueueElemType *)malloc(sizeof(QueueElemType)* (sq->capacity+1));
	sq->front = sq->rear = 0;
}
void SeqQueueEn(SeqQueue *sq, int x)
{
	assert(sq);
	if (sq->rear >= sq->capacity)
	{
		printf("����������%d�������\n",x);
		return;
	}
	else
	{
		sq->base[sq->rear++] = x;
		//sq->rear++;
	}
}
void SeqQueueDe(SeqQueue *sq)
{
	if (sq->front == sq->rear)
	{
		printf("�����ѿգ�����ɾ��\n");
		return;
	}
	else
	{
		sq->front++;
	}
}
void SeqQueueShow(SeqQueue *sq)
{
	for (int i = sq->front; i < sq->rear; i++)
	{
		printf("%d\n", sq->base[i]);
	}
}
void SeqQueueDestroy(SeqQueue *sq)
{
	free(sq->base);
	sq->base = NULL;
	sq->capacity = 0;
	sq->front = 0;
	sq->rear = 0;
}
///////////////////ѭ������//////////////////////
void CirSeqQueueEn(SeqQueue *sq, int x);
void CirSeqQueueDe(SeqQueue *sq);
void CirSeqQueueShow(SeqQueue *sq);
size_t CirSeqQueueBack(SeqQueue *sq);
size_t CirSeqQueueFront(SeqQueue *sq);
void CirSeqQueueEn(SeqQueue *sq, int x)
{
	assert(sq);
	if ((sq->rear+1) % (sq->capacity+1) == sq->front)
	{
		printf("����������%d���ܲ���\n", x);
	}
	//�����ʱ��i�洢
	else
	{
		sq->base[sq->rear] = x;
		sq->rear = (sq->rear + 1) % (sq->capacity + 1);
	}
}
void CirSeqQueueDe(SeqQueue *sq)
{
	if (sq->rear == sq->front)
	{
		printf("�����ѿգ�����ɾ��\n");
	}
	else
	{
		sq->front = (sq->front + 1) % (sq->capacity + 1);
	}
}
void CirSeqQueueShow(SeqQueue *sq)
{
	
	for (int i = sq->front; i !=sq->rear;)
	{
		printf("%d\n", sq->base[i]);
		i = (i + 1) % (sq->capacity + 1);
	}
}
////////////////��ʽ����////////////////////////////
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}
QNode* _BuyCode(QDataType x)
{
	QNode *s = (QNode*)malloc(sizeof(QNode));
	assert(s);
	s->_data = x;
	s->_next = NULL;
	return s;
}
void QueuePush(Queue* q, QDataType data)
{
	QNode *s = _BuyCode(data);
	assert(s);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = s;
	}
	else
	{
		q->_rear->_next = s;
		q->_rear = q->_rear->_next;
	}
}
void QueuePop(Queue* q)
{
	//assert(q->_front != NULL);
	QNode *p = q->_front;
	if (q->_front == NULL)
		return;
	q->_front = p->_next;
	//βָ��ҲҪ���ա�
	if (q->_front == NULL)
		q->_rear = NULL;
	free(p);
	p = NULL;
}
void QueueShow(Queue *q)
{
	QNode *p = q->_front;
	while (p != NULL)
	{
		printf("%d\n", p->_data);
		p = p->_next;
	}
}
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
int QueueSize(Queue* q)
{
	int size = 0;
	while (q->_front != NULL)
	{
		size++;
		q->_front=q->_front->_next;
	}
	return size;
}
bool QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}
void QueueDestroy(Queue* q)
{
	if (q->_front == NULL)
		return;
	else
	{
		while (q->_front != NULL)
		{
			QueuePop(q);
		}
	}
}
#endif