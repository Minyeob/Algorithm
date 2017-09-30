#include <iostream>
#include <cstdio>
using namespace std;
int check[11][11];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int r, c1, c2;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &r, &c1, &c2);
		for (int j = c1; j <= c2; j++)
			check[r][j] = 1;
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (check[i][j] == 0)
				result++;
		}
	}
	printf("%d", result);

	return 0;
}