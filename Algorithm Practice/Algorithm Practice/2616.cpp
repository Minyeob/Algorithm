#include <cstdio>

int people[50001];
int sum[50001];
int maxsum;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &people[i]);
	}
	int capable;
	scanf("%d", &capable);
	
	for (int i = 0; i <= n - capable; i++)
	{
		int temp = 0;
		if (i + capable <= n)
		{
			for (int j = i; j < capable; j++)
			{
				temp = temp + people[j];
			}
			sum[i] = temp;
		}
	}

	int result = 0;
	int max = 0;
	int maxloc = 0;
	int secondloc = 0;
	for (int i = 0; i <= n - capable; i++)
	{
		max = sum[i];
		maxloc = i;

		result = result + max;
		max = 0;
		for (int i = 0; i <= n - capable; i++)
		{
			if (i <= maxloc - capable && i >= maxloc + capable)
			{
				if (sum[i] > max)
				{
					max = sum[i];
					secondloc = i;
				}
			}
		}
		result = result + max;
		max = 0;
		for (int i = 0; i <= n - capable; i++)
		{
			if (i <= maxloc - capable && i >= maxloc + capable && i <= secondloc - capable && i >= secondloc + capable)
			{
				if (sum[i] > max)
				{
					max = sum[i];
				}
			}
		}
		result = result + max;
		sum[maxloc] = 0;
		if (result > maxsum)
			maxsum = result;
	}
}