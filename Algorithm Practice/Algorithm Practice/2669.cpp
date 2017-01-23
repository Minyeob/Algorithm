#include <cstdio>

bool point[101][101];

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int x, y, next_x, next_y;
		scanf("%d %d %d %d", &x, &y, &next_x, &next_y);

		for (int i = x; i < next_x; i++)
		{
			for (int j = y; j < next_y; j++)
			{
				point[i][j] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (point[i][j] == 1)
				sum = sum + 1;
		}
	}

	printf("%d", sum);
}