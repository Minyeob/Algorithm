#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>

vector<vector <char>> v;
int q[350];
int check[26][26];
char input[26][26];

void bfs(int i, int j,int count, int n)
{
	check[i][j] = 1;
	q[count]=q[count]+1;
	if (j - 1 >= 0)
	{
		if (v[i][j - 1] == '1'&&!check[i][j - 1])
		{
			bfs(i, j - 1, count, n);
		}
	}
	if (i - 1 > 0)
	{
		if (v[i - 1][j] == '1'&&!check[i - 1][j])
		{
			bfs(i - 1, j, count, n);
		}
	}
	if (j + 1 <= n-1)
	{
		if (v[i][j + 1] == '1'&&!check[i][j + 1])
		{
			bfs(i, j + 1, count,n);
		}
	}
	if (i + 1 <= n)
	{
		if (v[i + 1][j] == '1'&&!check[i + 1][j])
		{
			bfs(i + 1, j, count,n);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		scanf("%s", &input[i]);
		for (int j = 0; j < n; j++)
		{
			char a = input[i][j];
			v[i].push_back(a);
		}
	}
	int q_count = 1;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j]=='1'&&!check[i][j])
			{
				bfs(i, j,q_count,n);
				q_count++;
			}
			check[i][j] = 1;
		}
	}

	printf("%d\n", q_count - 1);
	sort(q+1, q+q_count-1);
	for (int i = 1; i < q_count; i++)
	{
		printf("%d\n", q[i]);
	}
}