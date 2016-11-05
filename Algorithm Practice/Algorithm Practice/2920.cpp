#include <stdio.h>
int array[8];

int main()
{
	for (int i = 0; i < 8; i++)
		scanf("%d", &array[i]);

	if (array[0] == 1)
	{
		int asc = 0;
		for (int i = 1; i < 8; i++)
		{
			if (array[i] == i + 1)
				;
			else
			{
				asc = 1;
				break;
			}
		}
		if (asc == 0)
			printf("ascending");
		else
			printf("mixed");
	}

	else if (array[0] == 8)
	{
		int dsc = 0;
		for (int i = 1; i < 8; i++)
		{
			if (array[i] == 8 - i)
				;
			else
			{
				dsc = 1;
				break;
			}
		}
		if (dsc == 0)
			printf("descending");
		else
			printf("mixed");
	}

	else
		printf("mixed");
}