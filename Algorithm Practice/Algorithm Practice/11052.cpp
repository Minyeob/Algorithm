#include <cstdio>

int value[1001];
int input[1001];
int max;

void find_value(int n)
{
	value[1] = input[1];
	for (int i = 2; i <= n; i++)
	{
		value[i] = input[i];
		for (int j = i-1; j >= i / 2; j--)
		{
			if (value[i] < value[j] + value[i - j])
				value[i] = value[j] + value[i - j];
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]);
	}

	find_value(n);
	printf("%d", value[n]);
}