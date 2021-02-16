#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "knn-.h"
int main()
{
	tempdata("iris.txt");//������ʱ����->��������
	loaddata();//���ش��Һ�����ݲ��ָ�
	int i, j;
	int k; //kֵ
	int sum = 0;//����ͳ�ƾ��������k����ǩ��ԭ���Ա�ǩ���ϵ�����
	printf("\n\nCheck data:\n\n");
	for (k = 1; k <= KN; k++){//kֵ��1--KN  KN�Ǻ궨��  �뿴Ԥ����ط�
		for (i = 0; i < NUM1; i++) {
			for (j = 0; j < NUM2; j++) {
				distance[j].data = computedistance(i, j);//�Ѽ���õľ������δ���distance�ṹ��������
				distance[j].trainlabel = train[j].label; //���Ͼ�������ͬʱҲ��ѵ������ǩһ�����distance�ṹ��������
			}
			qsort(distance, NUM2, sizeof(distance[0]), cmp); //��qsort������С�����������������ÿ��ѵ�����ݵľ���
			countlabel(&sum, k, i); //ͳ�ƾ�����Լ���ǩ����ı�ǩ����Ƶ��
		}
		printf("K = %d     P = %.1lf%%\n", k, 100.0*(sum) / NUM1); //��ӡÿ��Kֵ��Ӧ�ĸ���
		sum = 0;//ÿ��ͳ����󶼸�ֵ0  ������һ����������ͳ��
	}
	return 0;
}
