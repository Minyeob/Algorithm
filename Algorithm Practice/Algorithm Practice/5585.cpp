#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int m = 1000 - n;

	int count = 0;
	count = m / 500;
	m = m % 500;
	count = count + m / 100;
	m = m % 100;
	count = count + m / 50;
	m = m % 50;
	count = count + m / 10;
	m = m % 10;
	count = count + m / 5;
	m = m % 5;
	count = count + m / 1;
	printf("%d", count);
}