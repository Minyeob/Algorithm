#include <stdio.h>
#include <math.h>

long long int gcd(long long int a,long long int b)
{
	if (b == 0)
		return a;
	long long int r = a%b;
	a = b;
	b = r;
	return gcd(a, b);
}

int main()
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	long long int c = gcd(a, b);
	for (int i = 0; i < c; i++)
		printf("1");
}