#include <cstdio>

typedef struct point{
	int x, y;

	point(){
		//그냥 만들때 기본값을 지정해 줄 수 있다
		x = 5;
		y = 1;
	}

	point(const point& opposite)
	{
		x = opposite.x;
		y = opposite.y;
	}

	void operator=(const point& opposite)
	{
		x = opposite.x;
		y = opposite.y;
	}
};

point array[100005];
int arr[100];

bool compare(point a, point pivot)
{
	if (a.x < pivot.x)
		return true;
	else if (a.x == pivot.x)
	{
		if (a.y < pivot.y)
			return true;
	}
	return false;
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quick(int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[start];
	int loc = start;
	int pivotloc = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i]< pivot)
		{
			swap(arr[i], arr[loc]);
			pivotloc = i;
			loc++;
		}
	}
	swap(arr[loc], arr[pivotloc]);

	quick(start, loc - 1);
	quick(loc + 1, end);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	quick(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

}