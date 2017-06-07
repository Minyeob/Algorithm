#include <cstdio>

long long fibo[2000000];

int main()
{
	long long n;
	scanf("%lld", &n);
	n = n % 1500000;
	printf("%lld", n);

	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%1000000;

	printf("%lld",fibo[n]);
}