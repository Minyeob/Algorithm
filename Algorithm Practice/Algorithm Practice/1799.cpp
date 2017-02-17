#include <cstdio>

int board[11][11];
int black[100][2];
int white[100][2];
int black_max;
int white_max;
int n;

int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

bool black_check(int x, int y,int length)
{
	for (int i = 0; i < length; i++)
	{
		int compx = black[i][0];
		int compy = black[i][1];
		//printf("x is %d y is %d compx is %d compy is %d\n", x, y, compx, compy);

		if (abs(compx - x) == abs(compy - y))
		{
			//printf("¿©±â¼­ ¸ØÃã!!!\n");
			return false;
		}
	}
	return true;
}

bool white_check(int x, int y, int length)
{
	for (int i = 0; i < length; i++)
	{
		int compx = white[i][0];
		int compy = white[i][1];
		//printf("x is %d y is %d compx is %d compy is %d\n", x, y, compx, compy);

		if (abs(compx - x) == abs(compy - y))
		{
			//printf("¿©±â¼­ ¸ØÃã!!!\n");
			return false;
		}
	}
	return true;
}

void black_find(int x, int y, int length)
{
	if (black_max < length)
		black_max = length;
	for (int i = x; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == x && j <= y)
				continue;
			if (board[i][j] == 1 && (i+j)%2==0)
			{
				bool tt = black_check(i, j, length);
				if (tt = true)
				{
					printf("i is %d j is %d length is %d\n", i, j, length + 1);
					black[length][0] = i;
					black[length][1] = j;
					black_find(i, j, length + 1);
				}
			}
		}
	}
}

void white_find(int x, int y, int length)
{
	if (white_max < length)
		white_max = length;
	for (int i = x; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == x && j <= y)
				continue;
			if (board[i][j] == 1 && (i + j) % 2 == 1)
			{
				bool tt = white_check(i, j, length);
				if (tt = true)
				{
					white[length][0] = i;
					white[length][1] = j;
					white_find(i, j, length + 1);
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1)
			{
				if ((i + j) % 2 == 0)
				{
					black[0][0] = i;
					black[0][1] = j;
					printf("black       start x is %d y is %d \n", i, j);
					black_find(i, j, 1);
				}
				else
				{
					white[0][0] = i;
					white[0][1] = j;
					printf("black       start x is %d y is %d \n", i, j);
					white_find(i, j, 1);
				}
			}
		}
	}

	printf("black max is %d white max is %d\n", black_max, white_max);
	for (int i = 0; i < black_max; i++)
	{
		printf("%d  %d\n", black[i][0],black[i][1]);
	}
	printf("\n");
	for (int i = 0; i < white_max; i++)
	{
		printf("%d %d\n", white[i][0],white[i][1]);
	}
	printf("\n");
	printf("%d", black_max+white_max);
}