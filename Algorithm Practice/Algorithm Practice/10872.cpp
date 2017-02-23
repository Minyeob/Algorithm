#include <cstdio>

long long num[13];

void fac(int n)
{
	num[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		num[i] = num[i - 1] * i;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	fac(n);
	num[0] = 1;

	printf("%lld", num[n]);
}