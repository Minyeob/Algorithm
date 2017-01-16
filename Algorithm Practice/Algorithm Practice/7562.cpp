#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

bool check[501][501];
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
	return 0;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{		
		memset(check, 0, sizeof(check));
		int size;
		scanf("%d", &size);
		int x, y, nx, ny;
		scanf("%d %d", &x, &y);
		point now;
		now.x = x;
		now.y = y;
		now.count = 0;
		check[x][y] = 1;
		scanf("%d %d", &nx, &ny);
		point goal;
		goal.x = nx;
		goal.y = ny;
		goal.count = 0;
		int count = 0;

		if (now.x == goal.x && now.y == goal.y)
		{
			count = 0;
		}
		else
		{
			count = bfs(now, goal, size);
		}
		printf("%d\n", count);


		while (!q.empty())
		{
			q.pop();
		}
	}
}