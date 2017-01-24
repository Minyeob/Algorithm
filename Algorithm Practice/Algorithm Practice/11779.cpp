#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct edge{
	int end;
	int cost;

	edge(){};
	edge(const edge& temp)
	{
		end = temp.end;
		cost = temp.cost;
	}

	inline void operator = (const edge& temp)
	{
		end = temp.end;
		cost = temp.cost;
	}

	inline bool operator < (const edge& temp) const
	{
		return cost < temp.cost;
	}
};

priority_queue<edge> q;
bool check[1001];
vector<vector<edge>> v;
vector<vector<int>> way;
int result[1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	way.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.end = b;
		e.cost = c;
		v[a].push_back(e);
	}

	int start, destination;
	scanf("%d %d", &start, &destination);

	edge e;
	e.end = start;
	e.cost = 0;
	q.push(e);
	int max = 100000 * n;
	for (int i = 0; i <= n; i++)
	{
		result[i] = max;
	}
	result[start] = 0;
	way[start].push_back(start);

	while (!q.empty())
	{
		edge now = q.top();
		q.pop();
		if (result[now.end] < now.cost)
			continue;
		for (int i = 0; i < v[now.end].size(); i++)
		{
			edge next = v[now.end][i];
			if (result[next.end] > result[now.end] + next.cost)
			{
				result[next.end] = result[now.end] + next.cost;
				way[next.end].clear();
				for (int i = 0; i < way[now.end].size(); i++)
				{
					way[next.end].push_back(way[now.end][i]);
				}
				way[next.end].push_back(next.end);
				edge e;
				e.end = next.end;
				e.cost = result[next.end];
				q.push(e);
			}
		}
	}

	printf("%d\n", result[destination]);
	printf("%d\n", way[destination].size());
	for (int i = 0; i < way[destination].size(); i++)
	{
		printf("%d ", way[destination][i]);
	}
}