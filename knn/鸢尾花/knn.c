#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "knn-.h"
void labelABC(char x[], char* p) { //把不同种类花的名字分别转化成 A B C 标签

	if (strcmp(x, "\"Iris-setosa\"") == 0)
		*p = 'A';
	else
	if (strcmp(x, "\"Iris-versicolor\"") == 0)
		*p = 'B';
	else
	if (strcmp(x, "\"Iris-virginica\"") == 0)
		*p = 'C';
}
void makerand(TestAndTrain a[], int n){ //函数功能：打乱存放标签后的结构体数组
	TestAndTrain t;
	int i, n1, n2;
	srand((unsigned int)time(NULL));//获取随机数的种子,百度查下用法
	for (i = 0; i<n; i++){
		n1 = (rand() % n);//产生n以内的随机数  n是数组元素个数
		n2 = (rand() % n);
		if (n1 != n2){ //若两随机数不相等 则下标为这两随机数的数组进行交换
			t = a[n1];
			a[n1] = a[n2];
			a[n2] = t;
		}
	}
}
void tempdata(char filename[]){//临时存放数据  用于先存放150个数据后再打乱
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	int i, j;
	for (i = 0; i<NUM; i++){
		for (j = 0; j<N; j++){
			fscanf(fp, "%lf\t", &temp[i].data[j]);
		}
		fscanf(fp, "%s", temp[i].name);
		labelABC(temp[i].name, &temp[i].label);
	}
	//makerand(temp, NUM);//打乱所有数据
	fclose(fp);
	fp = NULL;
}
void loaddata() { //加载数据      分割：测试NUM1组   训练NUM2组
	int i, j, n = 0, m = 0;
	for (i = 0; i < NUM; i++) 
	{
		if (i < NUM1) { //存入测试集
			for (j = 0; j < N; j++) 
			{
				test[n].data[j] = temp[i].data[j]; //存入花的四个特征数据
			}
			test[n].label = temp[i].label;//存入花的标签
			n++;
		}
		else { //剩下的行数存入训练集
			for (j = 0; j < N; j++) 
			{
				train[m].data[j] = temp[i].data[j];//存入花的四个特征数据
			}
			train[m].label = temp[i].label;//存入花的标签
			m++;
		}
	}
	printf("test:\n"); //把分割后的数据都打印出来  便于观察是否已经打乱
	for (i = 0; i<NUM1; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%lf ", test[i].data[j]);
		}
		printf("%c\n", test[i].label);
	}
	printf("\n\ntrain:\n");
	for (i = 0; i<NUM2; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%lf ", train[i].data[j]);
		}
		printf("%c\n", train[i].label);
	}
}

double computedistance(int n1, int n2) { //计算距离
	double sum = 0.0;
	int i;
	for (i = 0; i < N; i++) {
		sum += pow(test[n1].data[i] - train[n2].data[i], 2.0);
	}
	return sqrt(sum);//返回距离
}

char max_count(int a, int b, int c)
{
	if (a>b && a>c) return 'A';
	else
	if (b>c && b>a) return 'B';
	else
	if (c>a && c>b) return 'C';
	return '0';
}//找出频数最高的 测试数据就属于出现次数最高的

void countlabel(int* sum, int k, int n) { //统计距离最邻近的k个标签出现的频数
	int i;
	int sumA = 0, sumB = 0, sumC = 0; //sumA sumB sumC 分别统计距离最邻近的三类标签出现的频数
	for (i = 0; i < k; i++) {
		switch (distance[i].trainlabel) { //用Distance结构体指针p来取K个距离最近的标签来进行判断
		case 'A':sumA++; break;
		case 'B':sumB++; break;
		case 'C':sumC++; break;
		}
	}
	if (max_count(sumA, sumB, sumC) == test[n].label) { //检测距离最近的k个标签与原测试标签是否符合  并统计
		(*sum)++; //统计符合的数量
	}
}

int cmp(const void* a, const void* b) { //快速排序qsort函数的cmp函数(判断函数)
	Distance A = *(Distance*)a;
	Distance B = *(Distance*)b;
	return A.data > B.data ? 1 : -1;
}