#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#include <queue>

vector<vector <int>> v;
queue<int> q;
void bfs(int start)
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[start].size(); i++)
		{

		}
	}
}