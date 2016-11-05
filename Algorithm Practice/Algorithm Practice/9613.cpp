#include <stdio.h>

int array[1000000];

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int r = a%b;
	a = b;
	b = r;
	return gcd(a, b);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int n2;
		scanf("%d", &n2);
		int sum = 0;
		for (int j = 0; j < n2; j++)
		{
			scanf("%d", &array[j]);
		}

		for (int j = 0; j < n2; j++)
		{
			for (int q = j+1; q < n2; q++)
				sum=sum+gcd(array[j], array[q]);
		}
		printf("%d\n", sum);
	}
}