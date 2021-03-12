#define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"
void ClearContact(ConTact* pc)
{
	ConTactInit(pc);
}
void ConTactInit(ConTact *pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void AddPeoInfo(ConTact *pc)
{
	assert(pc);
	if (pc->sz >= MAX)
	{
		printf("通讯录已满，不能添加用户\n");
	}
	else
	{
		printf("请输入姓名:\n");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入性别:\n");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入年龄:\n");
		scanf("%d", &pc->data[pc->sz].age);
		printf("请输入电话:\n");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入住址:\n");
		scanf("%s", pc->data[pc->sz].addr);
		pc->sz++;
	}
}
int FinPeoInfoByPos(ConTact *pc, char *name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;

}
void FindContact(ConTact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名\n");
	scanf("%s", name);
	int pos = FinPeoInfoByPos(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}
	printf("%-7s\t%-5s\t%-5s\t%-12s\t%-15d\n",
		pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr,
		pc->data[pos].age);
}
void DelPeoInfo(ConTact *pc, char *name)
{
	if (pc->sz == 0)
	{
		printf("通讯录已空，不能删除");
		return;
	}
	else
	{
		//1.按照姓名查找,查找它的下标；
		//int i;
		int pos = FinPeoInfoByPos(pc, name);
		//2.删除该联系人的信息
		if (pos == -1)
			return;
		else
		{
			//被删除的元素后面依次向前移动1个；
			for (int i = pos + 1; i < pc->sz; i++)
			{
				pc->data[i - 1] = pc->data[i];
			}
			pc->sz--;
		}
	}
}
void ChangePeoInfo(ConTact *pc)
{
	//1.查找有没有该联系人，有的话，才能改变联系人的信息；
	//查找的话可以1个1个进行比较，也可以使用二分查找法。
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	int mod = 0;
	printf("请输入要修改的联系人姓名:\n");
	scanf("%s", name);
	pos = FinPeoInfoByPos(pc, name);
	if (pos == -1)
	{
		printf("查无此人,输入错误\n");
		return;
	}

	//2.更改联系人的信息
	printf("选择1更改性别，选择2更改年龄，选择3更改住址\n");
	scanf("%d", &mod);
	switch (mod)
	{
	case 1:
		printf("请输入新的性别\n");
		scanf("%s", pc->data[pos].sex);
		break;
	case 2:
		printf("请输入新的年龄\n");
		scanf("%d", &pc->data[pos].age);
		break;
	case 3:
		printf("请输入新的住址\n");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("输入错误，请重新输入");
		break;
	}
	printf("修改成功\n");


}
void ShowPeoInfo(ConTact *pc)
{
	int i = 0;
	printf("%-7s\t%-5s\t%-5s\t%-12s\t%-15s\n",
		"name", "age", "sex", "tele", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-7s\t%-5d\t%-5s\t%-12s\t%-15s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}
