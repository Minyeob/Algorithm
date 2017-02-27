#include <cstdio>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int min = 0;
	int sum = 0;
	int loc = 0;
	for (int i = 1; i <= 100; i++)
	{
		int t = i*i;
		if (t >= m)
		{
			min = t;
			sum = t;
			loc = i;
			break;
		}
	}
	if (loc == 0 || min>n)
	{
		printf("-1");
		return 0;
	}

	for (int i =loc+1; i <= 100; i++)
	{
		int t = i*i;
		if (t > n)
			break;
		else
			sum = sum + t;
	}

	printf("%d \n%d", sum, min);
}