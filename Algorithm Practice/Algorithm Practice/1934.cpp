#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int r = a%b;
	a = b;
	b = r;
	gcd(a, b);
}

int lcm(int a, int b)
{
	int c = a / gcd(a, b);
	int d = b / gcd(a, b);
	return gcd(a, b)*c*d;
}

int main()
{
	int number;
	int a, b;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
}