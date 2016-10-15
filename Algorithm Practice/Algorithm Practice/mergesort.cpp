#include <iostream>
#include <stdio.h>
using namespace std;
int length = 4;
int a[4];
int b[4];

void merge(int start, int end)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;

	merge(start, mid);
	merge(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int q = 0;

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			b[q] = a[i];
			++i;
		}

		else
		{
			b[q] = a[j];
			++j;
		}
		q++;
	}

	while (i <= mid)
	{
		b[q] = a[i];
		i++;
		q++;
	}

	while (j <= end)
	{
		b[q] = a[j];
		j++;
		q++;
	}

	for (int i = start; i <= end; i++)
	{
		a[i] = b[i - start];
	}
}