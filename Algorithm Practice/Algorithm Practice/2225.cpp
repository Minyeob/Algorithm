#include <cstdio>

long long num[201][201];

int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);

	
	for (int i = 0; i <= n; i++)
	{
		num[i][1] = 1;
		for (int j = 2; j <= k; j++)
		{
			for (int t = 0; t <= i; t++)
			{
				num[i][j] = num[i][j] + num[t][j - 1];
			}
			num[i][j] = num[i][j] % 1000000000;
		}
	}

	printf("%lld", num[n][k]);
}