#include <cstdio>

int call[16][2];
int max[16];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &call[i][0], &call[i][1]);

	for (int i = 1; i <= n; i++)
	{
		int end = i + call[i][0];
		for (int j = 2; j<i; j++)
		{
			if (max[j]>max[i])
				max[i] = max[j];
		}
		int sum = max[i] + call[i][1];

		if (sum>max[end])
			max[end] = sum;
	}

	int final = 0;
	for (int i = 2; i <= n + 1; i++)
	{
		if (max[i]>final)
			final = max[i];
	}
	printf("%d", final);
}