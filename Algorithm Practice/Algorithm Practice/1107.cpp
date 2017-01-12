#include <cstdio>
#include <math.h>

int check[20];
int num[70];

int save(int n)
{
	int count=0;
	while (n != 0)
	{
		int temp = n % 10;
		num[count] = temp;
		count++;
		n = n / 10;
	}
	return count;
}

int load(int size)
{
	int n=0;
	for (int i = 0; i < size; i++)
	{
		n = n * 10 + check[i];
	}
	return n;
}

int find_minus(int n, int count)
{
	int final=count;
	int correct=0;
	int size=save(n);
	printf("n is %d\n",n);
	for (int i = 0; i < size; i++)
	{
		if (check[num[i]])
		{
			correct = 1;
			int j = size - 1;
			while (j>=0)
			final=find_minus(n - 1, count + pow(10*1.0,(size-1-i)));
		}
	}
	if (correct == 0)
	{
		return count;
	}
	else
		return final;
}

int find_plus(int n, int count)
{
	int final = count;
	int correct = 0;
	int size=save(n);
	for (int i = 0; i < size; i++)
	{
		if (check[num[i]])
		{
			correct = 1;
			final = find_plus(n + 1, count + 1);
		}
	}
	if (correct == 0)
	{
		return count;
	}
	else
		return final;
}

int find_100(int n)
{
	int count = 0;
	if (n > 100)
		count = n - 100;
	else if (n == 100)
		count = 0;
	else
		count = 100 - n;
	return count;
}

int main()
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		check[a] = 1;
	}

	int count = 0;
	count = save(n);
	int final1 = count;
	int final2 = count;
	int final3 = 0;
	
	final1 = find_minus(n, count);
	final2 = find_plus(n, count);
	final3 = find_100(n);

	int small = 0;
	if (final1 < final2)
		small = final1;
	else
		small = final2;

	if (small > final3)
		small = final3;

	printf("%d", small);
}