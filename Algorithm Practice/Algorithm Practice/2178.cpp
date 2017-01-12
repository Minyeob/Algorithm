#include <cstdio>

char map[101][101];
int check[101][101];
int x_plus[4] = { -1, 1, 0, 0 };
int y_plus[4] = { 0, 0, -1, 1 };
int final_length;

int dfs(int x, int y,int n,int m,int length)
{	
	check[x][y] = 1;
	length++;
	printf("x is %d y is %d length is %d\n", x+1, y+1,length);
	if (x == n - 1 && y == m - 1)
	{
		if (length < final_length)
			final_length = length;
		return final_length;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + x_plus[i];
		int next_y = y + y_plus[i];
		if (0<=next_x<n && 0<=next_y<m)
		{
			if (map[next_x][next_y] =='1' && check[next_x][next_y] != 1)
				dfs(next_x, next_y, n, m, length);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
	}
	printf("-----------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", map[i]);
	}

	printf("%c", map[0][2]);
	int length = 0;
	final_length = 100000;
	length=dfs(0, 0, n, m, length);

	printf("%d", final_length);

	
}