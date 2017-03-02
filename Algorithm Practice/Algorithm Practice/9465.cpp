#include <cstdio>

int arr[2][100001];
int point[2][100001];

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[0][j]);
		}
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[1][j]);
		}

		point[0][1] = arr[0][1];
		point[1][1] = arr[1][1];

		for (int k = 2; k <= n; k++)
		{
			int up = point[0][k-1];
			int down = point[1][k - 1];
			int up_now = down + arr[0][k];
			int down_now = up + arr[1][k];
			
			if (up < up_now)
				point[0][k] = up_now;
			else
				point[0][k] = up;
			if (down < down_now)
				point[1][k] = down_now;
			else
				point[1][k] = down;
		}
		int final = point[0][n];
		if (final < point[1][n])
			final = point[1][n];
		printf("%d\n", final);
	}
}