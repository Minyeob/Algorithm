#include <cstdio>

int board[51][51];
int final;
int n, m;
void check(int x, int y, int dir, int count);
//0은 아직 청소가 되지 않은 영역, 1은 벽, 2는 청소가 완료된 영역
void clear(int x, int y, int dir)
{
	board[x][y] = 2;
	//printf("x is %d y is %d \n",x,y);
	final++;
	check(x, y, dir, 0);
}

void check(int x, int y, int dir, int count)
{
	if (count == 4)
	{
		int x_back = x;
		int y_back = y;
		if (dir == 0)
			x_back = x + 1;
		else if (dir == 1)
			y_back = y - 1;
		else if (dir == 2)
			x_back = x - 1;
		else if (dir == 3)
			y_back = y + 1;

		if (x_back >= 0 && x_back<n && y_back >= 0 && y_back<m)
		{
			if (board[x_back][y_back] != 1)
				check(x_back, y_back, dir, 0);
			else
				return;
		}
		return;
	}
	int dir_now;
	//0은 북쪽, 1은 동쪽, 2는 남쪽, 3은 서쪽
	if (dir == 0)
		dir_now = 3;
	else if (dir == 1)
		dir_now = 0;
	else if (dir == 2)
		dir_now = 1;
	else if (dir == 3)
		dir_now = 2;

	int nex = x;
	int ney = y;
	//printf("nex is %d ney is %d count is %d dir_now is %d\n",nex,ney,count,dir_now);
	if (dir_now == 0)
		nex = x - 1;
	else if (dir_now == 1)
		ney = y + 1;
	else if (dir_now == 2)
		nex = x + 1;
	else if (dir_now == 3)
		ney = y - 1;

	if (nex >= 0 && nex<n && ney >= 0 && ney<m)
	{
		if (board[nex][ney] == 0)
			clear(nex, ney, dir_now);
		else
			check(x, y, dir_now, count + 1);
	}
	else
		check(x, y, dir_now, count + 1);
}

int main()
{
	scanf("%d %d", &n, &m);

	int r, c, d;
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			scanf("%d", &board[i][j]);
	}

	clear(r, c, d);
	printf("%d", final);
}