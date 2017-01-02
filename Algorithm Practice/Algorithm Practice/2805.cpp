#include <stdio.h>
#include <iostream>
using namespace std;

int min = 0;
int max_length = 1000000000;
int tree[1000000];

int search(int start,int end, int tree_number, int required_length)
{
	int mid = (start+end) / 2;
	int sum = 0;
	for (int j = 0; j < tree_number; j++)
	{
		if (tree[j]-mid>0)
			sum = sum + (tree[j] - mid);
	}

	if (sum > required_length)
	{
		search(mid,end, tree_number, required_length);
	}
	else if (sum < required_length)
	{
		search(start, mid, tree_number, required_length);
	}
	else if (sum == required_length)
		return mid;
}

int main()
{
	int tree_number, required_length;
	scanf("%d %d", &tree_number, &required_length);
	for (int i = 0; i < tree_number; i++)
	{
		scanf("%d", &tree[i]);
	}

	int height=search(0, max_length, tree_number, required_length);
	while (1)
	{
		height = height + 1;
		int sum = 0;
		for (int i = 0; i < tree_number; i++)
		{
			if (tree[i] - height>0)
				sum = sum + (tree[i] - height);
		}
		if (sum < required_length)
		{
			height = height - 1;
			break;
		}
	}
	printf("%d", height);
}