/**
 * 欧几里得算法求公约数
 * 别名：辗转相除法
*/
#include <stdio.h>
int gcd(int a,int b){
	int temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main(int argc, char *argv[])
{
	int a, b;
	printf("please input the number a and b:\n");
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	printf("The gcd of a(%d) and b(%d) is %d.\n",a,b,gcd(a,b));
	return 0;
}