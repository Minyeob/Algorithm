#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
vector<vector<int>> v;
int check[1001];
queue <int> q;

void dfs(int start)
{
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (!check[next])
		{
			q.push(next);
			check[next] = 1;
			dfs(next);
		}		
	}
}

void bfs(int start)
{
	q.push(start);
	check[start] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (!check[next])
			{				
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int node;
	int edge;
	int start;

	cin >> node >> edge >> start;
	v.resize(node + 1);
	
	for (int i = 0; i < edge; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); 
		v[b].push_back(a);
	}

	for (int i = 1; i < node + 1; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	check[start] = 1;
	q.push(start);
	dfs(start);

	while (!q.empty())
	{
		cout << q.front() <<' ';
		q.pop();
	}
	cout << endl;
	memset(check,0,sizeof(check));
	bfs(start);
}