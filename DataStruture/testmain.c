//#define _CRT_SECURE_NO_WARNINGS 
//#include "Sysutil.h"
//#include "Seqlist.h"
//int main()
//{
//	ELEMTYPE item,key;
//	int pos;//���ҵ�λ�ã�
//	Seqlist mylist;
//	//�ṹ��ͨ������ַ����������������ֱ�ӵĴ�ֵ�����ṹ���һ�ݿ�����
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
//		printf("��ѡ��\n");
//		scanf("%d", &select);
//		switch (select)
//		{
//			case 1:
//				printf("������Ҫ����������\n");
//				while (scanf("%d", &item), item != -1)
//				{
//					SeqlistPushBack(&mylist, item);
//				}
//				SeqlistPushBack(&mylist, item);
//				break;
//			case 2:
//				printf("������Ҫǰ���������\n");
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
//				//Ҫ��ӡ��������
//				printf("��ĳ���Ϊ%d\n",Seqlistlength(&mylist));
//				break;
//			case 7:
//				printf("�������Ϊ%d\n", SeqlistCapcity(&mylist));
//				break;
//
//				//����Ԫ��ɾ��
//				//����û���뵽����Ҫ�Ȳ���Ԫ�أ����Ե��ò��ҵ�Ԫ��;
//				//��Ҫ�ж���û�и�Ԫ�أ����û�еĻ���̸����Ҫɾ����
//			case 10:
//
//				break;
//				//����λ��ɾ��
//			case 11:
//				break;
//			case 12:
//				printf("������Ҫ���ҵ�Ԫ��\n");
//				scanf("%d", &key);
//				//���Լ��տ�ʼд�����ֺã�ʹ��pos�����պ����ķ���ֵ;
//				pos = SeqlistFind(&mylist, key);
//				if (pos == -1)
//					printf("Ҫ���ҵ�Ԫ�ز�����\n");
//				else
//					printf("Ҫ���ҵ�Ԫ��%dλ�ڵ�%d��λ��\n", key,pos);
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