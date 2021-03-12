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
//声明通讯录结构体
typedef struct ConTact
{
	Peo_Info data[MAX];//每一个数组的元素类型为结构体类型。
	int sz;//当前通讯录中的元素个数
}ConTact;
//添加联系人的信息；
void ConTactInit(ConTact *pc);
void AddPeoInfo(ConTact *pc);
void DelPeoInfo(ConTact *pc,char *name);
int FinPeoInfoByPos(ConTact *pc, char *name);
void FindContact(ConTact* pc);
void ChangePeoInfo(ConTact *pc);
void ShowPeoInfo(ConTact *pc);
void ClearContact(ConTact* pc);
#endif