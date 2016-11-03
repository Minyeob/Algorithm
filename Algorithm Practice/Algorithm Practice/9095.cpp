#include <stdio.h>

int array[12];

int main()
{
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 4;

	for (int i = 4; i < 11; i++)
	{
		for (int j = i; j > 0; j--)
		{
			array[i] = array[i] + array[j];
		}
	}

	for(int i = 0; i < 11; i++)
	{
		printf("%d is %d \n", i,array[i]);
	}

	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", array[n]);
	}
}