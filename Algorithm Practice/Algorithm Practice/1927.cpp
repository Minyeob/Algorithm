#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v;
queue<int> q;
int v_loc;

void swap(int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void push_sort(int loc)
{
	while (loc>0)
	{
		if (v[loc] < v[loc / 2])
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
	v.push_back(a);
	
	int loc = v_loc;
	push_sort(loc);
}

void pop_sort()
{
	int loc = 1;
	while (loc*2<v.size())
	{
		int left = 0;
		int right = 0;
		if (loc * 2 < v.size())
			left = loc * 2;
		if (loc * 2 + 1 < v.size())
			right = loc * 2 + 1;
		
		int small=0;

		if (v[left] < v[right])
			small = left;
		else
			small = right;
		
		if (small!=0)
		{
			if (v[small] < v[loc])
			{
				swap(small, loc);
				loc = small;
			}
			else
				break;	
		}
		else
			break;
	}

	if (loc * 2 == v.size()-1)
	{
		if (loc * 2 < v.size())
	
		if (v[loc * 2] < v[loc])
		{
			swap(loc * 2, loc);
			loc = loc * 2;
		}
	}
}

void pop()
{
	if (v.size()==1)
		q.push(0);
	else
	{
		q.push(v[1]);
		swap(1, v.size()-1);
		v.pop_back();
		v_loc--;
		pop_sort();
	}	
}

int main()
{
	int n;
	scanf("%d", &n);
	v.push_back(0);
	v_loc = 1;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if (a == 0)
			pop();
		else
		{
			push(a);
			v_loc++;
		}
	}

	while (!q.empty())
	{
		printf("%d\n", q.front());
		q.pop();
	}
}