#include <cstdio>
#include <algorithm>
using namespace std;
int cost[1001][1001];
int result[1001][1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &cost[i][j]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int big = max(result[i - 1][j], result[i][j - 1]);
			big = max(big, result[i - 1][j - 1]);
			result[i][j] = big + cost[i][j];
		}
	}

	printf("%d", result[n][m]);
}