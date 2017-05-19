#include <cstdio>

int cost[100001];

int main()
{
	int n;
	scanf("%d", &n);

	cost[0] = 1;
	cost[1] = 3;

	for (int i = 2; i <= n; i++)
	{
		cost[i] = (cost[i - 1] + cost[i - 2] * 2 + cost[i - 1] - cost[i - 2]) % 9901;
	}
	printf("%d", cost[n]);
}