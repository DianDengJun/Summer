/**
 * 海伦公式
 * 即已知三边求三角形面积
*/
#include <stdio.h>
#include <math.h>
double area_tri(double a, double b, double c)
{
	double area = 0;
	double p = (a + b + c) / 2.0;
	if (a + b <= c || a + c <= b || b + c <= a)
		area = 0;
	else
		area = sqrt(p * (p - a) * (p - b) * (p - c));
	return area;
}
int main(int argc, char *argv[])
{
	double a, b, c;
	printf("Please input the length of 3 sides:\n");
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	if (area_tri(a, b, c))
		printf("Its perimeter is %.2f.\n", area_tri(a, b, c));
	else
		printf("These sides do not correspond to a valid triangle!\n");
	return 0;
}