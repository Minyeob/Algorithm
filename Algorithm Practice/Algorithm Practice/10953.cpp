#include <cstdio>

char s[10];

int main()
{
	int n;
	scanf("%d", &n);

	int a, b;
	char c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%c%d", &a, &c, &b);
		printf("%d\n", a + b);
	}

	return 0;

}