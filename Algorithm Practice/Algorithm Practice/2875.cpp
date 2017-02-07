#include <cstdio>
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int max = 0;

	for (int i = 0; i <= k; i++)
	{
		int temp_n = n - i;
		int temp_m = m - (k - i);

		if (temp_n < 0 || temp_m < 0)
			continue;

		int count1 = temp_n / 2;
		int count2 = temp_m;
		
		int min = 0;
		if (count1 < count2)
			min = count1;
		else
			min = count2;
		//printf("min is %d\n",min);
		if (min > max)
			max = min;
	}

	printf("%d", max);
}