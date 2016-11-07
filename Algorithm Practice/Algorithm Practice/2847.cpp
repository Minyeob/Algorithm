#include <stdio.h>

int array[100];
int main()
{
	int n;
	int count=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for (int i = n-1; i >= 0; i--)
	{
		int max = array[i];
		for (int j = 0; j < i; j++)
		{
			if (array[j] >= max)
			{
				count = count + (array[j] - (max - 1));
				array[j] = max - 1;
			}
		}
	}

	printf("%d", count);
}