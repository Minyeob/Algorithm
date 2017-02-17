#include <cstdio>

char board[21][21];
char record[30];
int r, c;
int max;

int next_x[4] = { 1, -1, 0, 0 };
int next_y[4] = { 0, 0, 1, -1 };

bool check(int x, int y, int length)
{
	char temp = board[x][y];
	for (int j = 0; j < length; j++)
	{
		if (record[j] == temp)
			return false;
	}
	return true;
}

void find(int x, int y, int length)
{
	if (max < length)
		max = length;

	for (int i = 0; i < 4; i++)
	{
		int nex = x + next_x[i];
		int ney = y + next_y[i];

		if (nex >= 0 && nex < r && ney >= 0 && ney < c)
		{
			//printf("next is %c\n", board[nex][ney]);
			bool cont=check(nex, ney, length);
			if (cont == true)
			{
				record[length] = board[nex][ney];
				find(nex, ney, length + 1);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
	{
		scanf("%s", board[i]);
	}

	record[0] = board[0][0];
	int length = 1;
	find(0, 0, 1);
	printf("%d", max);
}