#include <cstdio>
#define max 1000000000;

long long final[101][10];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)
	{
		final[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		final[i][0] = final[i - 1][1]%max;
		for (int j = 1; j < 9; j++)
		{
			final[i][j] = (final[i - 1][j - 1] + final[i - 1][j + 1])%max;
		}
		final[i][9] = final[i - 1][8]%max;
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + final[n][i]) % max;
	}

	printf("%lld", sum);
}