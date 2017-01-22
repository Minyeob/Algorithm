#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

struct edge{
	int start;
	int end;
	int cost;

	edge(){}
	edge(const edge& temp)
	{
		start = temp.start;
		end = temp.end;
		cost = temp.cost;
	}

	void operator=(const edge& temp)
	{
		start = temp.start;
		end = temp.end;
		cost = temp.cost;
	}

	bool operator<(const edge& temp)
	{
		if (cost < temp.cost)
			return true;
		else
			return false;
	}
};
vector<vector<edge>> cost;

int dist[1001];
bool check[1001];

void swap(int a, int b, int index)
{
	edge temp = cost[index][a];
	cost[index][a] = cost[index][b];
	cost[index][b] = temp;
}

void quick(int start, int end,int index)
{
	if (start >= end)
		return;
	int loc = start;
	edge pivot = cost[index][loc];
	//printf("start is %d end is %d pivot is %d\n", start, end, pivot.cost);
	swap(loc, end,index);

	for (int i = start; i < end; i++)
	{
		//printf("temp start is %d end is %d cost is %d\n", cost[index][i].start, cost[index][i].end, cost[index][i].cost);
		if (cost[index][i] < pivot)
		{
			swap(i, loc, index);
			loc++;
		}
	}
	swap(loc, end,index);

	quick(start, loc - 1,index);
	quick(loc + 1, end,index);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	cost.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.start = a;
		e.end = b;
		e.cost = c;
		cost[a].push_back(e);
	}
	int start_city, destination;
	scanf("%d %d", &start_city, &destination);

	int max = n * 100000;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = max;
	}
	dist[start_city] = 0;	

	int node = start_city;
	for (int i = 1; i < n; i++)
	{	
		int min = max;
		int loc = start_city;
		for (int j = 1; j <=n; j++)
		{
			if (check[j] == false && dist[j] != max)
			{
				if (dist[j] < min)
				{
					min = dist[j];
					loc = j;
				}
			}
		}
		//printf("loc is %d\n", loc);
		check[loc] = true;
		for (int k = 0; k < cost[loc].size(); k++)
		{
			edge next = cost[loc][k];
			if (dist[next.end]>dist[next.start] + next.cost)
				dist[next.end] = dist[next.start] + next.cost;
			//printf("to %d dist is %d  start dist is %d and cost is %d\n", next.end, dist[next.end],dist[next.start], next.cost);
		}		
	}

	printf("%d", dist[destination]);
}