/**
 * 高次方求模
*/
#include <stdio.h>
long mod(long a, long b, long m)
{
	long ret;
	if (!b)
		ret = 1; //	边界处理，b==0
	else if (b == 1)
		ret = a % m; //	边界处理，b==1
	else
	{
		ret = mod(a, b / 2, m);	//	递归
		ret = ret * ret % m;	//	先算偶数的（奇数第一部分和此一样）
		if (b & 1)	//	当指数为奇数,多乘第二部分
			ret = (ret * a % m)%m;
	}
	return ret;
}
int main(int argc, char *argv[])
{
	long a, b, m;
	printf("Calculate a^b mod m:\n");
	printf("\tInput a:");
	scanf("%ld",&a);
	printf("\tInput b:");
	scanf("%ld",&b);
	printf("\tInput m:");
	scanf("%ld",&m);
	printf("Result:%ld\n",mod(a,b,m));
	return 0;
}