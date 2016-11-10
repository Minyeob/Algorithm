#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> input;
int check[1001];

void dfs(int start)
{
	for (int i = 0; i < input[start].size(); i++)
	{
		int next = input[start][i];
		if (!check[next])
		{
			check[next] = 1;
			dfs(next);
		}
	}
}

int main()
{
	int number;
	cin >> number;

	for (int i = 0; i < number; i++)
	{
		int n;
		cin >> n;
		input.resize(n + 1);
		for (int j = 1; j < n+1; j++)
		{
			int a;
			cin >> a;
			input[j].push_back(a);
		}
		int count = 0;
		for (int q = 1; q < n + 1; q++)
		{
			if (!check[q])
			{
				check[q] = 1;
				count++;
				dfs(q);
			}
		}

		printf("%d\n", count);
		input.clear();
		for (int w = 0; w < 1001; w++)
			check[w] = 0;
	}
}