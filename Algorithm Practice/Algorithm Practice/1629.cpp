#include <stdio.h>
#include <iostream>
using namespace std;

long long int mul(long long int a,long long int b,int c)
{
	if (b <= 1)
		return a;
	if (b%2 ==0)
	{
		long long int z = mul(a, b / 2,c);
		return (z*z)%c;
	}
	else
	{
		long long int z = mul(a, b / 2,c);
		return (((z*z)%c)*a)%c;
	}
}

int main()
{
	long long int a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long int d=mul(a, b,c);
	printf("%lld", d%c);
}