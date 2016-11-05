#include <stdio.h>
int array[10];
int main()
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &array[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		array[i] = array[i] % 42;
	}
	int count = 1;
	for (int i = 1; i < 10; i++)
	{
		int same = 0;
		for (int j = 0; j < i; j++)
		{
			if (array[i] == array[j])
			{
				same = 1;
				break;
			}
		}
		if (same != 1)
			count++;
	}

	printf("%d", count);
}