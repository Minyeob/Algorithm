#include <cstdio>

int result[31];

int main()
{
	int n;
	scanf("%d", &n);

	result[1] = 0;
	result[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 1)
			continue;
		else
		{
			
		}
	}
	printf("%d", result[n]);
}