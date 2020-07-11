/*
** 筛法求素数
*/
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
	const int MAX = 1e6;
	bool isPrime[MAX];
	int number;
	// 开辟prime[MAX]，初始其所有元素为1，prime[x]为true表示x是素数
	for (int i = 0; i < MAX; i++)
		isPrime[i] = true;
	for (int x = 2; x < MAX; x++)
	{
		if (isPrime[x])
			for (int i = 2; i * x < MAX; i++)
				isPrime[i * x] = false;
	}
	printf("please input the number you want to know whether it's a prime:\n");
	scanf("%d", &number);
	if (isPrime[number])
		printf("It's a prime!\n");
	else
		printf("It isn't a prime!\n");
	return 0;
}