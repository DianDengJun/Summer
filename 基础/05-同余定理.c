#include <stdio.h>
#include <stdlib.h>
#define Max 100
int num[Max]; //原始序列
int val[Max]; //每两个数之间的差
//最大公约数
int gcd(int a, int b)
{
	int temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//用同余定理处理求n的数的余数，num[]原始序列，n元素个数
int my_remainder(int num[], int n)
{
	int i = 0, j = 0, k = 0;
	//处理得到val[]，即每两个数之间的差值
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			val[k++] = abs(num[i] - num[j]);
		}
	}
	//求val[0]和val[1]求最大公约数t，然后再对t和val[i](i>=2)求最大公约数，
	//一直到最后一个，得出val数组中的最大公约数即为所求
	int t = gcd(val[0], val[1]);
	for (i = 2; i < n; i++)
	{
		t = gcd(val[i], t);
	}
	return t;
}

int main()
{
	int n;
	printf("Pleas input the number of the elements:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Please input the NO.%d element:", i + 1);
		scanf("%d", &num[i]);
	}
	printf("%d is the largest remainder of this %d elements.\n", my_remainder(num, n), n);
	return 0;
}