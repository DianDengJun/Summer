/**
 * 康托展开
 * 即求某个排列的全排列序号
*/
#include <stdio.h>
const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800}; //	0-10的阶乘
//cantor展开，n表示是n位的全排列，a[]表示全排列的数(用数组表示)
int cantor(int a[], int n)
{
	int ans = 0, sum = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[i])
				sum++;
		}
		ans += sum * fact[n - i]; //	累积
		sum = 0;				  //	计数器归零
	}
	return (ans + 1);
}
//计算位数
int length(int n)
{
	int len = 0;
	do
	{
		len++;
		n /= 10;
	} while (n);
	return len;
}
int main(int argc, char *argv[])
{
	int number;
	printf("Input the number:");
	scanf("%d", &number);
	int a[length(number)], temp = number;
	//存入数组
	for (int i = length(number); i >= 0; i--)
	{
		a[i] = temp % 10;
		temp /= 10;
	}
	printf("The cantor number of %d is %d.", number, cantor(a, length(number)));
	return 0;
}