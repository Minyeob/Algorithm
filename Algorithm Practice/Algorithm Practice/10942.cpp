#include <cstdio>
int input[2001];
bool result[2001][2001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]);
		result[i][i] = true;
	}
	
	for (int i = 1; i < n; i++)
	{
		if (input[i] == input[i + 1])
			result[i][i + 1] = true;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j + i > n)
				break;
			if (input[j] == input[i + j] && result[j + 1][j + i - 1])
				result[j][j + i] = true;
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d",&s,&e);
		printf("%d\n", result[s][e]);
	}
}