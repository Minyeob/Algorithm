#include <stdio.h>
#include <stdlib.h>

int point[1001][1001];
int start[1001];

void dfs(int start)
{
	for (int i = 1; i < 1001; i++)
	{
		if (point[start][i] == 1)
		{
			point[start][i] = 0;
			point[i][start] = 0;
			dfs(i);
		}
	}
}

int main()
{
	int node, edge;
	scanf("%d %d", &node, &edge);
	int count = 0;

	for (int i = 0; i < edge; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		point[a][b] = 1;
		point[b][a] = 1;
	}

	if (node == 1)
	{
		printf("1");
		exit(1);
	}
	for (int i = 1; i < node; i++)
	{
		for (int j = 1; j < node; j++)
		{
			if (point[i][j]==1)
			{
				count++;
				dfs(i);
				break;
			}
		}
	}

	printf("%d", count);

	return 0;
}