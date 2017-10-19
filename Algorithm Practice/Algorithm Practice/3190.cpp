#include <cstdio>
#include <queue>
using namespace std;

int board[102][102];
queue<pair<int, int>> point;
queue<pair<int, char>> dir_queue;

int main()
{
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i<k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		//board가 1이라면 사과가 있는것
		board[x][y] = 1;
	}

	int l;
	scanf("%d", &l);

	for (int i = 0; i<l; i++)
	{
		int x;
		char c;
		scanf("%d %c", &x, &c);
		pair<int, char> p;
		p.first = x;
		p.second = c;
		dir_queue.push(p);
	}

	int x = 1;
	int y = 1;
	pair<int, int> p;
	p.first = x;
	p.second = y;
	point.push(p);
	pair<int, char> dir_next;
	dir_next = dir_queue.front();
	dir_queue.pop();
	//0이 오른쪽 1이 왼쪽 2가 아래 3이 위쪽
	int dir = 0;
	int time = 0;
	int final = 0;
	while (1)
	{
		time++;
		if (dir == 0)
			y++;
		else if (dir == 1)
			y--;
		else if (dir == 2)
			x++;
		else if (dir == 3)
			x--;
		pair<int, int> now;
		now.first = x;
		now.second = y;
		point.push(now);
		if (board[x][y] == 1)
		{
			board[x][y] = 2;
		}
		else if (board[x][y] == 0)
		{
			pair<int, int> temp = point.front();
			point.pop();
			board[temp.first][temp.second] = 0;
			board[x][y] = 2;
		}
		else if (board[x][y] == 2)
		{
			final = time;
			break;
		}

		if (dir_next.first == time)
		{
			//printf("dir change now dir is %d next dir is %c time is %d\n",dir,dir_next.second,time);
			if (dir_next.second == 'L')
			{
				if (dir == 0)
					dir = 3;
				else if (dir == 1)
					dir = 2;
				else if (dir == 2)
					dir = 0;
				else if (dir == 3)
					dir = 1;
			}
			else if (dir_next.second == 'D')
			{
				if (dir == 0)
					dir = 2;
				else if (dir == 1)
					dir = 3;
				else if (dir == 2)
					dir = 1;
				else if (dir == 3)
					dir = 0;
			}
			if (!dir_queue.empty())
			{
				dir_next = dir_queue.front();
				dir_queue.pop();
			}
		}

		if (x>n || y>n || x <= 0 || y <= 0)
		{
			final = time;
			break;
		}
	}

	printf("%d", final);
}