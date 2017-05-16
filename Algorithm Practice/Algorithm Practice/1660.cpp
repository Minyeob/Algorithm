#include <cstdio>

int num[1001];
int sum[1001];
int count[300001];

int main()
{
	int n;
	scanf("%d", &n);

	num[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		num[i] = num[i - 1] + i;
	}
	
	sum[1] = 1;
	int loc = 0;
	for (int i = 2; i < 1001; i++)
	{
		sum[i] = sum[i - 1] + num[i];
		if (sum[i] > n)
		{
			loc = i - 1;
			break;
		}
	}


	for (int i = 1; i <= loc; i++)
	{
		count[sum[i]] = 1;
		for (int j = sum[i]; j <= n; j++)
		{
			if (count[j] == 0)
			{
				if (count[j - sum[i]] > 0)
					count[j] = count[j - sum[i]] + 1;
			}
			else
			{
				if (count[j] > count[j - sum[i]] + 1 && count[j - sum[i]] > 0)
					count[j] = count[j - sum[i]] + 1;
			}
		}
	}

	printf("%d", count[n]);
}