#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int point[1001][1001];
int check[1001];
int check2[1001];
queue<int> q;

void dfs(int start)
{
	printf("%d ", start);
	check[start] = 1;

	for (int i = 0; i < 1001; i++)
	{
		if (point[start][i] == 1 && !check[i])
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	check2[start] = 1;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < 1001; i++)
		{
			if (point[cur][i] == 1 && !check2[i])
			{
				q.push(i);
				check2[i] = 1;
			}
		}
	}
}

int main()
{
	int node, edge, start;
	scanf("%d %d %d", &node, &edge, &start);
	for (int i = 0; i < edge; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		point[a][b] = 1;
		point[b][a] = 1;
	}
	dfs(start);
	printf("\n");
	bfs(start);

	return 0;
}