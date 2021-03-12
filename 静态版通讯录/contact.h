#ifndef _CONTACT_H_
#define _CONTACT_H_
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 20
#define MAX_TELE 12
#define MAX 1000
#include "common.h"
typedef struct Peo_Info
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peo_Info;
//����ͨѶ¼�ṹ��
typedef struct ConTact
{
	Peo_Info data[MAX];//ÿһ�������Ԫ������Ϊ�ṹ�����͡�
	int sz;//��ǰͨѶ¼�е�Ԫ�ظ���
}ConTact;
//�����ϵ�˵���Ϣ��
void ConTactInit(ConTact *pc);
void AddPeoInfo(ConTact *pc);
void DelPeoInfo(ConTact *pc,char *name);
int FinPeoInfoByPos(ConTact *pc, char *name);
void FindContact(ConTact* pc);
void ChangePeoInfo(ConTact *pc);
void ShowPeoInfo(ConTact *pc);
void ClearContact(ConTact* pc);
#endif