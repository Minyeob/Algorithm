#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
bool check[1000001];
int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

int bfs(int goal)
{
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		int start = now.first;
		int len = now.second;
		if (start == goal)
			return len;
		if (start - 1 >= 0 && check[start - 1] == false)
		{
			q.push(make_pair(start - 1, len + 1));
			check[start - 1] = true;
		}
		if (check[start + 1] == false)
		{
			q.push(make_pair(start + 1, len + 1));
			check[start + 1] = true;
		}
		if (start * 2 < 200000 && check[start * 2] == false)
		{
			q.push(make_pair(start * 2, len + 1));
			check[start * 2] = true;
		}
	}
}

int main()
{
	int start, goal;
	scanf("%d %d", &start, &goal);

	if (start == goal)
	{
		printf("0");
		return 0;
	}

	q.push(make_pair(start, 0));
	int len=bfs(goal);
	printf("%d", len);
}