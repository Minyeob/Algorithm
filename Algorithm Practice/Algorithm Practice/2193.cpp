#include <cstdio>

long long count[91];

void pibo(int n)
{
	count[1] = 1;
	count[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		count[i] = count[i - 1] + count[i - 2];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	pibo(n);

	printf("%lld", count[n]);
}