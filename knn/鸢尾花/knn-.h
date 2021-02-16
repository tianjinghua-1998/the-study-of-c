
#define _CRT_SECURE_NO_WARNINGS 
#define NUM 150 //总数据的数量
#define NUM1 50 //测试数据的数量
#define NUM2 100 //训练数据的数量
#define N 4 //特征数据的数量（维数）
#define KN 15//K的最大取值
typedef struct {
	double data;//距离
	char trainlabel;//用于链接训练标签

}Distance;
typedef struct {
	double data[N];//每种花的4个特征数据
	char label; //标签（花的种类）
	char name[20];//存放花的名字
}TestAndTrain;

TestAndTrain test[NUM1];//测试数据结构体数组
TestAndTrain train[NUM2];//训练数据结构体数组
TestAndTrain temp[NUM]; //临时存放数据结构体数组
Distance distance[NUM2];//存放距离结构体数组
void labelABC(char x[], char* p);
void makerand(TestAndTrain a[], int n);
void tempdata(char filename[]);
void loaddata();
double computedistance(int n1, int n2);
char max_count(int a, int b, int c);
void countlabel(int* sum, int k, int n);
int cmp(const void* a, const void* b);
