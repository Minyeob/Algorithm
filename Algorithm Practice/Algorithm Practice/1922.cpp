#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
int cost[1001][1001];
bool visit[1001];
int sum;
int edge_count;
int final_sum;

void prim(int n)
{
	visit[1] = true;
	for (int k = 1; k < n; k++)
	{		
		int distance = 0;
		int loc = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == true)
			{
				for (int j = 1; j <= n; j++)
				{
					if (visit[j] == false && cost[i][j] != 0)
					{
						//printf("from %d to %d is false and cost is %d \n", i,j, cost[i][j]);
						if (distance == 0)
						{
							distance = cost[i][j];
							loc = j;
						}
						else if (cost[i][j] < distance)
						{
							distance = cost[i][j];
							loc = j;
						}
					}
				}
			}	
		}
		sum = sum + distance;
		visit[loc] = true;
		//printf("distance is %d and sum is %d\n", distance, sum);
	}
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

	prim(n);
	printf("%d", sum);
}