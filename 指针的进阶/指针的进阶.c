#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
////int main()
////{
////	/*int arr1[] = { 1, 2, 3, 4, 5, 6 };*/
////	//�ж�ָ������ͣ�ȥ��ָ����������֣������������p;������������int(*)[10];
////	//ָ�����飺�����������飻ÿһ�����������ŵĵ�ַ��
////	//ָ����������arr[0]����һ����ַ����Ϊָ�룩����������ÿ��Եõ�arr[0]��ַ��ŵ�Ԫ�أ���a��
////	/*int a = 2;
////	int b = 3;
////	int d = 2;
////	int* arr[3] = { &a, &b, &d };
////	int i = 0;
////	for (i = 0; i < 3; i++)
////	{
////		printf("%d\n", *(arr[i]));
////	}*/
////	//��ʵ�ľ���������ô�ã�
////	//����ָ������������arr1,arr2��arr3���������Ԫ�أ�
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
////����ָ��,ָ�������ָ�룻
////����ָ�룺������α����ĵ�ַ��
////�ַ�ָ�룺����ַ������ĵ�ַ��
//void print_shuzu(int (*p)[4], int hang, int lie)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < hang; i++)
//	{
//		for (j = 0; j < lie; j++)
//		{
//			printf("%d ", *((*p + i) + j));
//				//p+i�������i������ĵ�ַ��
//				// (*p+i)�൱��arr[i];�����ô����i����������
//				//�������ִ���������Ԫ�صĵ�ַ���൱��arr[i];
//				//����arr[0]�������һ��Ԫ�ص���������
//				//arr[0]+j:�����α�����Ԫ�صĵ�ַ���ٽ����õõ�ÿһ�������Ԫ�أ�
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
//	//����
//	/*int arr[] = { 1, 2, 3, 4, 5 };*/
//	//int *p = arr;//arr����ľ�����Ԫ�صĵ�ַ����˿���ʹ��ָ�������գ�
//	////p+1,��������ָ�����ƫ��4���ֽڣ���ŵڶ���Ԫ�صĵ�ַ��Ȼ���ٶ�������ü��ɡ�
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	printf("%d\n", *(p + i));
//	//}
//
//	//p�Ǵ���ʮ�����Ƶģ���Ϊһ���ַ����32λ�ģ���16��������ʾ�ģ�
//	//printf("%p\n", &arr);
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr + 1);
//	//printf("%p\n", arr + 1);
//	//printf("%p\n", &arr[0]);
//	//p���Ⱥͷ����Ž����ָ�룬��Ϊ[]���ȼ�����*�����ȼ�������Ҫ��()����ŵ�������ĵ�ַ��
//	/*int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(arr + i));
//	}*/
//	//*(arr+i)==arr[i]==*(p+i);
	//д�ɵڶ�����ʽ������Ҳ�ᷭ��ɵ����ֻ��ߵ�һ����������
	//����д��Ҳ���ԣ���Ϊ��������˵������������Ԫ�صĵ�ַ��Ҳ������int *p=arr;
	//char* arr2[5];//��һ���ַ�ָ�����飻
	////��ζ���һ��ָ����ָ��ָ�������أ�
	////*p������ָ��
	////pa��ָ������֣�*��������pa��ָ�룬[5]����paָ������������Ԫ�أ�
	////char*�������paָ��������Ԫ�����ͣ�ÿ��Ԫ�ص����͵���char*��
	//char* (*pa)[5] = &arr2;
	//int *p1,*p2;
	//*��������p1��p2��ָ��;
	//int(*p)[10] = &arr;
	////����ж����ͣ�ȥ���������֣���������ָ������;���int(*)[10];
	////��ָ�����������Ϊ��int*[10];
	//printf("%d\n", sizeof(*p));//�����ô��������������
	//printf("%p\n", *p);
	//*p������ʽ��һ���ֵ�ʱ��(��Ϊ���ʽ��ʱ�򣩣�����������������Ԫ�صĵ�ַ��
	/*for (i = 0; i < 5; i++)
	{
		printf("%d\n", (*(*p + i)));
	}*/
	//(*p)[i]=arr[i];
	//�����*p���൱����������arr���ȼ���������Ԫ�صĵ�ַ��
	//��ά�����ʹ�ã�
	// ��ά�����ǰ��������洢�ģ��ȴ�ӡ��һ�У��ٴ�ӡ�ڶ��У��ٴ�ӡ�����С�
	//��������ָ������ӡ��ά����
	/*int arr2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };*/
	/*print_shuzu(arr2, 3, 4);*/
	//������������Ԫ�صĵ�ַ���������Ԫ��ָ���ǵ�һ�еĵ�ַ��
	//��һ����ʵ��һ��һά���飬������������ĵ�ַ����ʹ������ָ�������ա�
	/*print_shuzu2(&arr2[0][0], 12);*/
	/*int a = 10;*/
	/*int(*parr3[10])[5];*/ // *parr3[10]��parr3�Ⱥ�[10]��ϣ�˵����һ�����飬ȥ��������
	//�ͷ����ţ�ʣ��int(*)[5],��������ָ�����ͣ�����һ���������ָ������飬��������
	//��ŵ�������ĵ�ַ��
//	int arr1[] = { 1, 2, 3, 4 };
//	int(*parr3[10])[1] = { &arr1};
//	int(*parr2)[10];//parr2��һ��ָ�룬��ָ��ָ�����һ�����飬��������10��Ԫ�أ�ÿһ��Ԫ�ص�������int��
//	int* p[10];//ָ�����飬���������ŵ�Ԫ����int*���ͣ�ָ�����ͣ�
//	int a[10];//�������飬ÿ�������Ԫ����int���ͣ�
//	//һά���鴫�Σ��βεĻ�������һά���顣
//	//��ά���鴫�Σ�
//	return 0;
//}
void test(int arr[3][4]){}
void test2(int arr[][4]){}
//����д������Ϊ��ά����������������һ�еĵ�ַ����һ�еĵ�ַ��Ҫ������ָ�������ա�
/*void test3(int *arr){}*/
/*void test4(int**arr){}*///����ָ�������һ��ָ��ĵ�ַ��

void test5(int(*arr)[4]){}
///* �в���ʡ��;�п���ʡ��;
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
	//pf��ָ������ָ�����,��ź�����ָ�룻
	//pf�Ǻ���ָ�������
	//int �Ǻ����ķ������ͣ�
	//int(*pf)(int ,int ) = &Add;
	////*pf���ǶԺ������н����ã�
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
	//printf("%d\n", sizeof(arr + 0));//4;������ʲô���͵ĵ�ַ������4/8��
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//'b'��1
//	return 0;
//}
//��ά�����ʹ�ã�
//int main()
//{
//	 int arr[10] = { 0 };
//	 int(*p)[10] = &arr;//����ָ�룻
//	 //����p��һ��ָ�룬ָ�������������arr����arr������10��Ԫ��,ÿ��Ԫ��������int��
//	 printf("%d\n",sizeof(*p));
//	 //*p��p���н����ã�������������Ԫ�ء�**p�����10������Ԫ�صĵ�ַ����һ��ָ�룻
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
//��ת�ַ���
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
//��ת�ַ���
#include <string.h>
#include <assert.h>
//void left_move(char *arr, int k)
//{
//	//char tmp = *arr;//��arr�ĵ�һ��Ԫ�ص�ֵ�����tmp���棻
//	//����д�����棬��������Ļ���tmp��ֵһֱ������Ԫ�أ���������ѭ���������ı䡣
//	assert(arr != NULL);
//	int i = 0;
//	int j = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;
//		//������ת1���ַ�
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//			//����j+1���ַ���ǰ�ƶ�һλ����j���ַ�;
//		}
//		*(arr + len - 1) = tmp;
//	}
//}
//�ж����������±�С�����±�ʱ��*left��*right��һ���leftΪ������Ԫ�أ�rightΪ���Ҳ��Ԫ�أ�
//��right=leftֹͣ����;
void reverse(char *left, char *right)
{
	assert(left != NULL&&right != NULL);
	//char tmp = *left;
	//�ر�ϲ�������ӣ����Ե�ѽ��
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
	
	//��abcdef:��c�ָ����ab,�õ�ba;
	//����cdef,�õ�fedc;
	//���������ַ��������򣬵õ�cdefab;
	reverse(arr, arr + x - 1);//����ǰk��;
	//�ַ����ĳ�����Ҫ�����;�õ���β���ַ���;
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
//��ٷ����Ƚ��鷳�������еĿ����Զ��г�����
//int is_left_move(char*arr1, char *arr2)
//{
//	//1.arr1��תk��֮��Ľ����arr2���бȽϣ�����������бȽ�֮�󣬷���arr1��arr2������ȣ���ô��Ҫ�����㣬���򷵻�һ��
//	//����֮ǰ��left_move����;
//	int len = strlen(arr1);
//	int i = 0;
//	//�����ת�Ĵ���Ϊ�ַ����ĳ��ȣ�����Ϊlen��
//	for (i = 0; i < len; i++)
//	{
//		//����д�ǲ��Եģ���Ϊÿ��i��ȡֵ��0��1��n���൱�����µ��ַ����ϸĵ�arr1��ֵ��
//		//Ӧ�øĳ�i����1������ÿ�ζ�����֮ǰ�Ļ�������תһ�Σ�
//		left_move2(arr1, 1);
//		int ret = strcmp(arr1, arr2);
//		//ע��strcmp����,��������ȫ����ǣ�ret����ֵΪ0�����αȽϣ���arr1�е�i���ַ����ڵ�arr2�е�i���ַ�����ֵΪ1;����Ϊ-1��
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	//ע��һ������²�Ҫʹ��char*arr="abcdef",���Ҫ�����ַ���ֵ����Ϊָ��ָ���Ϊ
//	//�����ַ�����
//	char arr1[] = "abcdef";
//	char arr2[] = "cdgfab";
//	//�Լ����Լ�׷�ӣ�������strcat����,����������
//	strcat(arr1, arr1);
//	int ret=is_left_move(arr1,arr2);
//	printf("%d\n", ret);
//	return 0;
//	unsigned long x = 5;
//}
//��ӡ�������飬ʹ��ָ��
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
