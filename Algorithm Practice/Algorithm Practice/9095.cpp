#include <cstdio>

int result[12];

int main()
{
	int t;
	scanf("%d", &t);
	
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		result[i] = result[i - 1] + result[i - 2] + result[i - 3];
	}
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", result[n]);
	}
}