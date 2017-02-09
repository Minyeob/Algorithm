#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	if (n >= 3 && m >= 7)
	{
		printf("%d", m - 2);
		return 0;
	}
	else if (n == 1)
	{
		printf("1");
		return 0;
	}
	else if (n == 2 && m<9)
	{
		printf("%d", (m-1) / 2+1);
		return 0;
	}
	else if (m <= 4)
	{
		printf("%d", m);
		return 0;
	}
	else
		printf("4");
}