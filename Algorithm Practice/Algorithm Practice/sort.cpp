#include <stdio.h>
#include <iostream>

void sort(int array[],int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = array[i];
		int location = i;
		for (int j = i+1; j < n; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				location = j;
			}
		}
		int swap = array[i];
		array[i] = array[location];
		array[location] = swap;
	}
}
int main(){
	int array[5] = { 5, 7, 1, 3, 6 };
	printf("initial value is %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
	sort(array,5);
	printf("final value is %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
}

