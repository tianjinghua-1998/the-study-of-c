#define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"
void menu()
{
	printf("--------�˵�-------       \n");
	printf("1.�����ϵ����Ϣ          \n");
	printf("2.ɾ����ϵ����Ϣ          \n");
	printf("3.������ϵ����Ϣ          \n");
	printf("4.�޸�ָ����ϵ����Ϣ      \n");
	printf("5.��ʾ������ϵ����Ϣ      \n");
	printf("6.���������ϵ����Ϣ      \n");
	printf("7.����������������ϵ����Ϣ\n");
	printf("0.���������˳��������� \n");
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
		printf("��ѡ��->:\n");
		scanf("%d", &select);
		switch (select)
		{
		case ADD:
			AddPeoInfo(&con);
			break;
		case DEL:
			printf("������Ҫɾ������ϵ��:\n");
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
			printf("�����������������\n");
		}
	}while(select);
}
void main()
{
	test();
}