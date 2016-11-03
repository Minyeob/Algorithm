#include <stdio.h>
#include <math.h>

int temp[10000000];
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int r = a%b;
	a = b;
	b = r;
	gcd(a, b);
}

int main()
{
	long long int a, b;
	scanf("%ld %ld", &a, &b);
	long long int c = gcd(a, b);
	for (int i = 0; i < c; i++)
		printf("%d",1);

}