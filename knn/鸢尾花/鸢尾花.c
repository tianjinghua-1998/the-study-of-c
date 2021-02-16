#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "knn-.h"
int main()
{
	tempdata("iris.txt");//加载临时数据->打乱数据
	loaddata();//加载打乱后的数据并分割
	int i, j;
	int k; //k值
	int sum = 0;//用于统计距离最近的k个标签与原测试标签符合的数量
	printf("\n\nCheck data:\n\n");
	for (k = 1; k <= KN; k++){//k值：1--KN  KN是宏定义  请看预处理地方
		for (i = 0; i < NUM1; i++) {
			for (j = 0; j < NUM2; j++) {
				distance[j].data = computedistance(i, j);//把计算好的距离依次存入distance结构体数组中
				distance[j].trainlabel = train[j].label; //以上距离存入的同时也把训练集标签一起存入distance结构体数组中
			}
			qsort(distance, NUM2, sizeof(distance[0]), cmp); //用qsort函数从小到大排序测试数据与每组训练数据的距离
			countlabel(&sum, k, i); //统计距离测试集标签最近的标签出现频数
		}
		printf("K = %d     P = %.1lf%%\n", k, 100.0*(sum) / NUM1); //打印每个K值对应的概率
		sum = 0;//每次统计完后都赋值0  便于下一个测试数据统计
	}
	return 0;
}
