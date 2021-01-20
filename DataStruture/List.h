#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST_H_
#define _LIST_H_
#include "Sysutil.h"
typedef struct ListNode
{
	int data; //������
	//�����ŵ�����һ���ṹ��ĵ�ַ��
	struct ListNode *next; //ָ����һ���ڵ�Ľṹ��ָ��
}ListNode;
typedef ListNode* List; //��ָ���ض���Ϊ��㣬��ô�ɶ��Ծͻ���ߡ�
void ListInit(List *head)
{
	//*head = NULL;
}
void ListCreate_Tail(List * head)
{
	//�����mylistʵ�����Ѿ�����һ���ṹ��ָ���ˣ�����ָ�����ṹ��������Ԫ�صĵ�ַ��
	//����ͨ��mylist->data�����ҵ��ṹ���ڲ���Ԫ�أ�
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
		//ͷ������֮��*headָ��s;
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