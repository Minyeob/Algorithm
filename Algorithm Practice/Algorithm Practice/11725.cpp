#include <iostream>
#include <vector>
using namespace std;

int input[100001][3];
int parent[100001];
bool check[100001];
vector<vector <int>> in;

void find(int par, int n)
{
	for (int i = 0; i < in[par].size(); i++)
	{
		int a = in[par][i];
		if (a!=par&&!check[a])
		{
			check[a] = true;
			parent[a] = par;
			find(a, n);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	in.resize(n + 1);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		in[a].push_back(b);
		in[b].push_back(a);
	}
	
	check[1] = true;
	find(1, n);
	for (int i = 2; i < n + 1; i++)
	{
		printf("%d\n", parent[i]);
	}
}

