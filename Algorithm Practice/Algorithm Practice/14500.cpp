#include <cstdio>

int board[500][500];
bool check[500][500];
int n, m;
int final;

void second(int x, int y, int sum);
void cal(int x, int y, int count, int sum);

void first(int x, int y)
{
	check[x][y] = true;
	int sum = board[x][y];
	second(x, y, sum);
}

void second(int x, int y, int sum)
{
	int nex = x;
	int ney = y + 1;

	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		if (check[nex][ney] == false)
		{
			check[nex][ney] = 1;
			int new_sum = sum + board[nex][ney];
			cal(nex, ney, 2, new_sum);
			cal(x, y, 2, new_sum);
			check[nex][ney] = 0;
		}
	}

	nex = x + 1;
	ney = y;

	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		if (check[nex][ney] == false)
		{
			check[nex][ney] = 1;
			int new_sum = sum + board[nex][ney];
			cal(nex, ney, 2, new_sum);
			cal(x, y, 2, new_sum);
			check[nex][ney] = 0;
		}
	}
}

void cal(int x, int y, int count, int sum)
{
	if (count == 4)
	{
		if (sum>final)
			final = sum;
		return;
	}
	int	x_next[4] = { 1,-1,0,0 };
	int y_next[4] = { 0,0,1,-1 };

	for (int i = 0; i<4; i++)
	{
		int nex = x + x_next[i];
		int ney = y + y_next[i];

		if (nex >= 0 && nex<n && ney >= 0 && ney<m)
		{
			if (check[nex][ney] == false)
			{
				check[nex][ney] = 1;
				int new_sum = sum + board[nex][ney];
				cal(nex, ney, count + 1, new_sum);
				cal(x, y, count + 1, new_sum);
				check[nex][ney] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			scanf("%d", &board[i][j]);
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			first(i, j);
	}
	printf("%d", final);
}