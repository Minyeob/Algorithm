#include <cstdio>
#include <algorithm>
using namespace std;

int cost[501];
int result[501][501];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &cost[j]);
		}

		if (i == 1)
			result[1][1] = cost[1];
		else
		{
			for (int j = 1; j <= n; j++)
			{
				result[i][j] = max(result[i - 1][j - 1] + cost[j], result[i - 1][j] + cost[j]);
			}
		}
	}

	int final = result[n][1];
	for (int i = 2; i <= n; i++)
	{
		final=max(final,result[n][i]);
	}
	printf("%d", final);
}