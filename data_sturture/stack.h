#include "syst.h"
#define ELEMTYPE int
//˳��ջ
#define ELEM_DEFALUT_SIZE 8
//typedef struct SeqStack
//{
//	ELEMTYPE* base;
//	int capcity;
//	int top;
//}SeqStack;
//void SeqStackPush(SeqStack *ss, ELEMTYPE x);
//void SeqStackPop(SeqStack *ss);
//ELEMTYPE SeqStackTop(SeqStack *ss);
//void SeqStackShow(SeqStack *ss);
//void SeqStackInit(SeqStack *ss,int sz)
//{
//	ss->capcity = sz >=ELEM_DEFALUT_SIZE ? sz : ELEM_DEFALUT_SIZE;
//	ss->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*sz);
//	assert(ss->base != NULL);
//	ss->top = 0;
//}
//void SeqStackPush(SeqStack *ss, ELEMTYPE x)
//{
//	assert(ss->base != NULL);
//	if (ss->top >=ss->capcity)
//	{
//		printf("ջ�Ѿ�����%d���ܲ���\n", x);
//	}
//	ss->base[ss->top++] = x;
//}
//ELEMTYPE SeqStackTop(SeqStack *ss)
//{
//	assert(ss->base != NULL);
//	return ss->base[(ss->top) - 1];
//}
////��ջ
//void SeqStackPop(SeqStack *ss)
//{
//	assert(ss->base != NULL);
//	if (ss->top == 0)
//	{
//		printf("ջ�Ѿ��գ�����ɾ��Ԫ��\n");
//	}
//	ss->top--;
//}
//void SeqStackShow(SeqStack *ss)
//{
//	assert(ss->base);
//	for (int i = ss->top - 1; i>=0; i--)
//	{
//		printf("%d\n", ss->base[i]);
//	}
//}
