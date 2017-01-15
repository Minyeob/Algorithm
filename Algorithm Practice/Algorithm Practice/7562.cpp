#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int board[301][301];
bool check[301][301];
int result[100000];
typedef struct{
	int x;
	int y;
	int count;
}point;

queue<point> q;

int next_x[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int next_y[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int bfs(point n, point goal,int size)
{
	q.push(n);

	while (!q.empty())
	{
		point now = q.front();
		//printf("now x is %d now y is %d count is %d\n", now.x, now.y, now.count);
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int x = now.x + next_x[i];
			int y = now.y + next_y[i];
			int count = now.count + 1;


			if (x == goal.x && y == goal.y)
			{
				return count;
			}
			point next;
			next.x = x;
			next.y = y;
			next.count = count;

			if (0 <= x && x < size && 0 <= y && y < size && check[x][y]==0)
			{
				check[x][y] = 1;
				q.push(next);
			}
		}
		
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int size;
		scanf("%d", &size);
		int x, y;
		scanf("%d %d", &x, &y);
		point now;
		now.x = x;
		now.y = y;
		now.count = 0;
		check[x][y] = 1;
		scanf("%d %d", &x, &y);
		point goal;
		goal.x = x;
		goal.y = y;
		int count = 0;

		if (now.x == goal.x && now.y == now.y)
		{
			count = 0;
		}
		else
		{
			count = bfs(now, goal, size);
		}
		result[i] = count;
		memset(check, 0, sizeof(check));

		while (!q.empty())
		{
			q.pop();
		}
	}

	for (int i = 0; i < t; i++)
	{
		printf("%d\n", result[i]);
	}
}