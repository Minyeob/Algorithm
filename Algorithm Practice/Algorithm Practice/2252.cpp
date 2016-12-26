#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int check[32001];
queue <int> q;
vector <vector<int>> v;
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	v.resize(a + 1);
	int c, d;
	for (int i = 0; i < b; i++)
	{
		scanf("%d %d", &c, &d);
		v[c].push_back(d);
		check[d]++;
	}
	
	for (int i = 1; i < a + 1; i++)
	{
		if (check[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		printf("%d ", cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			check[next]--;

			if (check[next] == 0)
				q.push(next);
		}
	}
}