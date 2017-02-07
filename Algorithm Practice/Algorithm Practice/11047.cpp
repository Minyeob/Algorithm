#include <cstdio>

int coin[10];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	int max = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (coin[i] <= k)
		{
			max = i;
			break;
		}
	}

	int count = 0;
	while (k != 0)
	{
		count = count + (k / coin[max]);
		k = k%coin[max];
		max = max - 1;
	}

	printf("%d", count);
}