#include <cstdio>
#include <queue>
using namespace std;
int input[1000][1000];
int check[1000][1000];

struct tomato
{
	int x;
	int y;
	int day;
};
queue<tomato> q;

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &input[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (input[i][j] == 1)
			{
				check[i][j] = 100;
				tomato t;
				t.x = j;
				t.y = i;
				t.day = 100;
				q.push(t);
			}
		}
	}
	int next_x[4] = { 1,-1,0,0 };
	int next_y[4] = { 0,0,1, - 1 };

	while (!q.empty())
	{
		tomato t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nex = t.x + next_x[i];
			int ney = t.y + next_y[i];
			if (nex >= 0 && ney >= 0 && nex < m && ney < n)
			{
				if (check[ney][nex] == 0 && input[ney][nex]==0)
				{
					check[ney][nex] = t.day + 1;
					tomato new_tom;
					new_tom.x = nex;
					new_tom.y = ney;
					new_tom.day = t.day + 1;
					q.push(new_tom);
					//printf("x is %d y is %d day is %d \n", ney, nex, t.day + 1);
				}
			}
		}
	}
	int max = 100;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == 0 && input[i][j]==0)
			{
				max = 99;
				break;
			}
			else if (check[i][j] > max)
				max = check[i][j];
		}
		if (max == 99)
			break;
	}
	printf("%d", max - 100);
}

