#include <stdio.h>
#include <algorithm>
using namespace std;
int array[1000];
int diff[1000];
int main()
{
	int number;
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
		scanf("%d", &array[i]);
	int loc = 0;
	for (int i = 0; i < number-1; i++)
	{
		if (array[i] < array[i + 1])
		{
			diff[loc] = diff[loc] + (array[i + 1] - array[i]);
		}
		else
		{
			loc++;
		}
	}
	int maxdiff = 0;
	for (int i = 0; i <= loc; i++)
	{
		maxdiff = max(maxdiff, diff[i]);
	}

	printf("%d", maxdiff);
}