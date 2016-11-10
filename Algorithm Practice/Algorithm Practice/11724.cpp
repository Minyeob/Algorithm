#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<vector<int>> point;
int start[1001];
int check[1001];

void dfs(int start)
{
	for (int i = 0; i < point[start].size(); i++)
	{
		int next = point[start][i];
		if (!check[next])
		{
			check[next] = 1;
			dfs(next);
		}
	}
}

int main()
{
	int node, edge;
	scanf("%d %d", &node, &edge);
	int count = 0;
	point.resize(node + 1);

	for (int i = 0; i < edge; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		point[a].push_back(b);
		point[b].push_back(a);
	}

	for (int i = 1; i < node+1; i++)
	{
		if (!check[i])
		{
			check[i] = 1;
			count++;
			dfs(i);
		}
	}

	printf("%d", count);

	return 0;
}