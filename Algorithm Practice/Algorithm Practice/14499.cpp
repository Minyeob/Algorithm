#include <cstdio>

int board[20][20];
int dice[7];
int n, m, x, y, k;

void three();
void two();
void one();
void four()
{
	int nex = x + 1;
	int ney = y;
	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		x = nex;
		int under = dice[5];
		int south = dice[1];
		int up = dice[2];
		int north = dice[6];

		//¹Ù´Ú¸éÀÌ 0ÀÏ¶§
		if (board[x][y] == 0)
		{
			board[x][y] = under;
		}
		else
		{
			under = board[x][y];
			board[x][y] = 0;
		}
		printf("%d\n", up);
		dice[2] = north;
		dice[1] = up;
		dice[5] = south;
		dice[6] = under;
	}
}

void three()
{
	int nex = x - 1;
	int ney = y;
	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		x = nex;
		int under = dice[2];
		int south = dice[6];
		int up = dice[5];
		int north = dice[1];

		//¹Ù´Ú¸éÀÌ 0ÀÏ¶§
		if (board[x][y] == 0)
		{
			board[x][y] = under;
		}
		else
		{
			under = board[x][y];
			board[x][y] = 0;
		}
		printf("%d\n", up);
		dice[2] = north;
		dice[1] = up;
		dice[5] = south;
		dice[6] = under;
	}
}

void one()
{
	int nex = x;
	int ney = y + 1;
	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		y = ney;
		int under = dice[3];
		int east = dice[1];
		int up = dice[4];
		int west = dice[6];

		//¹Ù´Ú¸éÀÌ 0ÀÏ¶§
		if (board[x][y] == 0)
		{
			board[x][y] = under;
		}
		else
		{
			under = board[x][y];
			board[x][y] = 0;
		}
		printf("%d\n", up);
		dice[3] = east;
		dice[1] = up;
		dice[4] = west;
		dice[6] = under;
	}
}

void two()
{
	int nex = x;
	int ney = y - 1;
	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		y = ney;
		int under = dice[4];
		int east = dice[6];
		int up = dice[3];
		int west = dice[1];

		//¹Ù´Ú¸éÀÌ 0ÀÏ¶§
		if (board[x][y] == 0)
		{
			board[x][y] = under;
		}
		else
		{
			under = board[x][y];
			board[x][y] = 0;
		}
		printf("%d\n", up);
		dice[3] = east;
		dice[1] = up;
		dice[4] = west;
		dice[6] = under;
	}
}

int main()
{
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			scanf("%d", &board[i][j]);
	}

	for (int i = 0; i<k; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
			one();
		else if (t == 2)
			two();
		else if (t == 3)
			three();
		else if (t == 4)
			four();
	}
}