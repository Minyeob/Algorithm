#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	while (a != 0 && b != 0)
	{
		int temp = a + b;
		printf("%d\n", temp);
		scanf("%d %d", &a, &b);
	}

	return 0;
}