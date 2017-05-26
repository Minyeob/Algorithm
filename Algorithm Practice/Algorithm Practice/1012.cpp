#include <cstdio>

int input[51][51];
bool check[51][51];
int n, m, k;

void dfs(int y, int x)
{
	check[y][x] = true;
	if (y - 1 >= 0 && input[y - 1][x] == 1 && check[y - 1][x] == false)
		dfs(y - 1, x);
	if (y + 1 < n && input[y + 1][x] == 1 && check[y + 1][x] == false)
		dfs(y + 1, x);
	if (x - 1 >= 0 && input[y][x-1] == 1 && check[y][x-1] == false)
		dfs(y, x-1);
	if (x + 1 < m && input[y][x+1] == 1 && check[y][x+1] == false)
		dfs(y, x+1);
}

int main()
{
	int num;
	scanf("%d", &num);
	for (int c = 0; c < num; c++)
	{
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			input[y][x] = 1;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (input[i][j] == 1 && check[i][j] == false)
				{
					count++;
					dfs(i, j);
				}
				else
					check[i][j] = true;
			}
		}

		printf("%d\n", count);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				input[i][j] = 0;
				check[i][j] = false;
			}
		}
	}
}