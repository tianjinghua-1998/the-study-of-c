#define _CRT_SECURE_NO_WARNINGS 
#ifndef _LIST3_H_
#define _LIST3_H_
#define ELEMTYPE int
#include "syst.h"
typedef struct DCListNode
{
	ELEMTYPE data;
	struct DCListNode* next;
	struct DCListNode* prev;
}DCListNode;
typedef struct DClist
{
	DCListNode* first;
	DCListNode* last;
	size_t size;
}DClist;
void DClistInit(DClist* plist);
void DClistPushBack(DClist* plist, ELEMTYPE x);
void DClistPushFront(DClist* plist, ELEMTYPE x);
void DClistShow(DClist* plist);
void DClistPopBack(DClist* plist);
void DClistPopFront(DClist* plist);
int DClistLength(DClist* plist);
void DClistInsert_Val(DClist* plist, ELEMTYPE key);
void DClistDel_Val(DClist* plist, ELEMTYPE key);
DCListNode* SlistFind(DClist* plist, ELEMTYPE key);
void DClistReverse(DClist* plist);
void DClistSort(DClist* plist);
void DClistClear(DClist* plist);
void DClistDestroy(DClist* plist);
void DClistRemoveAll(DClist* plist, ELEMTYPE key);
void DClistInit(DClist* plist);
#endif