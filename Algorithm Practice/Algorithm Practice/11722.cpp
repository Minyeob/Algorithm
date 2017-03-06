#include <cstdio>

int input[1000];
int length[1000];

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
		length[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[j] > input[i] && length[j] + 1 > length[i])
			{
				length[i] = length[j] + 1;
			}
		}
	}

	int final = 0;
	for (int i = 0; i < n; i++)
	{
		if (final < length[i])
			final = length[i];
	}
	printf("%d", final);
}