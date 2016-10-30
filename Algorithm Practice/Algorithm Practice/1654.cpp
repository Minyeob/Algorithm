#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int length[10000];
int max_length = 1000000000;

int ten_dvide(int k,int n)
{
	for (int i = max_length; i > 0; i = i / 10)
	{
		int sum = 0;
		for (int j = 0; j < k; j++)
		{
			int num = length[i] / max_length;
			sum = sum + num;
		}
		if (sum >= n)
		{
			return i;
		}
	}
}

int search(int k, int n,int start, int end)
{
	start = 1;
	end = pow(2, 32) - 1;
	
	int mid = (start + end) / 2;
	int sum = 0;
	for (int j = 0; j < k; j++)
	{
		int num = length[j] / mid;
		sum = sum + num;
	}
	if (sum < n)
	{
		search(k, n, mid + 1, end);
	}
	else if (sum > n)
	{
		search(k, n, start, mid);
	}
	else if (sum = n)
	{
		return mid;
	}
}

int main()
{
	int k,n;
	
	cin >> k >> n;
	int count = 0;
	
	
	for (int i = 0; i < k; i++)
	{
			cin >> length[i];
	}

	int start=ten_dvide(k, n);
	int end = pow(2, 32) - 1;

	search(k, n, start, end);

	
	
}

