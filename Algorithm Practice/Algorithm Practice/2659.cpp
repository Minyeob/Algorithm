#include <cstdio>
int array[10000];
int number[4];
int result[4];
bool check[10000];

void quick(int start, int end)
{
	if (start >= end)
		return;
	int loc = start;
	int pivot = result[start];
	//printf("pivot is %d\n", pivot);
	result[start] = result[end];
	result[end] = pivot;
	for (int i = start; i < end; i++)
	{
		if (result[i] < pivot)
		{
			int temp = result[loc];
			result[loc] = result[i];
			result[i] = temp;
			loc++;
		}
	}

	//printf("loc is %d and %d and pivot is %d\n", loc,number[loc],pivot);
	result[end] = result[loc];
	result[loc] = pivot;

	quick(start, loc - 1);
	quick(loc + 1, end);
}

int main()
{
	int loc = 1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int t = 1; t <= 9; t++)
				{
					number[0] = i;
					number[1] = j;
					number[2] = k;
					number[3] = t;
					result[0] = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
					result[1] = (number[1] * 1000) + (number[2] * 100) + (number[3] * 10) + number[0];
					result[2] = (number[2] * 1000) + (number[3] * 100) + (number[0] * 10) + number[1];
					result[3] = (number[3] * 1000) + (number[0] * 100) + (number[1] * 10) + number[2];
					quick(0, 3);
					check[result[0]] = true;
				}
			}
		}
	}

	for (int i = 1111; i <= 9999; i++)
	{
		if (check[i] == true)
		{
			array[loc] = i;
			loc++;
		}
	}

	/*for (int i = 1; i < loc; i++)
	{
		printf("%d ¹øÂ° %d\n", i, array[i]);
	}*/
	scanf("%d %d %d %d", &number[0], &number[1] , &number[2], &number[3]);
	//printf("%d %d %d %d\n", number[0], number[1], number[2], number[3]);
	//printf("%d %d %d %d\n", number[0], number[1], number[2], number[3]);
	result[0] = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
	result[1] = (number[1] * 1000) + (number[2] * 100) + (number[3] * 10) + number[0];
	result[2] = (number[2] * 1000) + (number[3] * 100) + (number[0] * 10) + number[1];
	result[3] = (number[3] * 1000) + (number[0] * 100) + (number[1] * 10) + number[2];
	quick(0, 3);
	//printf("num is %d\n", result[0]);

	for (int i = 1; i < loc; i++)
	{
		if (array[i] == result[0])
		{
			printf("%d", i);
			return 0;
		}
	}
}