#include <cstdio>
#include <cmath>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int m;
	scanf("%d", &m);

	int sum = 0;
	for (int i = m-1; i >= 0; i--)
	{
		int temp;
		scanf("%d", &temp);
		int b = temp*pow(a, i);
		//printf("b is %d \n", b);
		sum = sum + b;
	}

	int c = b;
	while (c < sum)
	{
		c = c*b;
	}
	c = c / b;
	//printf("c is %d sum is %d a is %d\n", c,sum,a);

	while (c > 0)
	{
		int t = sum / c;
		printf("%d ", t);
		sum = sum%c;
		c = c / b;
	}
}