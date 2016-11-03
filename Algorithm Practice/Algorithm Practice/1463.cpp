#include <stdio.h>
#include <iostream>
using namespace std;
int array[1000000];

int main()
{
	array[0] = 0;
	array[1] = 0;
	array[2] = 1;
	array[3] = 1;

	int n;
	scanf("%d", &n);
	
	for (int i = 4; i <= n;i++)
	{
		if ((i % 3) == 0)
		{
			int z = i / 3;
			array[i] = 1 + array[z];
		}
		else if ((i % 2) == 0)
		{
			int q = i / 2;
			int count = 1 + array[q];
			int w = i - 1;
			int count2 = 1 + array[w];
			int e = i - 2;
			int count3 = 2 + array[e];
			
			int min = count;
			if (min > count2)
				min = count2;
			if (min > count3)
				min = count3;

			array[i] = min;
		}
		else
		{
			int w = i - 1;
			int count2 = 1 + array[w];
			int e = i - 2;
			int count3 = 2 + array[e];

			int min = count2;
			if (min > count3)
				min = count3;

			array[i] = min;
		}	
	}
	printf("%d", array[n]);
}