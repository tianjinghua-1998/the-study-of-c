#define _CRT_SECURE_NO_WARNINGS 
#include "Sysutil.h"
#include "List.h"
int main()
{
	List mylist; //是一个结构体类型的指针；
	ListInit(&mylist);
	//ListCreate_Head(&mylist); 
	ListCreate_Tail(&mylist);
	ListShow(mylist);
	return 0;
}