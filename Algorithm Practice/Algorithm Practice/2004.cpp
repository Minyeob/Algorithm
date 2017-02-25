#include <cstdio>

int score[10];

int fac(int n,int length)
{
	int count = 0;
	for (int i = n; i > length; i--)
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
	int n1,n2;
	scanf("%d %d", &n1,&n2);
	int count1 = 0;
	if (n2 == 0)
		count1 = fac(n1, 0);
	else
		count1 = fac(n1,n1-n2);
	score[2] = 0;
	score[5] = 0;
	int count2 = fac(n2,0);
	printf("%d %d\n", count1, count2);
	int count = count1 - count2;

	printf("%d", count);
}