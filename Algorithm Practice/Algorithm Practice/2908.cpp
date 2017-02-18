#include <cstdio>
#include <cmath>

char a[100];
char b[100];

int main()
{
	scanf("%s %s", a, b);
	int c = 0;
	int d=0;
	int n = 0;
	while (a[n] != '\0')
	{
		c = c +(a[n]-'0')*pow(10,n);
		d = d + (b[n]-'0')*pow(10,n);
		//printf("%d %d\n", c, d);
		n++;
	}
	int max = c;
	if (c < d)
		max = d;
	printf("%d", max);
}
