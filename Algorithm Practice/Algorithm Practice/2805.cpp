#include <cstdio>

int input[1000000];

int find(int n, int m)
{
	int min = 0;
	int max = 1000000000;
	int mid = (min + max) / 2;
	int final = 0;

	while (min <= max)
	{
		mid = (min + max) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if(input[i]>mid)
				sum += input[i] - mid;
			if (sum >= m)
				break;
		}
		if (sum >= m)
		{
			final = mid;
			min = mid + 1;
		}
		else
			max = mid-1;
		//printf("mid is %d sum is %d \n", mid,sum);
	}
	return final;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);
	int len = find(n, m);
	printf("%d", len);
}