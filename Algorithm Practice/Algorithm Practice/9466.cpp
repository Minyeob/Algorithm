#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

queue<int> q;
int student[100001];
int check[100001];
int nowcheck[100001];
bool result[100001];
int num_result[100001];

void bfs(int start)
{
	q.push(start);
	check[start] = 1;
	while (!q.empty())
	{

	}
}

void clear_array(int arr[], int size)
{
	for (int i = 0; i <= size; i++)
	{
		arr[i] = 0;
	}
}

void test(int start, int size)
{	
	int now, next=0;
	now = start;
	next = student[start];
	check[now] = 1;
	nowcheck[now] = 1;

	while(!check[next])
	{
		now = next;
		check[next] = 1;
		nowcheck[next] = 1;
		next = student[next];
	}

	if (now == next)
		result[now] = true;
	else if (nowcheck[next] == 1)
	{
		result[now] = true;
		while (next != now)
		{
			result[next] = true;
			next = student[next];
		}
	}

	clear_array(nowcheck, size);
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
	}
	for (int i = 0; i < case_count; i++)
	{
		printf("%d\n", num_result[i]);
	}
}