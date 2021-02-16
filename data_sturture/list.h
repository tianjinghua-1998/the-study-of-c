#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST_H_
#define _LIST_H_
#define ELEMTYPE int
#include "syst.h"
//1.创建1个节点
typedef struct SListNode
{
	ELEMTYPE data;
	//结构体的自引用，该指针可以指向同一类型的不同的结构体；
	//即为指向该类型的指针
	//刚开始写错了！没写struct
	struct SListNode *next;
}SListNode;
typedef SListNode* Slist;
void SlistInit(Slist *head);
void SlistCreate_Tail(Slist *head);
void SlistCreate_Head(Slist *head);
void SlistShow(Slist head);
//void BuyCode();
void SlistInit(Slist *head)
{
	*head= NULL;
	//将第一个节点的指针置为空指针，即不指向任何变量，因为0地址处不存储任何变量
	//不能对空指针解引用
}
//void SlistCreate_Tail(SListNode *head)
//{
//	//不带头节点的创建
//	*head= (SListNode *)malloc(sizeof(SListNode));
//	(*head)->data = 1;
//	(*head)->next = NULL;
//	SListNode* p = *head;
//	SListNode *s = NULL;
//	for (int i = 2; i <5 ; i++)
//	{
//		SListNode *s = (SListNode *)malloc(sizeof(SListNode));
//		//加上断言
//		assert(s != NULL);
//		s->data = i;
//		s->next = NULL;
//		p->next = s;
//		p= s;//p指向s的意思；
//	}
//}
void SlistCreate_Head(Slist *head)
{
	//2-1
	//1.创建头节点1，
	//2.创建节点2(s),节点2指向节点1，调整head指向2；
	*head = (SListNode *)malloc(sizeof(SListNode));
	(*head)->data = 1;
	(*head)->next = NULL;
	//这里并不需要创建一个临时的指针p了，因为是头部插入，5，4，3，2，1
	//每一次*head都会指向最新的结点，例如*head指向的是2，那么*head->next里面存放的
	//是1的地址，依次类推，可以找到生成的每一个结点。
	for (int i = 2; i < 5; i++)
	{
		SListNode *s = (SListNode *)malloc(sizeof(SListNode));
		s->data = i;
		s->next = *head;
		*head = s;
	}
}
void SlistShow(Slist head)
{
	/*for (int i = 0; i < 4; i++)
	{

	}*///错误写法
	SListNode* p = head;
	while (p != NULL)
	{
		printf("%d-> ",p->data);
		p = p->next;
	}
	printf("over\n");
}

#endif