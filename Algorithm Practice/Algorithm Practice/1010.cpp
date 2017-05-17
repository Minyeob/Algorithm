#include <cstdio>

int result[31][31];

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i < 31; i++)
		result[1][i] = i;
	for (int i = 2; i < 31; i++)
	{
		result[i][i] = 1;
		for (int j = i + 1; j < 31; j++)
			result[i][j] = result[i][j - 1] + result[i - 1][j - 1];
	}

	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", result[n][m]);
	}
}