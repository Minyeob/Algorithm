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
int sum;

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

int test(int start, int size)
{
	int now, next = 0;
	now = start;
	next = student[start];
	check[now] = 1;
	nowcheck[now] = start;

	if (now == next)
	{
		result[now] = true;
		sum--;
		return sum;
	}

	while (!check[next])
	{
		now = next;
		check[next] = 1;
		nowcheck[next] = start;
		next = student[next];
	}

	if (now == next)
	{
		result[now] = true;
		sum--;

		return sum;
	}
	else if (nowcheck[next] == start)
	{
		result[now] = true;
		nowcheck[now] = 0;
		sum = sum - 1;
		while (next != now)
		{
			result[next] = true;
			sum = sum - 1;
			next = student[next];
		}
	}

	return sum;
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
		sum = student_number;
		for (int j = 1; j <= student_number; j++)
		{
			if (!check[j])
			{
				test(j, student_number);
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