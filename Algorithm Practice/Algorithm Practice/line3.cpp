#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;

#define MAX_N 1000

int graph[MAX_N][MAX_N];
int N;
bool check[MAX_N];
bool final;
vector<vector <int>> v;

/*
* Description :
* Time complexity :
* Space complexity :
*/
void solve(int n,int count) {
	// TODO implement your code to here.
	printf("count is %d \n", count);
	if (count == n)
	{
		final = true;
		return;
	}
	for (int i = 0; i < v[count].size(); i++)
	{
		int want = v[count][i];
		if (!check[want])
		{
			printf("p is %d want is %d \n", count, want);
			check[want] = true;
			solve(n, count + 1);
			check[want] = false;
		}
	}
}

void bfs(int n,int start)
{
	q.push(start);
	check[start] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (!check[next])
			{
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int T, K, P, S;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		// reset
		for (int person = 0; person < N; person++) {
			for (int seat = 0; seat < N; seat++) {
				graph[person][seat] = 0;
			}
		}

		cin >> K;
		v.resize(N+1);

		for (int i = 0; i < K; i++) {
			cin >> P;
			cin >> S;
			v[P].push_back(S);
		}
		final = false;
		solve(N, 0);

		if (final == true)
			cout << 'O' << '\n';
		else
			cout << 'X' << '\n';

		v.clear();
	}
	return 0;
}
