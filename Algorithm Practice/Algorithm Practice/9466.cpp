#include <cstdio>
#include <algorithm>
#include <string.h>

int student[100001];
int check[100001];
int nowcheck[100001];
bool result[100001];
int num_result[100001];

void clear_array(int arr[], int size)
{
	for (int i = 0; i <= size; i++)
	{
		arr[i] = 0;
	}
}

void test(int start, int size)
{	
	if (check[student[start]])
	{
		check[start] = 1;
		return;
	}
	check[start] = 1;
	int now = start;
	int next = student[start];
	

	while (!check[next])
	{
		check[next] = 1;
		now = next;
		next = student[next];
	}

	result[now] = true;
	while (!result[next])
	{
		result[next] = true;
		next = student[next];
	}
}

int main()
{
	int case_count;
	scanf("%d", &case_count);
	for (int i = 0; i < case_count; i++)
	{
		int student_number;
		scanf("%d", &student_number);
		for (int j = 1; j <= student_number; j++)
		{
			scanf("%d", &student[j]);
		}
		for (int j = 1; j <= student_number; j++)
		{
			if (!check[j])
			{
				test(j,student_number);
			}
		}
		int sum = 0;
		for (int j = 1; j <= student_number; j++)
		{
			if (!result[j])
			{
				sum++;
			}
		}
		num_result[i] = sum;
		clear_array(check, student_number);
		clear_array(student, student_number);
		memset(result, false, sizeof(result));
	}
	for (int i = 0; i < case_count; i++)
	{
		printf("%d\n", num_result[i]);
	}
}