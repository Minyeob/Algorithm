#include <cstdio>

int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int x_dist = (x2 - x1)*(x2 - x1);
		int y_dist = (y2 - y1)*(y2 - y1);
		int r_dist = (r2 + r1)*(r2 + r1);
		int r_minus = (r2 - r1)*(r2 - r1);
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else
		{
			if (x_dist + y_dist < r_dist)
			{
				if (x_dist + y_dist > r_minus)
					printf("2\n");
				else if (x_dist + y_dist == r_minus)
					printf("1\n");
				else
					printf("0\n");
			}
			else if (x_dist + y_dist == r_dist)
				printf("1\n");
			else
				printf("0\n");
		}

	}
}