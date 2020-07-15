/**
 * 判断三点顺序
 */
#include <stdio.h>
typedef struct _point
{
	double x;
	double y;
} Point;
int main(int argc, char *argv[])
{
	Point A, B, C;
	printf("Please input 3 points:\n");
	printf("\tx of Point A:");
	scanf("%lf", &A.x);
	printf("\ty of Point A:");
	scanf("%lf", &A.y);
	printf("\tA(%.2f,%.2f)\n",A.x,A.y);
	printf("\n\tx of Point B:");
	scanf("%lf", &B.x);
	printf("\ty of Point B:");
	scanf("%lf", &B.y);
	printf("\tB(%.2f,%.2f)\n",B.x,B.y);
	printf("\n\tx of Point C:");
	scanf("%lf", &C.x);
	printf("\ty of Point C:");
	scanf("%lf", &C.y);
	printf("\tC(%.2f,%.2f)\n",C.x,C.y);
	double ans = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	if (!ans)
		printf("Three points are collinear!\n");
	else if (ans > 0)
		printf("Anti-Clockwise!\n");
	else
		printf("clockwise!\n");
	return 0;
}