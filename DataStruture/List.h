#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST_H_
#define _LIST_H_
#include "Sysutil.h"
typedef struct ListNode
{
	int data; //数据域
	//里面存放的是下一个结构体的地址；
	struct ListNode *next; //指向下一个节点的结构体指针
}ListNode;
typedef ListNode* List; //将指针重定义为结点，那么可读性就会提高。
void ListInit(List *head)
{
	//*head = NULL;
}
void ListCreate_Tail(List * head)
{
	//这里的mylist实际上已经代表一个结构体指针了，即是指向这块结构体区域首元素的地址；
	//所以通过mylist->data可以找到结构体内部的元素；
	*head = (ListNode *)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	ListNode *p = *head;
	for (int i = 2; i < 10; i++)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}
void ListCreate_Head(List *head)
{
	*head = (ListNode *)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->next = NULL;
	(*head)->data = 1 ;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = *head;
		//头部插入之后，*head指向s;
		*head = s;
	}
}
void ListShow(List head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
SListNode* SListFind(Slist *plist,ElemType key)
{
	ListNode *s = plist->head;
	while (s!=NULL)
	if (key == s->data)
		return s;
	s = s->next;
		
}
#endif