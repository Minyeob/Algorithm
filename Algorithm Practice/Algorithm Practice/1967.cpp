#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int>> next_vertex;
vector<vector<int>> length;
int check[10001];
int max_distance;
int tail;

void dfs(int v,int distance)
{
	check[v] = 1;
	if (next_vertex[v].size() == 1)
	{
		if (distance > max_distance)
		{
			max_distance = distance;
			tail = v;
			return;
		}
	}
	
	for (int i = 0; i < next_vertex[v].size(); i++)
	{
		int next = next_vertex[v][i];

		if (!check[next])
		{
			int distance_sum = distance + length[v][i];
			dfs(next, distance_sum);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	next_vertex.resize(n + 1);
	length.resize(n + 1);

	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		next_vertex[a].push_back(b);
		next_vertex[b].push_back(a);
		length[a].push_back(c);
		length[b].push_back(c);
	}

	dfs(1,0);
	memset(check, 0, sizeof(check));

	dfs(tail, 0);
	printf("%d", max_distance);	
}