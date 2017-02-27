#include <cstdio>
int board[501][501];
int num[501][501];
int final[501][501];
long long count;

int dfs(int x, int y, int m, int n)
{
	int next_x[4] = { 1,-1,0,0 };
	int next_y[4] = { 0,0,1,-1 };

	if (x == 1 && y == 1)
		return 1;
	if (num[x][y] == 0) 
	{
		for (int i = 0; i < 4; i++)
		{
			int nex = x + next_x[i];
			int ney = y + next_y[i];

			if (nex > 0 && nex <= m && ney > 0 && ney <= n)
			{
				if (board[x][y] < board[nex][ney])
				{
					num[x][y] = num[x][y] + dfs(nex, ney, m, n);
				}
			}
		}
	}
	return num[x][y];
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	dfs(m, n, m, n);
	printf("%d", num[m][n]);
}
