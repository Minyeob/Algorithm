#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int board[501][501];
int cc[501][501];
struct point
{
	int tree;
	int x;
	int y;

	bool operator <(point p)
	{
		if (tree < p.tree)
			return true;
		else
			return false;
	}
};
vector<point> v;
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &board[i][j]);
			point p;
			p.tree = board[i][j];
			p.x = i;
			p.y = j;
			v.push_back(p);
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].x;
		int y = v[i].y;
		if (cc[x][y] == 0)
			cc[x][y] = 1;
		if (x - 1 > 0 && board[x - 1][y] > board[x][y])
		{
			if (cc[x - 1][y] < cc[x][y] + 1)
				cc[x - 1][y] = cc[x][y] + 1;
		}
		if (x + 1 <= n && board[x + 1][y] > board[x][y])
		{
			if (cc[x + 1][y] < cc[x][y] + 1)
				cc[x + 1][y] = cc[x][y] + 1;
		}
		if (y - 1 > 0 && board[x][y-1] > board[x][y])
		{
			if (cc[x][y-1] < cc[x][y] + 1)
				cc[x][y-1] = cc[x][y] + 1;
		}
		if (y + 1 <= n && board[x][y + 1] > board[x][y])
		{
			if (cc[x][y + 1] < cc[x][y] + 1)
				cc[x][y + 1] = cc[x][y] + 1;
		}
	}

	int final = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cc[i][j] > final)
				final = cc[i][j];
		}
	}

	printf("%d", final);
}