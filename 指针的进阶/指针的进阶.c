#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
////int main()
////{
////	/*int arr1[] = { 1, 2, 3, 4, 5, 6 };*/
////	//判断指针的类型：去掉指针变量的名字，这里的名字是p;即它的类型是int(*)[10];
////	//指针数组：本质上是数组；每一个数组里面存放的地址；
////	//指针数组里面arr[0]即是一个地址（即为指针），对其解引用可以得到arr[0]地址存放的元素，即a；
////	/*int a = 2;
////	int b = 3;
////	int d = 2;
////	int* arr[3] = { &a, &b, &d };
////	int i = 0;
////	for (i = 0; i < 3; i++)
////	{
////		printf("%d\n", *(arr[i]));
////	}*/
////	//真实的景不可能这么用；
////	//利用指针数组来遍历arr1,arr2，arr3里面数组的元素；
////	int arr1[] = { 1, 2, 3, 4 }; 
////	int arr2[] = { 2, 3, 4, 5 };
////	int arr3[] = { 4, 5, 6, 7 };
////	int* arr[] = { arr1, arr2, arr3};
////	int i = 0, j = 0;
////	for (i = 0; i < 3; i++)
////	{
////		for (j = 0; j < 4; j++)
////		{
////			printf("%d ", *(arr[i] + j));
////		}
////		printf("\n");
////	}
////	return 0;
////}
////数组指针,指向数组的指针；
////整型指针：存放整形变量的地址；
////字符指针：存放字符变量的地址；
//void print_shuzu(int (*p)[4], int hang, int lie)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < hang; i++)
//	{
//		for (j = 0; j < lie; j++)
//		{
//			printf("%d ", *((*p + i) + j));
//				//p+i；代表第i行数组的地址；
//				// (*p+i)相当于arr[i];解引用代表第i行数组名，
//				//数组名又代表数组首元素的地址，相当于arr[i];
//				//例如arr[0]：代表第一行元素的数组名；
//				//arr[0]+j:即依次遍历首元素的地址；再解引用得到每一行数组的元素；
//		}
//		printf("\n");
//	}
//}
//print_shuzu2(int *p, int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	//数组
//	/*int arr[] = { 1, 2, 3, 4, 5 };*/
//	//int *p = arr;//arr代表的就是首元素的地址，因此可以使用指针来接收；
//	////p+1,代表整型指针向后偏移4个字节，存放第二个元素的地址，然后再对其解引用即可。
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	printf("%d\n", *(p + i));
//	//}
//
//	//p是代表十六进制的，因为一般地址都是32位的，用16进制来表示的；
//	//printf("%p\n", &arr);
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr + 1);
//	//printf("%p\n", arr + 1);
//	//printf("%p\n", &arr[0]);
//	//p首先和方括号结合是指针，因为[]优先级高于*的优先级，所以要加()，存放的是数组的地址；
//	/*int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(arr + i));
//	}*/
//	//*(arr+i)==arr[i]==*(p+i);
	//写成第二种形式，电脑也会翻译成第三种或者第一种来解析。
	//这种写法也可以，因为本质上来说数组名就是首元素的地址；也可以令int *p=arr;
	//char* arr2[5];//是一个字符指针数组；
	////如何定义一个指针来指向指针数组呢？
	////*p代表是指针
	////pa是指针的名字，*告诉我们pa是指针，[5]代表pa指向的数组是五个元素；
	////char*代表的是pa指向的数组的元素类型：每个元素的类型的是char*；
	//char* (*pa)[5] = &arr2;
	//int *p1,*p2;
	//*仅仅代表p1和p2是指针;
	//int(*p)[10] = &arr;
	////如何判断类型：去掉变量名字；例如数组指针的类型就是int(*)[10];
	////而指针数组的类型为：int*[10];
	//printf("%d\n", sizeof(*p));//解引用代表的是整个数组
	//printf("%p\n", *p);
	//*p代表表达式的一部分的时候(作为表达式的时候），代表数组名，即首元素的地址；
	/*for (i = 0; i < 5; i++)
	{
		printf("%d\n", (*(*p + i)));
	}*/
	//(*p)[i]=arr[i];
	//这里的*p就相当于是数组名arr，等价于数组首元素的地址；
	//二维数组的使用：
	// 二维数组是按照行来存储的，先打印第一行，再打印第二行，再打印第三行。
	//利用数组指针来打印二维数组
	/*int arr2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };*/
	/*print_shuzu(arr2, 3, 4);*/
	//数组名代表首元素的地址，这里的首元素指的是第一行的地址；
	//第一行其实是一个一维数组，用来接收数组的地址可以使用数组指针来接收。
	/*print_shuzu2(&arr2[0][0], 12);*/
	/*int a = 10;*/
	/*int(*parr3[10])[5];*/ // *parr3[10]，parr3先和[10]结合，说明是一个数组，去掉数组名
	//和方括号，剩下int(*)[5],即是数组指针类型；即是一个存放数组指针的数组，数组里面
	//存放的是数组的地址。
//	int arr1[] = { 1, 2, 3, 4 };
//	int(*parr3[10])[1] = { &arr1};
//	int(*parr2)[10];//parr2是一个指针，该指针指向的是一个数组，数组是有10个元素，每一个元素的类型是int；
//	int* p[10];//指针数组，数组里面存放的元素是int*类型（指针类型）
//	int a[10];//整型数组，每个数组的元素是int类型；
//	//一维数组传参：形参的话可以是一维数组。
//	//二维数组传参：
//	return 0;
//}
void test(int arr[3][4]){}
void test2(int arr[][4]){}
//错误写法：因为二维数组的数组名代表第一行的地址，第一行的地址需要由数组指针来接收。
/*void test3(int *arr){}*/
/*void test4(int**arr){}*///二级指针来存放一级指针的地址；

void test5(int(*arr)[4]){}
///* 列不能省略;行可以省略;
//void test2(int arr[3][]){}*/
//int main()
//{
//	int arr[3][4] = { 0 };
//	test(arr);
//	test3(arr);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
	/*int a = 3, b = 4;
	Add(a, b);*/
	//pf是指向函数的指针变量,存放函数的指针；
	//pf是函数指针变量；
	//int 是函数的返回类型；
	//int(*pf)(int ,int ) = &Add;
	////*pf即是对函数进行解引用；
	//int ret = (*pf)(2, 3);
	//(*(void(*)())0)();
	//void(*signal((int, void(*)(int))(int);
	/*int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a + 0));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a + 1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0] + 1));*/
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6;
	//printf("%d\n", sizeof(arr + 0));//4;不管是什么类型的地址，都是4/8；
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//'b'，1
//	return 0;
//}
//二维数组的使用：
//int main()
//{
//	 int arr[10] = { 0 };
//	 int(*p)[10] = &arr;//数组指针；
//	 //代表p是一个指针，指向的是整个数组arr，该arr数组有10个元素,每个元素类型是int型
//	 printf("%d\n",sizeof(*p));
//	 //*p对p进行解引用，代表整个数组元素。**p，存放10个数组元素的地址，是一个指针；
//	 printf("%d\n", sizeof(**p));
//	return 0;
//}
//int main()
//{
//	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//	char**cp[] = { c + 3, c + 2, c + 1, c };
//	char***cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *--*++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	int arr[] = { 1, 2, 3, 4 };
//	return 0;
//}
//旋转字符串
//char* xuanzhuan_char(char *p, int x)
//{
//	char *ret = p;
//	int count = x;
//	while (count--&&*p)
//	{
//		*p = *(p+1);
//		p++;
//	}
//	*p = *(p + x);
//	return ret;
//}
//int main()
//{
//	char arr[] = "abcde";
//	xuanzhuan_char(arr, 4);
//	printf("%s\d", arr);
//	return 0;
//}
//旋转字符串
#include <string.h>
#include <assert.h>
//void left_move(char *arr, int k)
//{
//	//char tmp = *arr;//把arr的第一个元素的值存放在tmp里面；
//	//不能写在外面，如果这样的话，tmp的值一直都是首元素，不会随着循环而发生改变。
//	assert(arr != NULL);
//	int i = 0;
//	int j = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;
//		//向左旋转1个字符
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//			//将第j+1个字符向前移动一位到第j个字符;
//		}
//		*(arr + len - 1) = tmp;
//	}
//}
//判断条件：左下标小于右下标时，*left和*right相兑换，left为最左侧的元素，right为最右侧的元素；
//当right=left停止交换;
void reverse(char *left, char *right)
{
	assert(left != NULL&&right != NULL);
	//char tmp = *left;
	//特别喜欢这样子，不对的呀！
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move2(char *arr,int x)
{
	
	//将abcdef:以c分割；逆序ab,得到ba;
	//逆序cdef,得到fedc;
	//最终整体字符串再逆序，得到cdefab;
	reverse(arr, arr + x - 1);//逆序前k个;
	//字符串的长度需要求出来;得到结尾的字符串;
	int len = strlen(arr);
	reverse(arr + x, arr + len - 1);
	reverse(arr,arr + len - 1);
}
//int main()
//{
//	char arr[] = "abcdef";
//	//left_move(arr, 2);
//	left_move2(arr, 2);
//	printf("%s\n", arr);
//}
//穷举法，比较麻烦！把所有的可能性都列出来。
//int is_left_move(char*arr1, char *arr2)
//{
//	//1.arr1旋转k次之后的结果和arr2进行比较，如果进行所有比较之后，发现arr1和arr2都不相等，那么就要返回零，否则返回一；
//	//调用之前的left_move函数;
//	int len = strlen(arr1);
//	int i = 0;
//	//最多旋转的次数为字符串的长度，所以为len。
//	for (i = 0; i < len; i++)
//	{
//		//这样写是不对的，因为每次i的取值由0到1到n，相当于在新的字符串上改掉arr1的值；
//		//应该改成i等于1，这样每次都是在之前的基础上旋转一次；
//		left_move2(arr1, 1);
//		int ret = strcmp(arr1, arr2);
//		//注意strcmp函数,当两者完全相等是，ret返回值为0；依次比较，当arr1中第i个字符大于第arr2中第i个字符返回值为1;否则为-1；
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	//注意一般情况下不要使用char*arr="abcdef",如果要更改字符的值，因为指针指向的为
//	//常量字符串。
//	char arr1[] = "abcdef";
//	char arr2[] = "cdgfab";
//	//自己给自己追加，不能用strcat函数,程序会崩溃。
//	strcat(arr1, arr1);
//	int ret=is_left_move(arr1,arr2);
//	printf("%d\n", ret);
//	return 0;
//	unsigned long x = 5;
//}
//打印整形数组，使用指针
void print_arr(int*p,int x)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		printf("%d\n", *(p + i));
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(int);
	print_arr(arr,sz);
	return 0;
}
