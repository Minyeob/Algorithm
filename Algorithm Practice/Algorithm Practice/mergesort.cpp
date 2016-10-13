#include <iostream>
#include <stdio.h>
using namespace std;
int length = 4;
int array[4];
int b[4];
int k = 0;

void comp(int aa, int bb);

void merge(int start, int end)
{
	int mid = (start + end) / 2;

	if (start==mid)
		comp(start, end);

	else
	{
		merge(start, mid);
		merge(mid + 1, end);
	}

}

void comp(int start, int end)
{
	while (1)
	{
		int mid = (start + end) / 2;
		int i = start;
		int j = mid + 1;

		printf("initial i is %d, j is %d\n", i, j);

		if (array[i] > array[j])
		{
			b[k] = array[j];
			j++;
			printf("j is %d\n", j);
			printf("bk is %d\n",b[k]);
		}
		else
		{
			b[k] = array[i];
			i++;
			printf("i is %d\n", i);
			printf("bk is %d\n", b[k]);
		}
		k++;

		if (i == mid + 1)
		{
			
			for (int q = j; q < end + 1; q++)
			{
				b[k] = array[j];
				j++;
				k++;
				printf("j is %d, k is %d, value is %d\n", j-1,k-1, b[k-1]);
			}
			break;
		}

		else if (j == end)
		{
			for (int w = i; w < mid + 1; w++)
			{
				b[k] = array[i];
				i++;
				k++;
				printf("j is %d, k is %d, value is %d\n", i - 1, k - 1, b[k - 1]);
			}
			break;
		}
	}
}

void copy()
{
	for (int i = 0; i < length; i++)
		array[i] = b[i];
}
int main()
{
	array[0] = 4;
	array[1] = 7;
	array[2] = 2;
	array[3] = 3;
	merge(0, 3);
	copy();

	printf("sorted value is %d %d %d %d \n", array[0], array[1], array[2], array[3]);
	return 0;
}