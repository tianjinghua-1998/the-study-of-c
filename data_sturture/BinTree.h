#define _CRT_SECURE_NO_WARNINGS 
#ifndef _BINTREE_H_
#include "syst.h"
#include "stack2.h"
#include "queue.h"
#define BTDataType char
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
//返回值类型为BTNode*，指向结构体的指针
// 函数返回值这里*靠近函数一侧，突出返回值是指针类型，而形参里面*靠近变量一侧，
//突出定义的t为指向指针的指针。指向指针的指针变量。
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreeLevelOrder(BTNode* root);
//int BinaryTreeComplete(BTNode* root);
void BinaryTreeCreate(BTNode **t)
{
	BTDataType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BTNode*)malloc(sizeof(BTNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinaryTreeCreate(&((*t)->_left));
		BinaryTreeCreate(&((*t)->_right));
	}
}
BTNode* BinaryTreeCreate_2()
{
	char item;
	scanf("%c", &item);
	//将NULL返回即可
	if (item == '#')
		return NULL;
	else
	{
		BTNode *t = (BTNode *)malloc(sizeof(BTNode));
		t->data = item;
		t->_left = BinaryTreeCreate_2();
		t->_right = BinaryTreeCreate_2();
		return t;
	}
}
//const放在前面：修饰的是*str，即指针指向的内容是不能被改变的。
//自己写代码的时候：==写成了=，相当于给str指向的内容赋值了，所以报错。
BTNode* BinaryTreeCreate_3( const char* str,int *i)
{
	
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BTNode *t = (BTNode *)malloc(sizeof(BTNode));
		t->data = str[*i];
		(*i)++;
		t->_left = BinaryTreeCreate_3(str,i);
		//不能少这一句，否则遍历完左树之后，i没有变，还是前一次的。
		(*i)++;
		t->_right = BinaryTreeCreate_3(str,i);
		return t;
	}
}
//BTNode* BinaryTreeCreate_3( const char* str)
//{
//	
//	if (*str == '#' || *str == '\0')
//		return NULL;
//	else
//	{
//		BTNode *t = (BTNode *)malloc(sizeof(BTNode));
//		t->data = *str;
//		t->_left = BinaryTreeCreate_3(str+1);
//		//不能少这一句，否则遍历完左树之后，i没有变，还是前一次的。
//		t->_right = BinaryTreeCreate_3(str+1);
//		return t;
//	}
//}

void PreOrder(BTNode* t);
void PreOrder(BTNode* t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder(t->_left);
		PreOrder(t->_right);
	}
}
void InOrder(BTNode* t)
{
	if (t != NULL)
	{
		InOrder(t->_left);
		printf("%c ", t->data);
		InOrder(t->_right);
	}
}
void PostOrder(BTNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->_left);
		PostOrder(t->_right);
		printf("%c ", t->data);
	}
}
void LevelOrder(BTNode* t)
{

}
//二叉树的非递归前序遍历，利用到栈结构//
void PreOrder_Nor(BTNode *t);
void PreOrder_Nor(BTNode *t)
{
	if (t != NULL)
	{
		Stack t1;
		t1=*StackInit();
		StackPush(&t1, t);
		//加上！,代表栈不为空为真。
		while (!StackIsEmpty(&t1))
		{
			BTNode *p = Stacktop(&t1);
			StackPop(&t1);
			printf("%c ", p->data);
			if (p->_right != NULL)
				StackPush(&t1, p->_right);
			if (p->_left != NULL)
				StackPush(&t1, p->_left);
		}

	}
}
void BinaryTreeDestory(BTNode** root)
{
	if (*root != NULL)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right)+1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* p;
	if (root == NULL || root->data == x)
	{
		return root;
	}
	p = BinaryTreeFind(root->_left, x);
	if (p!=NULL)
		return p;
	else 
		return BinaryTreeFind(root->_right, x);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	BTNode* p;
	if (root != NULL)
	{
		Queue q;
		QueueInit(&q);
		QueuePush(&q, root);
		while (!QueueEmpty(&q))
		{
			p=QueueFront(&q);
			QueuePop(&q);
			printf("%c ", p->data);
			if (p->_left != NULL)
			{
				QueuePush(&q, p->_left);
			}
			if (p->_right != NULL)
			{
				QueuePush(&q, p->_right);
			}
		}
	}
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (k < 0 || root == NULL)
		return 0;
	if (k == 1)
		return 1;
	else
		return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}
#endif