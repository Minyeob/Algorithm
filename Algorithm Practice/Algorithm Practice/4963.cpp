#include <cstdio>
#include <queue>
using namespace std;

int input[51][51];
bool check[51][51];
queue<int> q;

int main()
{
	int w, h;
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		else
		{
			for (int i = 1; i <= h; i++)
			{
				for (int j = 1; j <= w; j++)
				{
					scanf("%d", &input[i][j]);
				}
			}

			for (int i = 1; i <= h; i++)
			{
				for (int j = 1; j <= w; j++)
				{
					scanf("%d", &input[i][j]);
				}
			}
		}
	}

}