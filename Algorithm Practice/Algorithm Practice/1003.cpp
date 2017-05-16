#include <cstdio>

int count[41][2];
int main()
{
	int t;
	scanf("%d", &t);

	count[0][0] = 1;
	count[0][1] = 0;
	count[1][0] = 0;
	count[1][1] = 1;

	for (int i = 2; i < 41; i++)
	{
		count[i][0] = count[i - 1][0] + count[i - 2][0];
		count[i][1] = count[i - 1][1] + count[i - 2][1];
	}
	for (int i = 0; i < t; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d %d\n", count[a][0], count[a][1]);
	}
}