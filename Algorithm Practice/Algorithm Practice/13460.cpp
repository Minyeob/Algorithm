#include <cstdio>
#include <cstdlib>
char board[11][11];
int min;
int n, m;

void down(int red_x, int red_y, int blue_x, int blue_y, int count);
void left(int red_x, int red_y, int blue_x, int blue_y, int count);
void right(int red_x, int red_y, int blue_x, int blue_y, int count);
void up(int red_x, int red_y, int blue_x, int blue_y, int count)
{
	int x, y, ax, ay;
	char first;
	if (blue_x < red_x)
	{
		x = blue_x;
		y = blue_y;
		ax = red_x;
		ay = red_y;
		first = 'b';
	}
	else
	{
		x = red_x;
		y = red_y;
		ax = blue_x;
		ay = blue_y;
		first = 'r';
	}

	for (int i = x-1; i >= 0; i--)
	{
		if (board[i][y] == 'O')
		{
			if (first == 'r')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[i][y] == '.')
			continue;
		else if(board[i][y]=='#')
		{
			x = i + 1;
			break;
		}
	}
	board[x][y] = '#';

	for (int i = ax - 1; i >= 0; i--)
	{
		if (board[i][ay] == 'O')
		{
			if (first == 'b')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[i][ay] == '.')
			continue;
		else if (board[i][ay] == '#')
		{
			ax = i + 1;
			break;
		}
	}
	board[x][y] = '.';
	
	if (x == ax && y == ay)
		return;

	printf("x is %d y is %d ax is %d ay is %d count is %d\n", x, y, ax, ay, count);
	if (count < 9)
	{
		if (first == 'b')
		{
			//up(ax, ay, x, y, count + 1);
			//down(ax, ay, x, y, count + 1);
			left(ax, ay, x, y, count + 1);
			right(ax, ay, x, y, count + 1);
		}
		else
		{
			//up(x, y, ax, ay, count + 1);
			//down(x, y, ax, ay, count + 1);
			left(x, y, ax, ay, count + 1);
			right(x, y, ax, ay, count + 1);
		}
	}
}

void down(int red_x, int red_y, int blue_x, int blue_y, int count)
{
	int x, y, ax, ay;
	char first;
	if (blue_x < red_x)
	{
		x = blue_x;
		y = blue_y;
		ax = red_x;
		ay = red_y;
		first = 'b';
	}
	else
	{
		x = red_x;
		y = red_y;
		ax = blue_x;
		ay = blue_y;
		first = 'r';
	}

	for (int i = x + 1; i < n; i++)
	{
		if (board[i][y] == 'O')
		{
			if (first == 'r')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[i][y] == '.')
			continue;
		else if(board[i][y]=='#')
		{
			x = i - 1;
			break;
		}
	}
	board[x][y] = '#';

	for (int i = ax + 1; i < n; i++)
	{
		if (board[i][ay] == 'O')
		{
			if (first == 'b')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[i][ay] == '.')
			continue;
		else if (board[i][ay] == '#')
		{
			ax = i - 1;
			break;
		}
	}
	board[x][y] = '.';
	
	if (x == ax && y == ay)
		return;
	printf("x is %d y is %d ax is %d ay is %d count is %d\n", x, y, ax, ay, count);
	if (count < 9)
	{
		if (first == 'b')
		{
			//up(ax, ay, x, y, count + 1);
			//down(ax, ay, x, y, count + 1);
			left(ax, ay, x, y, count + 1);
			right(ax, ay, x, y, count + 1);
		}
		else
		{
			//up(x, y, ax, ay, count + 1);
			//down(x, y, ax, ay, count + 1);
			left(x, y, ax, ay, count + 1);
			right(x, y, ax, ay, count + 1);
		}
	}
}

void left(int red_x, int red_y, int blue_x, int blue_y, int count)
{
	int x, y, ax, ay;
	char first;
	if (blue_x < red_x)
	{
		x = blue_x;
		y = blue_y;
		ax = red_x;
		ay = red_y;
		first = 'b';
	}
	else
	{
		x = red_x;
		y = red_y;
		ax = blue_x;
		ay = blue_y;
		first = 'r';
	}

	for (int i = y - 1; i >= 0; i--)
	{
		//printf("x is %d y is %d   %c  \n", x, i, board[x][i]);
		if (board[x][i] == 'O')
		{	
			if (first == 'r')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[x][i] == '.')
			continue;
		else if(board[x][i]=='#')
		{
			y = i + 1;
			break;
		}
	}
	board[x][y] = '#';

	for (int i = ay - 1; i >= 0; i--)
	{
		if (board[ax][i] == 'O')
		{
			if (first == 'b')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[ax][i] == '.')
			continue;
		else if(board[ax][i]=='#')
		{
			ay = i + 1;
			break;
		}
	}
	board[x][y] = '.';

	if (x == ax && y == ay)
		return;
	printf("x is %d y is %d ax is %d ay is %d count is %d\n", x, y, ax, ay, count);
	if (count < 9)
	{
		if (first == 'b')
		{
			up(ax, ay, x, y, count + 1);
			down(ax, ay, x, y, count + 1);
			//left(ax, ay, x, y, count + 1);
			//right(ax, ay, x, y, count + 1);
		}
		else
		{
			up(x, y, ax, ay, count + 1);
			down(x, y, ax, ay, count + 1);
			//left(x, y, ax, ay, count + 1);
			//right(x, y, ax, ay, count + 1);
		}
	}
}

void right(int red_x, int red_y, int blue_x, int blue_y, int count)
{
	int x, y, ax, ay;
	char first;
	if (blue_x < red_x)
	{
		x = blue_x;
		y = blue_y;
		ax = red_x;
		ay = red_y;
		first = 'b';
	}
	else
	{
		x = red_x;
		y = red_y;
		ax = blue_x;
		ay = blue_y;
		first = 'r';
	}

	for (int i = y + 1; i < m; i++)
	{
		//printf("x is %d y is %d   %c\n", x, i, board[x][i]);
		if (board[x][i] == 'O')
		{
			if (first == 'r')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[x][i] == '.')
			continue;
		else if (board[x][i] == '#')
		{
			y = i - 1;
			break;
		}
	}
	board[x][y] = '#';

	for (int i = ay + 1; i < m; i++)
	{
		if (board[ax][i] == 'O')
		{
			if (first == 'b')
			{
				if (count + 1 < min)
					min = count + 1;
			}
			return;
		}
		else if (board[ax][i] == '.')
			continue;
		else if (board[ax][i] == '#')
		{
			ay = i - 1;
			break;
		}
	}
	board[x][y] = '.';

	if (x == ax && y == ay)
		return;
	printf("x is %d y is %d ax is %d ay is %d count is %d\n", x, y, ax, ay, count);
	if (count < 9)
	{
		if (first == 'b')
		{
			up(ax, ay, x, y, count + 1);
			down(ax, ay, x, y, count + 1);
			//left(ax, ay, x, y, count + 1);
			//right(ax, ay, x, y, count + 1);
		}
		else
		{
			up(x, y, ax, ay, count + 1);
			down(x, y, ax, ay, count + 1);
			//left(x, y, ax, ay, count + 1);
			//right(x, y, ax, ay, count + 1);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	min = 11;
	int red_x, red_y, blue_x, blue_y;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				red_x = i;
				red_y = j;
			}
			if (board[i][j] == 'B')
			{
				blue_x = i;
				blue_y = j;
			}
		}
	}

	up(red_x, red_y, blue_x, blue_y, 0);
	down(red_x, red_y, blue_x, blue_y, 0);
	left(red_x, red_y, blue_x, blue_y, 0);
	right(red_x, red_y, blue_x, blue_y, 0);

	if (min <= 10)
		printf("%d", min);
	else
		printf("-1");
}