#include <cstdio>
#include <algorithm>

int people[1001];
int sum[1001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &people[i]);
	}

	std::sort(people, people + n);

	sum[0] = people[0];

	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + people[i];
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		max = max + sum[i];
	}

	printf("%d", max);
}