#include <cstdio>

int board[20][20];
int next_x[4] = { 0, 1, 1, 1 };
int next_y[4] = { 1, 1, 0, -1 };
int pre_x[4] = { 0, -1, -1, -1 };
int pre_y[4] = { -1, -1, 0, 1 };
bool success;

void find(int x, int y, int color, int length, int loc)
{
	int nex = x + next_x[loc];
	int ney = y + next_y[loc];

	if (length == 5)
	{
		if (board[nex][ney] != color)
			success = true;
	}

	if (board[nex][ney] == color && nex > 0 && nex < 20 && ney>0 && ney < 20)
	{
		//printf("nex is %d ney is %d  loc is %d\n", nex, ney,loc);
		find(nex, ney, color, length + 1, loc);
	}
}

int main()
{
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			//printf("i is %d j is %d\n", i, j);
			if (board[i][j] == 1)
			{
				if (board[i][j - 1] != 1)
				{
					//printf("i is %d j-1 is %d\n", i, j - 1);
					find(i, j, 1, 1, 0);
				}
				if (board[i - 1][j - 1] != 1)
				{
					//printf("i-1 is %d j-1 is %d\n", i - 1, j - 1);
					find(i, j, 1, 1, 1);
				}
				if (board[i - 1][j] != 1)
				{
					//printf("i-1 is %d j is %d\n", i - 1, j);
					find(i, j, 1, 1, 2);
				}
				if (board[i - 1][j + 1] != 1)
				{
					//printf("i-1 is %d j+1 is %d\n", i - 1, j + 1);
					find(i, j, 1, 1, 3);
				}

				if (success)
				{
					printf("1\n");
					printf("%d %d", i, j);
					return 0;
				}
			}

			if (board[i][j] == 2)
			{
				if (board[i][j-1] != 2)
					find(i, j, 2, 1, 0);
				if (board[i - 1][j - 1] != 2)
					find(i, j, 2, 1, 1);
				if (board[i - 1][j] != 2)
					find(i, j, 2, 1, 2);
				if (board[i - 1][j+1] != 2)
					find(i, j, 2, 1, 3);

				if (success)
				{
					printf("2\n");
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	printf("0");
	return 0;
}