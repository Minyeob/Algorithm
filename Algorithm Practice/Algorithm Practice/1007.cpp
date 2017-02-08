#include <cstdio>

struct point{
	int x;
	int y;
};

point p[20];
point dist[20][20];

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		for (int j = 0; j < n; j++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				dist[j][k].x = p[k].x - p[j].x;
				dist[j][k].y = p[k].y - p[k].y;
			}
		}
	}
}