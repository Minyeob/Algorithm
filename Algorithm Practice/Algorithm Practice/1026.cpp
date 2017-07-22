#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int A[50];
int B[50];
int temp[50];

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void quick(int start, int end)
{
	if (start >= end)
		return;
	int pivot = A[start];
	swap(A[start], A[end]);
	int loc = start;

	for (int i = start; i < end; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[loc]);
			loc++;
		}
	}
	swap(A[loc], A[end]);

	quick(start, loc - 1);
	quick(loc + 1, end);
}

void merge(int start, int end)
{
	//printf("start is %d end is %d \n", start, end);
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	merge(start, mid);
	merge(mid+1, end);
	
	int i = start;
	int j = mid+1;
	int loc = start;
	while (i <= mid && j <= end)
	{
		if (B[i] > B[j])
		{
			temp[loc] = B[i];
			loc++;
			i++;
		}
		else
		{
			temp[loc] = B[j];
			loc++;
			j++;
		}
		//printf("i is %d j is %d loc is %d \n", i, j, loc);
	}

	while (i <= mid)
	{
		temp[loc] = B[i];
		loc++;
		i++;
	}

	while (j <= end)
	{
		temp[loc] = B[j];
		loc++;
		j++;
	}

	for (int k = start; k <= end; k++)
	{
		B[k] = temp[k];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	quick(0, n - 1);
	merge(0, n - 1);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += A[i] * B[i];
	}
	printf("%d", sum);
}