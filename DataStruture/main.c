#define _CRT_SECURE_NO_WARNINGS 
#include "Sysutil.h"
#include "List.h"
int main()
{
	List mylist; //��һ���ṹ�����͵�ָ�룻
	ListInit(&mylist);
	//ListCreate_Head(&mylist); 
	ListCreate_Tail(&mylist);
	ListShow(mylist);
	return 0;
}