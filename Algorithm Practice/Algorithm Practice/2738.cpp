#include <cstdio>

int input[100][100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &input[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			scanf("%d", &temp);
			input[i][j] += temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", input[i][j]);
		printf("\n");
	}
}