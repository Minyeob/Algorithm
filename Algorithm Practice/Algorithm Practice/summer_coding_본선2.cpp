#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int cost[51][51];
queue<pair<int, int>> q;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cost[i][j] = 50000000;
	}
	for (int i = 0; i < road.size(); i++)
	{
		if (road[i][2]<cost[road[i][0]][road[i][1]])
		{
			cost[road[i][0]][road[i][1]] = road[i][2];
			cost[road[i][1]][road[i][0]] = road[i][2];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (cost[1][i] != 0)
		{
			q.push(make_pair(i, cost[1][i]));
		}
	}

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		int now = temp.first;
		int sum = temp.second;
		if (sum < K)
		{
			for (int i = 1; i <= N; i++)
			{
				if (cost[now][i] != 0 && now != i && i != 1)
				{
					if (cost[1][i] > sum + cost[now][i])
					{
						cost[1][i] = sum + cost[now][i];
						q.push(make_pair(i, sum + cost[now][i]));
					}
				}
			}
		}
	}

	int check;
	check = cost[1][5];
	for (int i = 2; i <= N; i++)
	{
		if (cost[1][i] <= K)
			answer += 1;
	}
	answer += 1;

	return answer;
}