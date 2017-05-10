#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool check[200001];

queue<pair<int, int>> q;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int time = 0;
	if (n == k)
	{
		printf("0");
		return 0;
	}

	if (n - 1 >= 0)
	{
		check[n - 1] = true;
		q.push(make_pair(n - 1, 1));
	}
	if (n + 1 < 100050)
	{
		check[n + 1] = true;
		q.push(make_pair(n + 1, 1));
	}
	if (2 * n < 110000)
	{
		check[2 * n] = true;
		q.push(make_pair(2 * n, 1));
	}
	

	while (!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();
		if (now.first == k)
		{
			time = now.second;
			break;
		}
		if (now.first - 1 >= 0 && check[now.first - 1] == false)
		{
			check[now.first - 1] = true;
			q.push(make_pair(now.first - 1, now.second + 1));
		}
		if (now.first + 1 < 100050 && check[now.first + 1] == false)
		{
			check[now.first + 1] = true;
			q.push(make_pair(now.first + 1, now.second + 1));
		}
		if (2 * now.first < 110000 && check[2 * now.first] == false)
		{
			check[2 * now.first] = true;
			q.push(make_pair(2 * now.first, now.second + 1));
		}
	}
	printf("%d", time);
}