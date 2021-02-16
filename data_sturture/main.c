#define _CRT_SECURE_NO_WARNINGS 
#include "list2.h"
#include "BinTree.h"
#include "queue.h"
#include<vld.h>
#include "heap.h"
//int main()
//{
//	Slist MyList;
//	//创建一个链表，因为链表之间是通过地址连接的，就是指针，这么写
//	//可读性会增强，一看就知道是一个链表，本质上还是指针；
//	//要改变Mylist的指向，所以要传MyList（本身就是一个地址）的地址进去；
//	//地址的地址所以是二级指针
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
//	//mylist 是一个结构体
//	SlistInit(&mylist);
//	int select = 1;
//	while (select)
//	{
//		printf("******************************  \n");
//		printf("**[1]push_back  [2]push_front** \n");
//		printf("**[3]show_list  [0]quit_system**\n");
//		printf("**[4]pop_back   [5]pop_front**  \n");
//		printf("**[6]length     [不做7] capacity    \n");
//		printf("**[8]insert_val [不做9] insert_pos  \n");
//		printf("**[10]delete_val[不做11] delete_pos \n");
//		printf("**[12]find      [13] sort       \n");
//		printf("**[14]reverse   [15] remove_all \n");
//		printf("**[16]clear     [17] destroy    \n");
//		printf("******************************\n");
//		printf("请选择>:\n");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("请输入要后插入的数据\n");
//			while (scanf("%d", &item), item != -1)
//			{
//				SlistPushBack(&mylist, item);
//			}
//			break;
//		case 2:
//			printf("请输入要前插入的数据\n");
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
//			//要打印出来看到
//			printf("表的长度为%d\n", SlistLength(&mylist));
//			break;
//		case 8:
//			printf("请输入要插入的值\n");
//			scanf("%d", &key);
//			SlistInsert_Val(&mylist, key);
//			break;
//		case 10:
//			printf("请输入要删除的值\n");
//			scanf("%d", &key);
//			SlistDel_Val(&mylist, key);
//			break;
//			//按照位置删除
//		case 11:
//			//按照位置插入
//			break;
//		case 12:
//			//查找
//			printf("请输入要查找的值\n");
//			scanf("%d", &key);
//			 p= SlistFind(&mylist, key);
//			if (p == NULL)
//				printf("要查找的%d不存在\n", key);
//			else
//				printf("要查找的%d存在\n", key);
//			p = NULL;
//			break;
//		case 13:
//			 SlistSort(&mylist);
//			break;
//		case 14:
//			SlistReverse(&mylist);
//			break;
//		case 15:
//			printf("请输入要删除的值->:\n");
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
/////栈与队列////
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
//	printf("队尾元素为%d\n", back);*/
//	/*size_t sz = SeqQueueSz(&t);
//	printf("队列中元素的个数为%d\n", sz);*/
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
//	printf("队头元素为%d\n", t0);
//	QueueElemType t2 = QueueBack(&t1);
//	printf("队尾元素为%d\n", t2);
//	int size = QueueSize(&t1);
//	printf("元素的个数%d\n", size);
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
//	printf("栈顶元素为%d\n", top);
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

////二叉树////
//void main()
//{
//	char *str = "ABD##E##C##";
//	BTNode* bt = NULL;
//	int index = 0;
//	//BinaryTreeCreate(&bt);
//	//bt = BinaryTreeCreate_2();
//	bt = BinaryTreeCreate_3(str,&index);
//	printf("前序遍历:->\n");
//	PreOrder(bt);
//	//PreOrder_Nor(bt);
//	printf("\n");
//	printf("中序遍历:->\n");
//	InOrder(bt);
//	printf("\n");
//	printf("后序遍历:->\n");
//	PostOrder(bt);
//	printf("\n");
//	printf("层次遍历:->\n");
//	BinaryTreeLevelOrder(bt);
//	printf("\n");
//	BTNode* p=BinaryTreeFind(bt, 'B');
//	printf("\n");
//	int c = BinaryTreeSize(bt);
//	printf("结点的个数为%d\n", c);
//	int d = BinaryTreeLeafSize(bt);
//	printf("叶子结点的个数为%d\n", d);
//	int k=BinaryTreeLevelKSize(bt, 4);
//	printf("第4层结点的个数为%d\n", k);
//	//BinaryTreeDestory(&bt);
//	printf("\n");
//}
//                  堆结构                   //
int main()
{
	ELEMTYPE arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//数组初始化的时候，可以不指定的数组的长度。因为元素的个数已经确定了。
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