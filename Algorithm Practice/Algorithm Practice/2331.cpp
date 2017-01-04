#include <cstdio>
#include <math.h>

int check[300000];

int calculate(int num, int p)
{
	int sum = 0;
	while (num > 0)
	{
		int a = num % 10;
		int b = pow(a*1.0, p);
		sum = sum + b;
		num = num/10;
	}
	return sum;
}

int main()
{
	int a, p;
	scanf("%d %d", &a, &p);
	check[a]++;

	while (1)
	{
		int next = calculate(a, p);
		check[next]++;
		if (check[next] > 2)
			break;
		a = next;
	}

	int count = 0;
	for (int i = 0; i < 300000; i++)
	{
		if (check[i] == 1)
			count++;
	}
	printf("%d", count);

	return 0;
}