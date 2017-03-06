#include <cstdio>

int input[1001];
int sum[1001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < n; i++)
	{
		sum[i] = input[i];
		for (int j = 0; j < i; j++)
		{
			if (input[j]<input[i] && sum[j] + input[i]>sum[i])
			{
				sum[i] = sum[j] + input[i];
			}
		}
	}

	int final = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum[i] > final)
			final = sum[i];
	}
	printf("%d", final);
}