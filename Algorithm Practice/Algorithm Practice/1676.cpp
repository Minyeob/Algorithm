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

	long long temp = num[n];
	//printf("%lld",temp);

	int count = 0;
	while (temp > 0)
	{
		int div = temp % 10;
		if (div == 0)
		{
			count++;
			temp = temp / 10;
		}
		else
			break;
	}
	printf("%d", count);
}