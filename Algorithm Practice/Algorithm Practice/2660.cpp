#include <cstdio>
int point[51][51];
int rank[51];

int main()
{	
	int number;
	scanf("%d", &number);
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 1; j <= 50; j++)
		{
			point[i][j] = number;
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	while (a != -1)
	{
		point[a][b] = 1;
		point[b][a] = 1;

		scanf("%d %d", &a, &b);
	}

	for (int i = 1; i <= 50; i++)
	{
		point[i][i] = 1;
	}

	for (int k = 1; k <= number; k++)
	{
		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number; j++)
			{
				if (point[i][j] > (point[i][k] + point[k][j]))
				{
					point[i][j] = point[i][k] + point[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= number; i++)
	{
		int max = 1;
		for (int j = 1; j <= number; j++)
		{
			if (point[i][j] > max)
				max = point[i][j];
		}
		rank[i] = max;
	}

	int min = 9999;
	for (int i = 1; i <= number; i++)
	{
		if (rank[i] < min)
			min = rank[i];
	}

	int count = 0;
	for (int i = 1; i <= number; i++)
	{
		if (rank[i] == min)
			count++;
	}
	printf("%d %d\n", min, count);
	for (int i = 1; i <= number; i++)
	{
		if (rank[i] == min)
			printf("%d ", i);
	}
}