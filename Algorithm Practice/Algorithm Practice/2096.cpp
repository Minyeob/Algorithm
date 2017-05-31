#include <cstdio>

int input[100001][3];
int min[100001][3];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &input[i][j]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int now = input[i][j];
			if (j - 1 >= 0)
			{
				min[i][j] = min[i - 1][j - 1] + now;
				input[i][j] = input[i - 1][j - 1] + now;
			}
			if (min[i][j] == 0)
				min[i][j] = min[i - 1][j] + now;
			else if(min[i-1][j]+ now<min[i][j])
				min[i][j] = min[i - 1][j] + now;
			if (input[i][j] == 0)
				input[i][j] = input[i - 1][j] + now;
			else if (input[i - 1][j] + now>input[i][j])
				input[i][j] = input[i - 1][j] + now;
			if (j + 1 < 3)
			{
				if (min[i - 1][j + 1] + now < min[i][j])
					min[i][j] = min[i - 1][j + 1] + now;
				if (input[i - 1][j + 1] + now > input[i][j])
					input[i][j] = input[i - 1][j + 1] + now;
			}
		}
	}

	int big = 0;
	int small = 0;
	if (input[n][0] < input[n][1])
		big = input[n][1];
	else
		big = input[n][0];
	if (big < input[n][2])
		big = input[n][2];
	printf("%d ", big);
	if (min[n][0] < min[n][1])
		small = min[n][0];
	else
		small = min[n][1];
	if (small > min[n][2])
		small = min[n][2];
	printf("%d", small);
}