#define _CRT_SECURE_NO_WARNINGS 
#include "list2.h"
#include "BinTree.h"
#include "queue.h"
#include<vld.h>
#include "heap.h"
//int main()
//{
//	Slist MyList;
//	//����һ��������Ϊ����֮����ͨ����ַ���ӵģ�����ָ�룬��ôд
//	//�ɶ��Ի���ǿ��һ����֪����һ�����������ϻ���ָ�룻
//	//Ҫ�ı�Mylist��ָ������Ҫ��MyList���������һ����ַ���ĵ�ַ��ȥ��
//	//��ַ�ĵ�ַ�����Ƕ���ָ��
//	SlistInit(&MyList);
//	//SlistCreate_Tail(&MyList);
////	SlistCreate_Head(&MyList);
//	SlistShow(&MyList);
//	//****************************************//
//	return 0;
//}
//int main()
//{
//	ELEMTYPE item,key;
//	SListNode *p;
//	Slist mylist;
//	//mylist ��һ���ṹ��
//	SlistInit(&mylist);
//	int select = 1;
//	while (select)
//	{
//		printf("******************************  \n");
//		printf("**[1]push_back  [2]push_front** \n");
//		printf("**[3]show_list  [0]quit_system**\n");
//		printf("**[4]pop_back   [5]pop_front**  \n");
//		printf("**[6]length     [����7] capacity    \n");
//		printf("**[8]insert_val [����9] insert_pos  \n");
//		printf("**[10]delete_val[����11] delete_pos \n");
//		printf("**[12]find      [13] sort       \n");
//		printf("**[14]reverse   [15] remove_all \n");
//		printf("**[16]clear     [17] destroy    \n");
//		printf("******************************\n");
//		printf("��ѡ��>:\n");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ����������\n");
//			while (scanf("%d", &item), item != -1)
//			{
//				SlistPushBack(&mylist, item);
//			}
//			break;
//		case 2:
//			printf("������Ҫǰ���������\n");
//			while (scanf("%d", &item), item != -1)
//			{
//				SlistPushFront(&mylist, item);
//			}
//			break;
//		case 3:
//			SlistShow(&mylist);
//			break;
//		case 4:
//			SlistPopBack(&mylist);
//			break;
//		case 5:
//			SlistPopFront(&mylist);
//			break;
//		case 6:
//			//Ҫ��ӡ��������
//			printf("��ĳ���Ϊ%d\n", SlistLength(&mylist));
//			break;
//		case 8:
//			printf("������Ҫ�����ֵ\n");
//			scanf("%d", &key);
//			SlistInsert_Val(&mylist, key);
//			break;
//		case 10:
//			printf("������Ҫɾ����ֵ\n");
//			scanf("%d", &key);
//			SlistDel_Val(&mylist, key);
//			break;
//			//����λ��ɾ��
//		case 11:
//			//����λ�ò���
//			break;
//		case 12:
//			//����
//			printf("������Ҫ���ҵ�ֵ\n");
//			scanf("%d", &key);
//			 p= SlistFind(&mylist, key);
//			if (p == NULL)
//				printf("Ҫ���ҵ�%d������\n", key);
//			else
//				printf("Ҫ���ҵ�%d����\n", key);
//			p = NULL;
//			break;
//		case 13:
//			 SlistSort(&mylist);
//			break;
//		case 14:
//			SlistReverse(&mylist);
//			break;
//		case 15:
//			printf("������Ҫɾ����ֵ->:\n");
//			scanf("%d", &key);
//			SlistRemoveAll(&mylist, key);
//			break;
//		case 16:
//			SlistClear(&mylist);
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}
/////ջ�����////
//int main()
//{
//	SeqQueue t;
//	/*SeqQueueInit(&t,0);
//	SeqQueueEn(&t, 2);
//	SeqQueueEn(&t, 4);
//	SeqQueueEn(&t, 6);
//	SeqQueueEn(&t, 8);
//	SeqQueueEn(&t, 10);
//	SeqQueueEn(&t, 12);
//	SeqQueueShow(&t);
//	printf("-----------\n");
//	SeqQueueDe(&t);
//	SeqQueueEn(&t, 12);
//	SeqQueueShow(&t);
//	printf("-----------\n");*/
//	/*size_t back= SeqQueueBack(&t);
//	printf("��βԪ��Ϊ%d\n", back);*/
//	/*size_t sz = SeqQueueSz(&t);
//	printf("������Ԫ�صĸ���Ϊ%d\n", sz);*/
//	SeqQueueInit(&t, 0);
//	CirSeqQueueEn(&t, 2);
//	CirSeqQueueEn(&t, 4);
//	CirSeqQueueEn(&t, 6);
//	CirSeqQueueEn(&t, 8);
//	CirSeqQueueEn(&t, 10);
//	CirSeqQueueDe(&t);
//	//CirSeqQueueEn(&t, 12);
//	CirSeqQueueShow(&t);
//	printf("-----------\n");
//	CirSeqQueueDe(&t);
//	CirSeqQueueEn(&t, 12);
//	CirSeqQueueShow(&t);
//	printf("-----------\n");
//	return 0;
//}

//int main()
//{
//	Queue t1;
//	QueueInit(&t1);
//	QueuePush(&t1, 1);
//	QueuePush(&t1, 2);
//	QueuePush(&t1, 3);
//	QueuePush(&t1, 4);
//	QueuePush(&t1, 5);
//	QueueShow(&t1);
//	printf("----------------------------\n");
//	QueuePop(&t1);
//	QueuePop(&t1);
//	QueuePop(&t1);
//	QueueShow(&t1);
//	QueueElemType t0 = QueueFront(&t1);
//	printf("��ͷԪ��Ϊ%d\n", t0);
//	QueueElemType t2 = QueueBack(&t1);
//	printf("��βԪ��Ϊ%d\n", t2);
//	int size = QueueSize(&t1);
//	printf("Ԫ�صĸ���%d\n", size);
//	return 0;
//}
//#include "stack.h"
//int main()
//{
//	SeqStack t;
//	SeqStackInit(&t,0);
//	SeqStackPush(&t, 11);
//	SeqStackPush(&t, 12);
//	SeqStackPush(&t, 7);
//	SeqStackPush(&t, 8);
//	SeqStackShow(&t);
//	ELEMTYPE top = SeqStackTop(&t);
//	printf("ջ��Ԫ��Ϊ%d\n", top);
//	return 0;
//}
//#include "stack2.h"
//int main()
//{
//	Stack* p = NULL;
//	p = StackInit();
//	StackPush(p, 1);
//	StackPush(p, 2);
//	StackPush(p, 3);
//	StackPush(p, 4);
//	StackPush(p, 5);
//	StackPush(p, 6);
//	StackShow(p);
//	StackPop(p);
//	StackPop(p);
//	StackPop(p);
//	int top = Stacktop(p);
//	printf("%d\n", top);
//	printf("------------------\n");
//	StackShow(p);
//	StackDestroy(p);
//	printf("------------------\n");
//	StackShow(p);
//	return 0;
//}

////������////
//void main()
//{
//	char *str = "ABD##E##C##";
//	BTNode* bt = NULL;
//	int index = 0;
//	//BinaryTreeCreate(&bt);
//	//bt = BinaryTreeCreate_2();
//	bt = BinaryTreeCreate_3(str,&index);
//	printf("ǰ�����:->\n");
//	PreOrder(bt);
//	//PreOrder_Nor(bt);
//	printf("\n");
//	printf("�������:->\n");
//	InOrder(bt);
//	printf("\n");
//	printf("�������:->\n");
//	PostOrder(bt);
//	printf("\n");
//	printf("��α���:->\n");
//	BinaryTreeLevelOrder(bt);
//	printf("\n");
//	BTNode* p=BinaryTreeFind(bt, 'B');
//	printf("\n");
//	int c = BinaryTreeSize(bt);
//	printf("���ĸ���Ϊ%d\n", c);
//	int d = BinaryTreeLeafSize(bt);
//	printf("Ҷ�ӽ��ĸ���Ϊ%d\n", d);
//	int k=BinaryTreeLevelKSize(bt, 4);
//	printf("��4����ĸ���Ϊ%d\n", k);
//	//BinaryTreeDestory(&bt);
//	printf("\n");
//}
//                  �ѽṹ                   //
int main()
{
	ELEMTYPE arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//�����ʼ����ʱ�򣬿��Բ�ָ��������ĳ��ȡ���ΪԪ�صĸ����Ѿ�ȷ���ˡ�
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	Heap heap;
	//HeapInit(&heap,sz);
	HeapCreate(&heap, arr, sz);
	HeapShow(&heap);
	HeapPush(&heap, 10);
	HeapShow(&heap);
	/*for (i = 0; i < sz; i++)
	{
		HeapPush(&heap, arr[i]);
	}*/
	//HeapShow(&heap);
	HeapDestory(&heap);
	return 0;
}