#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector < vector<int>> v;
stack<pair<int, int>> sta;
bool check[20][20];

int final;
void left(int n, int now, vector<vector<int>> in);
void up(int n, int now, vector<vector<int>> in);
void down(int n, int now, vector<vector<int>> in);

void show(int n,vector<vector<int>> ve)
{
	int len = ve.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", ve[i][j]);
		printf("\n");
	}
}

void right(int n, int now,vector<vector<int>> in)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (in[i][j] > final)
				{
					final = in[i][j];
					show(n, in);
				}
			}
		}

		return;
	}
	vector<vector<int>> arr;
	arr = in;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[i][j] == 0)
				continue;
			if (arr[i][j + 1] == 0)
			{
				arr[i][j + 1] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j] == arr[i][j + 1] && check[i][j]==false)
			{
				arr[i][j + 1] = arr[i][j] * 2;
				if (arr[i][j + 1] == 128)
				{
					printf("after right now is %d\n", now + 1);
					show(n, in);
					show(n, arr);
				}
				arr[i][j] = 0;
				check[i][j + 1] = true;
				sta.push(make_pair(i, j + 1));
			}
		}
	}
	while (!sta.empty())
	{
		pair<int, int> temp = sta.top();
		check[temp.first][temp.second] = false;
		sta.pop();
	}

	left(n, now + 1, arr);
	right(n, now + 1, arr);
	up(n, now + 1, arr);
	down(n, now + 1, arr);
}

void left(int n, int now, vector<vector<int>> in)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (in[i][j] > final)
				{
					final = in[i][j];
					show(n, in);
				}
			}
		}

		return;
	}
	vector<vector<int>> arr;
	arr = in;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j > 0; j--)
		{
			if (arr[i][j] == 0)
				continue;
			if (arr[i][j - 1] == 0)
			{
				arr[i][j - 1] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j] == arr[i][j - 1] && check[i][j] == false)
			{
				arr[i][j - 1] = arr[i][j] * 2;
				if (arr[i][j - 1] == 128)
				{
					printf("after left now is %d\n", now + 1);
					show(n, in);
					show(n, arr);
				}
				arr[i][j] = 0;
				check[i][j - 1] = true;
				sta.push(make_pair(i, j - 1));
			}
		}
	}
	while (!sta.empty())
	{
		pair<int, int> temp = sta.top();
		check[temp.first][temp.second] = false;
		sta.pop();
	}

	left(n, now + 1, arr);
	right(n, now + 1, arr);
	up(n, now + 1, arr);
	down(n, now + 1, arr);
}

void down(int n, int now, vector<vector<int>> in)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (in[i][j] > final)
				{
					final = in[i][j];
					show(n, in);
				}
			}
		}

		return;
	}
	vector<vector<int>> arr;
	arr = in;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = 0;
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				continue;
			if (arr[i+1][j] == 0)
			{
				arr[i+1][j] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j] == arr[i+1][j] && check[i][j] == false)
			{
				arr[i+1][j] = arr[i][j] * 2;
				arr[i][j] = 0;
				check[i+1][j] = true;
				sta.push(make_pair(i+1, j));
			}
		}
	}
	while (!sta.empty())
	{
		pair<int, int> temp = sta.top();
		check[temp.first][temp.second] = false;
		sta.pop();
	}

	left(n, now + 1, arr);
	right(n, now + 1, arr);
	up(n, now + 1, arr);
	down(n, now + 1, arr);
}

void up(int n, int now, vector<vector<int>> in)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (in[i][j] > final)
					final = in[i][j];
			}
		}

		return;
	}
	vector<vector<int>> arr;
	arr = in;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = 0;
	}

	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				continue;
			if (arr[i-1][j] == 0)
			{
				arr[i-1][j] = arr[i][j];
				arr[i][j] = 0;
			}
			else if (arr[i][j] == arr[i-1][j] && check[i][j] == false)
			{
				arr[i-1][j] = arr[i][j] * 2;
				arr[i][j] = 0;
				check[i-1][j] = true;
				sta.push(make_pair(i-1, j));
			}
		}
	}
	while (!sta.empty())
	{
		pair<int, int> temp = sta.top();
		check[temp.first][temp.second] = false;
		sta.pop();
	}

	left(n, now + 1, arr);
	right(n, now + 1, arr);
	up(n, now + 1, arr);
	down(n, now + 1, arr);
}


int main()
{
	int n;
	scanf("%d", &n);
	v.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t;
			scanf("%d", &t);
			v[i].push_back(t);
		}
	}

	left(n, 0, v);
	right(n, 0, v);
	up(n, 0, v);
	down(n, 0, v);

	printf("%d", final);
}