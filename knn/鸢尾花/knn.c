#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "knn-.h"
void labelABC(char x[], char* p) { //�Ѳ�ͬ���໨�����ֱַ�ת���� A B C ��ǩ

	if (strcmp(x, "\"Iris-setosa\"") == 0)
		*p = 'A';
	else
	if (strcmp(x, "\"Iris-versicolor\"") == 0)
		*p = 'B';
	else
	if (strcmp(x, "\"Iris-virginica\"") == 0)
		*p = 'C';
}
void makerand(TestAndTrain a[], int n){ //�������ܣ����Ҵ�ű�ǩ��Ľṹ������
	TestAndTrain t;
	int i, n1, n2;
	srand((unsigned int)time(NULL));//��ȡ�����������,�ٶȲ����÷�
	for (i = 0; i<n; i++){
		n1 = (rand() % n);//����n���ڵ������  n������Ԫ�ظ���
		n2 = (rand() % n);
		if (n1 != n2){ //�������������� ���±�Ϊ�����������������н���
			t = a[n1];
			a[n1] = a[n2];
			a[n2] = t;
		}
	}
}
void tempdata(char filename[]){//��ʱ�������  �����ȴ��150�����ݺ��ٴ���
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
	//makerand(temp, NUM);//������������
	fclose(fp);
	fp = NULL;
}
void loaddata() { //��������      �ָ����NUM1��   ѵ��NUM2��
	int i, j, n = 0, m = 0;
	for (i = 0; i < NUM; i++) 
	{
		if (i < NUM1) { //������Լ�
			for (j = 0; j < N; j++) 
			{
				test[n].data[j] = temp[i].data[j]; //���뻨���ĸ���������
			}
			test[n].label = temp[i].label;//���뻨�ı�ǩ
			n++;
		}
		else { //ʣ�µ���������ѵ����
			for (j = 0; j < N; j++) 
			{
				train[m].data[j] = temp[i].data[j];//���뻨���ĸ���������
			}
			train[m].label = temp[i].label;//���뻨�ı�ǩ
			m++;
		}
	}
	printf("test:\n"); //�ѷָ������ݶ���ӡ����  ���ڹ۲��Ƿ��Ѿ�����
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

double computedistance(int n1, int n2) { //�������
	double sum = 0.0;
	int i;
	for (i = 0; i < N; i++) {
		sum += pow(test[n1].data[i] - train[n2].data[i], 2.0);
	}
	return sqrt(sum);//���ؾ���
}

char max_count(int a, int b, int c)
{
	if (a>b && a>c) return 'A';
	else
	if (b>c && b>a) return 'B';
	else
	if (c>a && c>b) return 'C';
	return '0';
}//�ҳ�Ƶ����ߵ� �������ݾ����ڳ��ִ�����ߵ�

void countlabel(int* sum, int k, int n) { //ͳ�ƾ������ڽ���k����ǩ���ֵ�Ƶ��
	int i;
	int sumA = 0, sumB = 0, sumC = 0; //sumA sumB sumC �ֱ�ͳ�ƾ������ڽ��������ǩ���ֵ�Ƶ��
	for (i = 0; i < k; i++) {
		switch (distance[i].trainlabel) { //��Distance�ṹ��ָ��p��ȡK����������ı�ǩ�������ж�
		case 'A':sumA++; break;
		case 'B':sumB++; break;
		case 'C':sumC++; break;
		}
	}
	if (max_count(sumA, sumB, sumC) == test[n].label) { //�����������k����ǩ��ԭ���Ա�ǩ�Ƿ����  ��ͳ��
		(*sum)++; //ͳ�Ʒ��ϵ�����
	}
}

int cmp(const void* a, const void* b) { //��������qsort������cmp����(�жϺ���)
	Distance A = *(Distance*)a;
	Distance B = *(Distance*)b;
	return A.data > B.data ? 1 : -1;
}