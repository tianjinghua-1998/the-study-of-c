//#define _CRT_SECURE_NO_WARNINGS 
//#include "Sysutil.h"
//#include "Seqlist.h"
//int main()
//{
//	ELEMTYPE item,key;
//	int pos;//查找的位置；
//	Seqlist mylist;
//	//结构体通过传地址来传参数；而不是直接的传值，即结构体的一份拷贝。
//	SeqlistInit(&mylist);
//	int select = 1;
//	while (select)
//	{
//		printf("******************************  \n");
//		printf("**[1]push_back  [2]push_front** \n");
//		printf("**[3]show_list  [0]quit_system**\n");
//		printf("**[4]pop_back   [5]pop_front**  \n"  ); 
//		printf("**[6]length     [7] capacity    \n"  );
//		printf("**[8]insert_val [9] insert_pos  \n");
//		printf("**[10]delete_val[11] delete_pos \n");
//		printf("**[12]find      [13] sort       \n");
//		printf("**[14]reverse   [15] remove_all \n");
//		printf("**[16]clear     [17] destroy    \n");
//		printf("******************************\n");
//		printf("请选择\n");
//		scanf("%d", &select);
//		switch (select)
//		{
//			case 1:
//				printf("请输入要后插入的数据\n");
//				while (scanf("%d", &item), item != -1)
//				{
//					SeqlistPushBack(&mylist, item);
//				}
//				SeqlistPushBack(&mylist, item);
//				break;
//			case 2:
//				printf("请输入要前插入的数据\n");
//				while (scanf("%d", &item), item != -1)
//				{
//					SeqlistPushFront(&mylist, item);
//				}
//				break;
//			case 3:
//				SeqlistShowList(&mylist);
//				break;
//			case 4:
//				SeqlistPopBack(&mylist);
//				break;
//			case 5:
//				SeqlistPopFront(&mylist);
//				break;
//			case 6:
//				//要打印出来看到
//				printf("表的长度为%d\n",Seqlistlength(&mylist));
//				break;
//			case 7:
//				printf("表的容量为%d\n", SeqlistCapcity(&mylist));
//				break;
//
//				//按照元素删除
//				//这里没有想到，需要先查找元素，可以调用查找的元素;
//				//需要判断有没有该元素，如果没有的话就谈不上要删除；
//			case 10:
//
//				break;
//				//按照位置删除
//			case 11:
//				break;
//			case 12:
//				printf("请输入要查找的元素\n");
//				scanf("%d", &key);
//				//比自己刚开始写的那种好，使用pos来接收函数的返回值;
//				pos = SeqlistFind(&mylist, key);
//				if (pos == -1)
//					printf("要查找的元素不存在\n");
//				else
//					printf("要查找的元素%d位于第%d个位置\n", key,pos);
//				break;
//			case 13:
//				SeqlistSort(&mylist);
//				break;
//			case 16:
//				SeqlistClear(&mylist);
//				break;
//		}
//
//	}
//	return 0;
//}
////int main()
////{
////	char ch1, ch2;
////	scanf("%c", &ch1);
////	scanf("%c", &ch2);
////	printf("%d  %d\n", ch1, ch2);
////	return 0;
////}