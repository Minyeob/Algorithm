#include <cstdio>
#include <algorithm>
using namespace std;

int x[4];
int y[4];
int dist[4][4];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
		}

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x_dist = (x[j] - x[k])*(x[j] - x[k]);
				int y_dist = (y[j] - y[k])*(y[j] - y[k]);
				dist[j][k] = x_dist + y_dist;
			}
			sort(dist[j], dist[j] + 4);
		}
		bool check = true;
		for (int j = 0; j < 4; j++)
		{
			if (dist[j][1] == dist[j][2] && dist[j][1] * 2 == dist[j][3]);
			else
				check = false;
		}
		if (check == true)
			printf("1\n");
		else
			printf("0\n");
	}
}