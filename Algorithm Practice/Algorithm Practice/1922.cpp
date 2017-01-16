#include <cstdio>
#include <string.h>
int cost[1001][1001];
bool visit[1001];
int distance;

void prim(int now,int n)
{
	int min = 999999;
	int loc = 0;
	bool check = false;

	for (int i = 1; i <= n; i++)
	{
		cost[i][now] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (cost[now][i] != 0 && cost[now][i] < min && visit[i]==0)
		{
			min = cost[now][i];
			loc = i;
			printf("loc is %d min is %d\n",loc, min);
			check = true;
		}
	}

	if (check == false)
		return;

	distance = distance + min;
	printf("dis is %d\n", distance);
	visit[loc] = true;
	prim(loc, n);
}

int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c;
		cost[b][a] = c;
	}	
	visit[2] = true;
	prim(2, n);
	printf("%d", distance);
}