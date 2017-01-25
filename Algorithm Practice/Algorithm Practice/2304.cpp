#include <cstdio>

struct bar{
	int x;
	int y;

	bar(){};
	bar(const bar& temp)
	{
		x = temp.x;
		y = temp.y;
	}
	inline void operator=(const bar& temp)
	{
		x = temp.x;
		y = temp.y;
	}

	inline bool operator<(const bar& temp)
	{
		return x < temp.x;
	}
};
bar bar_array[1001];

void swap(int a, int b)
{
	bar temp = bar_array[a];
	bar_array[a] = bar_array[b];
	bar_array[b] = temp;
}

void quick(int start, int end)
{
	if (start >= end)
		return;
	bar pivot = bar_array[start];
	int loc = start;
	swap(loc, end);
	for (int i = start; i < end; i++)
	{
		if (bar_array[i] < pivot)
		{
			swap(loc, i);
			loc++;
		}
	}
	swap(loc, end);

	quick(start, loc - 1);
	quick(loc + 1, end);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		bar temp;
		temp.x = a;
		temp.y = b;
		bar_array[i] = temp;
	}
	quick(0, n - 1);

	int max_y = 0;
	int max_loc = 0;
	for (int i = 0; i < n; i++)
	{
		if (bar_array[i].y > max_y)
		{
			max_y = bar_array[i].y;
			max_loc = i;
		}
	}

	int left = 0;
	int sum = 0;
	for (int i = 1; i <= max_loc; i++)
	{
		if (bar_array[i].y >= bar_array[left].y)
		{
			int y = bar_array[left].y;
			int x = bar_array[i].x - bar_array[left].x;
			int size = x*y;
			//printf("size is %d\n", size);
			sum = sum + size;
			left = i;
		}
	}

	//max length sum
	sum = sum + max_y;
	//printf("sum is %d\n", sum);
	
	int right = n - 1;
	for (int i = n-2; i >= max_loc; i--)
	{
		if (bar_array[i].y >= bar_array[right].y)
		{
			int y = bar_array[right].y;
			int x = (bar_array[right].x + 1) - (bar_array[i].x + 1);
			int size = x*y;
			//printf("x is %d y is %d size is %d\n", x,y,size);
			sum = sum + size;
			right = i;
		}
	}

	printf("%d", sum);
}