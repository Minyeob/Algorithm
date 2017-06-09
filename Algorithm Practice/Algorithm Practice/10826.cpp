#include <cstdio>

int fibo[10001][3000];

int main()
{
	int n;
	scanf("%d", &n);

	fibo[1][0] = 1;
	int len = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			fibo[i][j] += fibo[i - 1][j] + fibo[i - 2][j];
			//printf("fibo[%d][%d] + fibo[%d][%d] is %d\n", i - 1, j, i - 2, j, fibo[i][j]);
			if (fibo[i][j] >= 10)
			{
				int rem = fibo[i][j] % 10;
				int div = fibo[i][j] / 10;
				fibo[i][j] = rem;
				fibo[i][j + 1] += div;
				if (j == len)
				{
					len += 1;
					break;
				}
			}
		}
	}
	
	for (int i = len; i >= 0; i--)
		printf("%d", fibo[n][i]);
}