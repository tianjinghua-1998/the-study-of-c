#define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"
void menu()
{
	printf("--------菜单-------       \n");
	printf("1.添加联系人信息          \n");
	printf("2.删除联系人信息          \n");
	printf("3.查找联系人信息          \n");
	printf("4.修改指定联系人信息      \n");
	printf("5.显示所有联系人信息      \n");
	printf("6.清空所有联系人信息      \n");
	printf("7.以名字排序所有联系人信息\n");
	printf("0.————退出———— \n");
}
enum OPTION
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MOD,
	SHOW,
	CLEAR,
	SORT
};
void test()
{
	ConTact con;
	ConTactInit(&con);
	menu();
	int select = 0;
	char name[10];
	do
	{
		printf("请选择->:\n");
		scanf("%d", &select);
		switch (select)
		{
		case ADD:
			AddPeoInfo(&con);
			break;
		case DEL:
			printf("请输入要删除的联系人:\n");
			scanf("%s", name);
			DelPeoInfo(&con, name);
			break;
		case FIND:
			FindContact(&con);
			break;
		case MOD:
			ChangePeoInfo(&con);
			break;
		case SHOW:
			ShowPeoInfo(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	}while(select);
}
void main()
{
	test();
}