#include <cstdio>
long long fibo[1001];
int main()
{
	int n;
	scanf("%d", &n);

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%1000000;

	printf("%lld", fibo[n]);
}