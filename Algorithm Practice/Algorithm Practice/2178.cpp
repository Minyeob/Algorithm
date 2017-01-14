#include <cstdio>
#include<queue>
using namespace std;

char map[101][101];
bool check[101][101];
int x_plus[4] = { 1, 0, -1, 0 };
int y_plus[4] = { 0, 1, 0, -1 };
int final_length;

typedef struct{
	int x;
	int y;
	int distance;
}point;

queue<point> q;

void bfs(int x, int y,int n,int m,int length)
{	
	point p;
	p.x = x;
	p.y = y;
	p.distance = length;
	check[x][y] = 1;
	q.push(p);
	
	while (!q.empty())
	{
		point now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		
		if (x == n - 1 && y == m - 1)
		{
			if (now.distance < final_length)
			{
				final_length = now.distance;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + x_plus[i];
			int next_y = y + y_plus[i];
			point next;
			next.x = next_x;
			next.y = next_y;
			next.distance = now.distance+1;

			if (0 <= next_x && next_x< n && 0 <= next_y && next_y< m)
			{
				if (map[next_x][next_y] == '1' && check[next_x][next_y] == 0)
				{
					check[next_x][next_y] = 1;
					q.push(next);
				}
			}
		}
	}	
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
	}

	int length = 1;
	final_length = 100000;
	bfs(0, 0, n, m, length);

	printf("%d", final_length);

	
}