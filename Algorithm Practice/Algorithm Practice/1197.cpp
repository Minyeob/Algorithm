#include <cstdio>
int parent[1005];
struct edge{
	int start;
	int end;
	int cost;

	edge(){};
	edge(const edge& temp)
	{
		this->start = temp.start;
		this->end = temp.end;
		this->cost = temp.cost;
	}

	void operator=(const edge& temp)
	{
		this->start = temp.start;
		this->end = temp.end;
		this->cost = temp.cost;
	}

	bool operator<(const edge& temp)
	{
		if (cost <= temp.cost)
			return true;
		else
			return false;
	}
};
edge array[1001];

void swap(int a, int b)
{
	edge temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void quick_sort(int start, int end)
{
	if (start >= end)
		return;

	int loc = (start + end) / 2;
	edge pivot = array[loc];
	//printf("pivot start is %d end is %d cost is %d\n", pivot.start, pivot.end, pivot.cost);
	swap(loc, end);
	loc = start;
	
	for (int i = start; i < end; i++)
	{
		//printf("i is %d start is %d end is %d cost is %d\n", i, array[i].start, array[i].end, array[i].cost);
		if (array[i] < pivot)
		{
			swap(loc, i);
			loc++;
		}
	}
	//printf("loc is %d \n", loc);
	swap(loc, end);
	quick_sort(start, loc - 1);
	quick_sort(loc + 1, end);
}

int find(int n)
{
	if (n == parent[n])
		return n;
	else
	{
		int y = find(parent[n]);
		parent[n] = y;
		return y;
	}
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	parent[b] = a;
}

int kruskal(int v,int e)
{
	int count = 0;
	int length = 0;
	for (int i = 0; i < e; i++)
	{
		int a = array[i].start;
		int b = array[i].end;
		a = find(a);
		b = find(b);
		if (a != b)
		{
			//printf("i is %d start is %d end is %d cost is %d\n", i,array[i].start, array[i].end, array[i].cost);
			length = length + array[i].cost;
			count=count+1;
			uni(a, b);
		}
		if (count == v - 1)
			return length;
	}
}


int main()
{
	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 0; i <= v; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.start = a;
		e.end = b;
		e.cost = c;
		array[i] = e;
		//printf("i is %d start is %d end is %d cost is %d\n", i, array[i].start, array[i].end, array[i].cost);
	}
	quick_sort(0, e - 1);
	int length = kruskal(v, e);
	printf("%d", length);
}