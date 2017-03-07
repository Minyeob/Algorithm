#include <cstdio>

int input[1001];
int size[1001];
int down[1001];

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
		size[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[j]<input[i] && size[j] + 1>size[i])
				size[i] = size[j] + 1;
		}
	}

	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j > i; j--)
		{
			if (input[j]<input[i] && down[j] + 1>down[i])
				down[i] = down[j] + 1;
		}
	}

	int final = 0;
	for (int i = 0; i < n; i++)
	{
		int total = size[i] + down[i];
		if (total > final)
			final = total;
	}
	printf("%d", final);
}