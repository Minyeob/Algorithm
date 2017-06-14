#include <cstdio>

int input[101][101];
int sum[101][101];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%1d", &input[i][j]);
	}

	long long entire = 0;
	long long max = 0;
	long long result = 0;
	long long first = 0;
	long long second = 0;
	long long third = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + input[i][j];
			entire += input[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			first = sum[i][j];
			second = sum[n][j]-first;
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	for (int i = 1; i <= m - 2; i++)
	{
		for (int j = i + 1; j <= m - 1; j++)
		{
			first = sum[n][i];
			second = sum[n][j] - first;
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			first = sum[n][i];
			second = sum[j][m] - sum[j][i];
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			first = sum[i][m];
			second = sum[n][j] - sum[i][j];
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			first = sum[i][j];
			second = sum[i][m] - first;
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			first = sum[i][m];
			second = sum[j][m] - first;
			third = entire - first - second;
			result = first*second*third;
			if (result > max)
				max = result;
		}
	}

	printf("%lld", max);
}