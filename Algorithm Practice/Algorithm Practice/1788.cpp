#include <cstdio>

long long plus[1000001];
long long minus[1000001];

long long abs(long long n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

int main()
{
	int n;
	scanf("%d", &n);

	plus[1] = 1;
	if (n >= 0)
	{
		for (int i = 2; i <= n; i++)
			plus[i] = (plus[i - 1] + plus[i - 2])% 1000000000;
		if (n > 0)
		{
			printf("1\n");
			printf("%lld", plus[n]);
		}
		else
		{
			printf("0\n");
			printf("0");
		}
	}

	else
	{
		minus[1] = 1;
		for (int i = 2; i <= abs(n); i++)
			minus[i] = (minus[i - 2] - minus[i - 1])% 1000000000;
		if (minus[abs(n)] > 0)
		{
			printf("1\n");
			printf("%lld", minus[abs(n)]);
		}
		else if (minus[abs(n)] == 0)
		{
			printf("0\n0");
		}
		else
		{
			printf("-1\n");
			printf("%lld", abs(minus[abs(n)]));
		}
	}

	
}