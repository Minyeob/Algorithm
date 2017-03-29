#include <cstdio>
#define pi 3.141592653589793238

int main()
{
	int r;
	scanf("%d", &r);
	double circle = r*r*pi;
	double square = r*r * 2;
	printf("%.6f\n", circle);
	printf("%.6f\n", square);
}