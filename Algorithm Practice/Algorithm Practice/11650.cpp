#include <iostream>
#include <stdio.h>
using namespace std;
struct point
{
	int x, y;
};
point a[100000];
point b[100000];
point c[100000];
int location = 0;

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
		if (a[i].x < a[j].x)
		{
			b[q].x = a[i].x;
			b[q].y = a[i].y;
			++i;
		}

		else
		{
			b[q].x = a[j].x;
			b[q].y = a[j].y;
			++j;
		}
		q++;
	}

	while (i <= mid)
	{
		b[q].x = a[i].x;
		b[q].y = a[i].y;
		i++;
		q++;
	}

	while (j <= end)
	{
		b[q].x = a[j].x;
		b[q].y = a[j].y;
		j++;
		q++;
	}

	for (int i = start; i <= end; i++)
	{
		a[i].x = b[i - start].x;
		a[i].y = b[i - start].y;
	}
}

void merge_b(int start, int end)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;

	merge_b(start, mid);
	merge_b(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int q = 0;

	while (i <= mid && j <= end)
	{
		if (b[i].y < b[j].y)
		{
			c[q].x = b[i].x;
			c[q].y = b[i].y;
			++i;
		}

		else
		{
			c[q].x = b[j].x;
			c[q].y = b[j].y;
			++j;
		}
		q++;
	}

	while (i <= mid)
	{
		c[q].x = b[i].x;
		c[q].y = b[i].y;
		i++;
		q++;
	}

	while (j <= end)
	{
		c[q].x = b[j].x;
		c[q].y = b[j].y;
		j++;
		q++;
	}

	for (int i = start; i <= end; i++)
	{
		b[i].x = c[i - start].x;
		b[i].y = c[i - start].y;
	}
}

void merge_y(int start, int end)
{	
	while (location <= end)
	{
		int k = 0;
		b[k].x = a[location].x;
		b[k].y = a[location].y;
		start = location;
		k++;

		for (int i = location + 1; i < 1000000; i++)
		{
			if (a[location].x == a[i].x)
			{
				b[k].x = a[i].x;
				b[k].y = a[i].y;
				k++;
			}
			else
			{
				location = i;
				break;
			}
		}

		merge_b(0, k - 1);
		for (int i = start; i < start+k; i++)
		{
			a[i].x = b[i - start].x;
			a[i].y = b[i - start].y;
		}
	}
}



int main()
{
	
	int number;
	scanf("%d", &number);
	
	for (int i = 0; i < number; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
	}

	merge(0, number - 1);
	merge_y(0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d %d\n", a[i].x, a[i].y);
	}



	return 0;
}