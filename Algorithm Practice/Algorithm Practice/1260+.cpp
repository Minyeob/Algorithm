#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector <int>> vec;
queue<int> q;
int check[1001];
int check2[1001];

void dfs(int end)
{
	check[end] = 1;
	printf("%d ",end);

	for (int i = 0; i < vec[end].size(); i++)
	{
		int next = vec[end][i];
		if (!check[next])
			dfs(next);
	}
}

void bfs()
{	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (!check2[next])
			{
				q.push(next);
				check2[next] = 1;
			}
		}
	}
}


int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	vec.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(v);
	printf("\n");
	q.push(v);
	check2[v] = 1;
	bfs();
}