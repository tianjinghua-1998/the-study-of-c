
#define _CRT_SECURE_NO_WARNINGS 
#define NUM 150 //�����ݵ�����
#define NUM1 50 //�������ݵ�����
#define NUM2 100 //ѵ�����ݵ�����
#define N 4 //�������ݵ�������ά����
#define KN 15//K�����ȡֵ
typedef struct {
	double data;//����
	char trainlabel;//��������ѵ����ǩ

}Distance;
typedef struct {
	double data[N];//ÿ�ֻ���4����������
	char label; //��ǩ���������ࣩ
	char name[20];//��Ż�������
}TestAndTrain;

TestAndTrain test[NUM1];//�������ݽṹ������
TestAndTrain train[NUM2];//ѵ�����ݽṹ������
TestAndTrain temp[NUM]; //��ʱ������ݽṹ������
Distance distance[NUM2];//��ž���ṹ������
void labelABC(char x[], char* p);
void makerand(TestAndTrain a[], int n);
void tempdata(char filename[]);
void loaddata();
double computedistance(int n1, int n2);
char max_count(int a, int b, int c);
void countlabel(int* sum, int k, int n);
int cmp(const void* a, const void* b);
