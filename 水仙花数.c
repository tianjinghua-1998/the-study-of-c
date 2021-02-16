#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
//int main()
//{
//	//判断一个数是否为自幂数。
//	//n位数，每个位上的数字的n次幂之和等于它本身，例如153,1^3+5^3+3^3=153-被称为水仙花数
//	//1.判断i是几位数-
//	//2.求出每个位的数字的n次幂之后是否为它本身。
//	int i = 0;
//	//找出所有的自幂数
//	for (i = 0; i < 10000; i++)
//	{
//		
//		int n = 1;//起始的数字为1位数，这里n=1比较合适；
//		/*while (i / 10)
//		{
//			n++;
//			i /= 10;
//		}*/
//		//更简化的版本;i这样做的时候：i会变成0，不要在循环里面改掉i，所以给一个
//		//临时变量来存储i；
//		int tmp = i;
//		//判断i是几位数。
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		int sum = 0;//这里的sum 一定要放在while循环外面，因为每次选择一个新的数字i
//		//时，sum都需要从0开始。
//		//sum用来保存每各位的数字的n次幂之和
//		//int tmp = i;不能多次初始化，但是可以重新令i等于tmp.
//		tmp = i;
//		while (tmp)
//		{
//			sum = sum + pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//判断一个数是否为水仙花数
//int Is_Nt(int i)
//{
//	int tmp = i;
//	int n = 1;
//	int ret = 0;
//	//判断为几位数;
//	while (tmp /= 10)
//	{
//		n++;
//	}
//	while (i)
//	{
//		ret = ret +(int) pow(i % 10, n);
//		i = i / 10;
//	}
//	return ret;
//}
//int main()
//{
//	int i = 0;
//	/*printf("请输入要判断的数是否为自幂数\n");
//	while (scanf("%d", &i) != EOF)
//	{
//		int ret = Is_Nt(i);
//		if (ret == i)
//		{
//			printf("%d 为自幂数\n", i);
//		}
//		else
//		{
//			printf("%d不为自幂数，请重新输入\n", i);
//		}
//	}*/
//	for (i = 0; i < 100000; i++)
//	{
//		int ret = Is_Nt(i);
//		if (ret == i)
//		{
//			printf("%d为自幂数\n", i);
//		}
//	}
//	return 0;
//}
//打印菱形
//     *//5
//    ***//4
//   *****//3
//  *******//2
// *********//1
//***********//0
// *********//1
//  *******//2
//   *****//3
//    ***//4
//	 *//5
int main()
{
	//只能打印奇数行，如果直接输入打印line行,如果输入偶数行的话，无法得到菱形。
	//所以可以先打印Line行，再打印line-1行。
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	int j = 0;
	//外层for循环，控制有几行；
	//内存for循环，要控制每次打印几个*号，和空格;
	for (i = 1; i <= line; i++)
	{
		//第1行：打印5个空格；
		//第二行打印4个空格；
		for (j = 1; j <= line - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= (2 * i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= line - 1; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <=2*(line-i)-1 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}