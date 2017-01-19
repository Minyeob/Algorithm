#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

struct edge{
	int start;
	int end;
	int cost;
};
int dist[501];
vector<edge> v;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int max = n * 10000 + 1;
	bool cycle = false;
	for (int i = 1; i < n + 1; i++)
	{
		dist[i] = max;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.start = a;
		e.end = b;
		e.cost = c;
		v.push_back(e);
	}
	dist[1] = 0;
	for (int k = 1; k <= n; k++)
	{
		//printf("k is %d\n\n", k);
		for (int i = 0; i < v.size(); i++)
		{
			int start = v[i].start;
			int end = v[i].end;
			int cost = v[i].cost;
			//printf("start is %d end is %d cost is %d dist is %d\n", start, end, cost,dist[end]);

			if (dist[start]!=max && dist[end]>dist[start] + cost)
			{
				dist[end] = dist[start] + cost;
				//printf("cost to %d is %d\n", end, dist[end]);
				if (k == n)
					cycle = true;
			}
		}
	}

	if (cycle == true)
		printf("-1\n");
	else
	{
		for (int i = 2; i < n + 1; i++)
		{
			if (dist[i] == max)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
}