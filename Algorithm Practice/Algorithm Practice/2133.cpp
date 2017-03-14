#include <cstdio>

int result[31];

int main()
{
	int n;
	scanf("%d", &n);

	result[0] = 1;
	result[2] = 3;
	for (int i = 4; i <= n; i = i + 2)
	{
		result[i] = result[i - 2] * 3;
		for (int j = 4; i - j >= 0; j = j + 2)
			result[i] = result[i] + result[i - j] * 2;
	}
	printf("%d", result[n]);
}