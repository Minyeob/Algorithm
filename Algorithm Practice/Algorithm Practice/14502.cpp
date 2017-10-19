#include <cstdio>
#include <vector>
using namespace std;
int final;
vector<vector<int>> board;
void test(int x, int y, int n, int m)
{
	int nex[4] = { 1,-1,0,0 };
	int ney[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		int x_next = x + nex[i];
		int y_next = y + ney[i];
		if (x_next >= 0 && y_next >= 0 && x_next < n && y_next < m)
		{
			if (board[x_next][y_next] == 0)
			{
				board[x_next][y_next] = 2;
				test(x_next, y_next, n, m);
			}
		}
	}
}

int cal(int n, int m, vector<vector<int>> v)
{
	board = v;
	int nex[4] = { 1,-1,0,0 };
	int ney[4] = { 0,0,1,-1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 2)
				test(i, j, n, m);
		}
	}
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				count++;
		}
	}
	return count;
}

void start(int count, int n,int m,vector<vector<int>> input)
{
	if (count == 3)
	{
		int num = cal(n, m, input);
		if (num > final)
		{
			final = num;
			/*printf("final is %d \n", final);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					printf("%d ", board[i][j]);
				}
				printf("\n");
			}*/
		}
		return;
	}
	vector<vector<int>> v;
	v = input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 0)
			{
				v[i][j] = 1;
				start(count + 1, n, m, v);
				v[i][j] = 0;
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> first;
	first.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			scanf("%d", &temp);
			first[i].push_back(temp);
		}
	}

	start(0, n, m, first);
	printf("%d", final);
}