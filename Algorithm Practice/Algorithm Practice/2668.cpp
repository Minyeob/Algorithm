#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int card[101];
bool check[101];
vector<int> v;
int max_num;

void push_cycle(int n)
{
	v.push_back(n);
	int next = card[n];
	while (next != n)
	{
		v.push_back(next);
		//printf("push is %d\n", next);
		check[next] = true;
		next = card[next];
	}
}

void dfs(int start, int n)
{
	int next = card[n];
	if (check[next] == false)
	{
		check[next] = true;
		dfs(start, next);
		check[next] = false;
	}

	else
	{
		if (next == start)
			push_cycle(start);
		else
			return;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int j;
		scanf("%d", &j);
		if (i == j)
			v.push_back(j);
		card[i] = j;
	}

	int loc = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i != card[i])
		{
			check[i] = true;
			dfs(i, i);
		}
	}

	sort(v.begin(), v.end());
	
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v[i]);
	}
}