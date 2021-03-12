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
		printf("ͨѶ¼��������������û�\n");
	}
	else
	{
		printf("����������:\n");
		scanf("%s", pc->data[pc->sz].name);
		printf("�������Ա�:\n");
		scanf("%s", pc->data[pc->sz].sex);
		printf("����������:\n");
		scanf("%d", &pc->data[pc->sz].age);
		printf("������绰:\n");
		scanf("%s", pc->data[pc->sz].tele);
		printf("������סַ:\n");
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
	printf("������Ҫ���ҵ���ϵ������\n");
	scanf("%s", name);
	int pos = FinPeoInfoByPos(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
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
		printf("ͨѶ¼�ѿգ�����ɾ��");
		return;
	}
	else
	{
		//1.������������,���������±ꣻ
		//int i;
		int pos = FinPeoInfoByPos(pc, name);
		//2.ɾ������ϵ�˵���Ϣ
		if (pos == -1)
			return;
		else
		{
			//��ɾ����Ԫ�غ���������ǰ�ƶ�1����
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
	//1.������û�и���ϵ�ˣ��еĻ������ܸı���ϵ�˵���Ϣ��
	//���ҵĻ�����1��1�����бȽϣ�Ҳ����ʹ�ö��ֲ��ҷ���
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	int mod = 0;
	printf("������Ҫ�޸ĵ���ϵ������:\n");
	scanf("%s", name);
	pos = FinPeoInfoByPos(pc, name);
	if (pos == -1)
	{
		printf("���޴���,�������\n");
		return;
	}

	//2.������ϵ�˵���Ϣ
	printf("ѡ��1�����Ա�ѡ��2�������䣬ѡ��3����סַ\n");
	scanf("%d", &mod);
	switch (mod)
	{
	case 1:
		printf("�������µ��Ա�\n");
		scanf("%s", pc->data[pos].sex);
		break;
	case 2:
		printf("�������µ�����\n");
		scanf("%d", &pc->data[pos].age);
		break;
	case 3:
		printf("�������µ�סַ\n");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("�����������������");
		break;
	}
	printf("�޸ĳɹ�\n");


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
