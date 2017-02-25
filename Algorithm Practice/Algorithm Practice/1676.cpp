#include <cstdio>

int score[10];

int fac(int n)
{
	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		int num = i;
		int div2 = num % 2;
		if (div2 == 0)
		{
			while (div2 == 0)
			{
				score[2]++;
				num = num / 2;
				div2 = num % 2;
			}
		}
		int div5 = num % 5;
		if (div5 == 0)
		{
			while (div5 == 0)
			{
				score[5]++;
				num = num / 5;
				div5 = num % 5;
			}
		}
	}
	int min = score[2];
	if (min > score[5])
		min = score[5];

	return min;
}

int main()
{
	int n;
	scanf("%d", &n);
	int count=fac(n);
	
	printf("%d", count);
}