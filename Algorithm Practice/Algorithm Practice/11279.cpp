#include <cstdio>
#include <queue>
using namespace std;
int array[100001];
int array_loc;
queue<int> q;

void swap(int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void sort(int loc)
{
	while (1)
	{
		if (array[loc] > array[loc / 2] && loc>1)
		{
			swap(loc, loc / 2);
			loc = loc / 2;
		}
		else
			break;
	}
}

void push(int a)
{
	if (a > array[1])
	{
		array[array_loc] = array[1];
		array[1] = a;
	}
	else
		array[array_loc] = a;
	sort(array_loc);
	array_loc++;
}

void pop()
{
	if (array[1] == 0)
	{
		q.push(0);
		return;
	}
	q.push(array[1]);
	swap(array_loc - 1, 1);
	array[array_loc - 1] = 0;
	array_loc--;
	int loc = 1;
	while (loc<array_loc)
	{
		int left = 0;
		int right = 0;
		if (loc * 2<array_loc)
			left = loc * 2;
		if (loc * 2 + 1<array_loc)
			right = loc * 2 + 1;

		int big;
		if (array[left] > array[right])
			big = left;
		else
			big = right;
		if (array[big] > array[loc])
		{
			swap(big, loc);
			loc = big;
		}
		else
			break;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	array_loc = 1;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 0)
			pop();
		else
			push(a);
	}

	while (!q.empty())
	{
		printf("%d\n", q.front());
		q.pop();
	}
}