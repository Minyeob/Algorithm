#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	if (n < 3)
	{
		printf("0");
		return 0;
	}

	int sum = 0;
	int start = n / 2;
	int end = n / 3;
	for (int i = start; i >= end; i--)
	{
		for (int j = i; j > n / 4; j--)
		{
			int k = n - i - j;
			if (k == 0)
				continue;
			if (i < j)
				continue;
			if (j < k)
				continue;
			if (i < k)
				continue;
			if (i >= j + k)
				continue;
			sum = sum + 1;
		}
	}

	printf("%d", sum);
}