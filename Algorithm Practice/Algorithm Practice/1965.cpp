#include <cstdio>

int input[1001];
int count[1001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &input[i]);

	for (int i = 1; i <= n; i++)
	{
		count[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (input[j]<input[i] && count[j] + 1>count[i])
				count[i] = count[j] + 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (count[i] > max)
			max = count[i];
	}
	printf("%d", max);
}