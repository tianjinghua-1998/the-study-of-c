#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST_H_
#define _LIST_H_
#define ELEMTYPE int
#include "syst.h"
//1.����1���ڵ�
typedef struct SListNode
{
	ELEMTYPE data;
	//�ṹ��������ã���ָ�����ָ��ͬһ���͵Ĳ�ͬ�Ľṹ�壻
	//��Ϊָ������͵�ָ��
	//�տ�ʼд���ˣ�ûдstruct
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
	//����һ���ڵ��ָ����Ϊ��ָ�룬����ָ���κα�������Ϊ0��ַ�����洢�κα���
	//���ܶԿ�ָ�������
}
//void SlistCreate_Tail(SListNode *head)
//{
//	//����ͷ�ڵ�Ĵ���
//	*head= (SListNode *)malloc(sizeof(SListNode));
//	(*head)->data = 1;
//	(*head)->next = NULL;
//	SListNode* p = *head;
//	SListNode *s = NULL;
//	for (int i = 2; i <5 ; i++)
//	{
//		SListNode *s = (SListNode *)malloc(sizeof(SListNode));
//		//���϶���
//		assert(s != NULL);
//		s->data = i;
//		s->next = NULL;
//		p->next = s;
//		p= s;//pָ��s����˼��
//	}
//}
void SlistCreate_Head(Slist *head)
{
	//2-1
	//1.����ͷ�ڵ�1��
	//2.�����ڵ�2(s),�ڵ�2ָ��ڵ�1������headָ��2��
	*head = (SListNode *)malloc(sizeof(SListNode));
	(*head)->data = 1;
	(*head)->next = NULL;
	//���ﲢ����Ҫ����һ����ʱ��ָ��p�ˣ���Ϊ��ͷ�����룬5��4��3��2��1
	//ÿһ��*head����ָ�����µĽ�㣬����*headָ�����2����ô*head->next�����ŵ�
	//��1�ĵ�ַ���������ƣ������ҵ����ɵ�ÿһ����㡣
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

	}*///����д��
	SListNode* p = head;
	while (p != NULL)
	{
		printf("%d-> ",p->data);
		p = p->next;
	}
	printf("over\n");
}

#endif