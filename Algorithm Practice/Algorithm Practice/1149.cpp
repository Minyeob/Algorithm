#include <cstdio>

int cost[1001][3];
int result[1001][2];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &cost[i][j]);
	}

	for (int i = 1; i < n; i++)
	{
		if (result[i - 1][0] == 0)
		{
			int left = cost[i][1];
			int right = cost[i][2];

			if (left > right)
			{
				result[i][0] = 1;
				result[i][1] = result[i - 1][1] + left;
			}
			
		}
	}
}