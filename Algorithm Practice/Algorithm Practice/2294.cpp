#include <cstdio>

int coin[201];
int num[1000001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		num[coin[i]] = 1;
		//printf("coin is %d \n", coin[i]);
		for (int j = coin[i]; j <= k; j++)
		{
			if (num[j] == 0)
			{
				if (num[j - coin[i]] > 0)
				{
					num[j] = num[j - coin[i]] + 1;
					//printf("num[%d] is %d +1 \n", j, num[j - coin[i]]);
				}
			}
			else
			{
				if (num[j] > num[j - coin[i]] + 1 && num[j-coin[i]]>0)
					num[j] = num[j - coin[i]] + 1;
			}
		}
	}
	if (num[k] == 0)
		printf("-1");
	else
		printf("%d", num[k]);
}