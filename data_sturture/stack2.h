#include "syst.h"
//进行一个声明
typedef struct BinaryTreeNode BTNode;
#define STACKELEMTYPE BTNode*
typedef struct StackNode
{
	STACKELEMTYPE data;
	struct StackNode *next;
}StackNode;
typedef struct Stack
{
	StackNode* top;
}Stack;
void StackPush(Stack *pst, STACKELEMTYPE x);
void StackPop(Stack *pst);
STACKELEMTYPE Stacktop(Stack *pst);
bool StackIsEmpty(Stack* pst);
void StackDestroy(Stack* pst);
void StackShow(Stack* pst);
Stack* StackInit()
{
	Stack*p = (Stack*)malloc(sizeof(Stack));
	p->top = NULL;
	return p;
}
bool StackIsEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == NULL;
}
void StackPush(Stack *pst,STACKELEMTYPE x)
{
	assert(pst != NULL);
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	StackNode *p = pst->top;
	s->data = x;
	s->next = pst->top;
	pst->top = s;
}
void StackPop(Stack *pst)
{
	assert(pst != NULL);
	StackNode *p = pst->top;
	pst->top = p->next;
	free(p);
}
STACKELEMTYPE Stacktop(Stack *pst)
{
	assert(pst && pst->top != NULL);
	return pst->top->data;
}
void StackDestroy(Stack* pst)
{
	StackNode *p = pst->top;
	while (p!= NULL)
	{
		p = pst->top->next;
		free(pst->top);
		pst->top = p;
	}
}
void StackShow(Stack* pst)
{
	assert(pst);
	StackNode *p = pst->top;
	while (p!= NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("->\n");
}