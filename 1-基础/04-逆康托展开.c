/**
 * 逆康托展开
 * 即求某个序号对应的全排列 
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800}; //	0-10的阶乘
bool used[11];																 //	判断是否用过
//cantor展开逆运算，rank表示第rank位的全排列数，length表示全排列位数长度
int de_cantor(int rank, int length)
{
	int ans = 0, sum = 0;	 //	ans存储答案，sum暂时计数
	int quotient, remainder; //	quotient商，remainder余数
	for (int i = length - 1; i >= 1; i--)
	{
		quotient = rank / fact[i];
		remainder = rank % fact[i];
		for (int j = 1; j <= length; j++)
		{
			if (!used[j])
			{
				sum++;
			}
			if (sum == quotient + 1) //	找到该位
			{
				ans += j * pow(10, i);
				sum = 0; //	清零
				rank = remainder;
				used[j] = true; //标记为用过
				break;
			}
		}
	}
	for (int i = 1; i <= length; i++)
	{
		if (!used[i])
		{
			ans += i;
			break;
		}
	} //	最后一位
	return ans;
}
int main()
{
	int rank, length;	//	rank表示第rank位的全排列数，length表示全排列位数长度
	for (int i = 0; i < 11; i++)
		used[i] = false;	//	全部初始化为未用过
	printf("Please input the length of the number:");
	scanf("%d",&length);
	printf("==================================================\nTip: This Group is [1");
	for (int i = 1; i < length; i++)
		printf(", %d", i + 1);
	printf("]\n==================================================\n");

	printf("Please input the order:");
	scanf("%d",&rank);
	rank--;	//	第rank位前的个数
	printf("The NO.%d number is %d\n", rank + 1, de_cantor(rank, length));
}