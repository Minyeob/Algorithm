#include <stdio.h>
#include <iostream>
using namespace std;
int array[1001][10];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		array[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				array[i][j] = array[i - 1][j];
			else
			{
				for (int q = 0; q <= j; q++)
				{
					array[i][j] = array[i][j] + array[i - 1][q];
				}
			}
		}
	}

	long long int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + array[n][i];
	}
	sum = sum % 10007;
	printf("%d", (int)sum);
}