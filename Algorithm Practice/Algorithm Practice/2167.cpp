#include <cstdio>

int arr[301][301];
int result[301][301];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			result[i][j] = result[i - 1][j];
			for (int k = 1; k <= j; k++)
				result[i][j] += arr[i][k];
		}
	}

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int final = result[x2][y2] - result[x1 - 1][y2] - result[x2][y1 - 1] + result[x1 - 1][y1 - 1];
		printf("%d\n", final);
	}
}