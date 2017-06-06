#include <cstdio>

int first[100][100];
int second[100][100];
int result[100][100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &first[i][j]);
	}
	
	int k;
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
			scanf("%d", &second[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int t = 0; t < m; t++)
			{
				result[i][j] += first[i][t] * second[t][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}