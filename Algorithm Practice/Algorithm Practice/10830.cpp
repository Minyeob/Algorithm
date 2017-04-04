#include <cstdio>

long long arr[1000001][5][5];
long long final[5][5];
long long temp[5][5];

int main()
{
	int n;
	long long b;
	scanf("%d %lld", &n, &b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%lld", &arr[1][i][j]);
	}

	for (int t = 2; t < 1000001; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					arr[t][i][j] = (arr[t][i][j] + arr[t - 1][i][k] * arr[1][k][j])%1000;
			}
		}
	}

	int count = b / 1000000;		
	int remain = b % 1000000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				temp[i][j] = 1;
		}
	}

	//printf("count is %d \n", count);
	//printf("remain is %d \n", remain);
	for (int t = 0; t < count; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				final[i][j] = 0;
				for (int k = 0; k < n; k++)
					final[i][j] = (final[i][j] + temp[i][k] * arr[1000000][k][j]) % 1000;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				temp[i][j] = final[i][j];
		}
	}
	if (remain != 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				final[i][j] = 0;
				for (int k = 0; k < n; k++)
					final[i][j] = (final[i][j] + temp[i][k] * arr[remain][k][j]) % 1000;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lld ", final[i][j]);
		}
		printf("\n");
	}
}