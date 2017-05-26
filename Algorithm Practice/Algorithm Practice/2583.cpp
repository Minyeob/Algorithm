#include <cstdio>
#include <algorithm>
using namespace std;

int input[101][101];
bool check[101][101];
int sum[5001];
int m, n, k;

void dfs(int y, int x,int loc)
{
	check[y][x] = true;
	sum[loc] += 1;
	if (y - 1 >= 0 && input[y - 1][x] == 0 && check[y - 1][x] == false)
		dfs(y - 1, x,loc);
	if (y + 1 < n && input[y + 1][x] == 0 && check[y + 1][x] == false)
		dfs(y + 1, x,loc);
	if (x - 1 >= 0 && input[y][x - 1] == 0 && check[y][x - 1] == false)
		dfs(y, x - 1,loc);
	if (x + 1 < m && input[y][x + 1] == 0 && check[y][x + 1] == false)
		dfs(y, x + 1,loc);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
				input[j][k] = 1;
		}
	}

	int loc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (input[i][j] == 0 && check[i][j] == false)
			{
				dfs(i, j, loc);
				loc++;
			}
			else
				check[i][j] = true;
		}
	}

	sort(sum, sum + loc);
	printf("%d\n", loc);
	for (int i = 0; i < loc; i++)
		printf("%d ", sum[i]);
}