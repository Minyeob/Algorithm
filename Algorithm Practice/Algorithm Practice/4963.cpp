#include <cstdio>

int input[50][50];
bool check[50][50];

void dfs(int x, int y,int w,int h)
{
	//printf("x is %d y is %d \n", x, y);
	int next_x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
	int next_y[8] = { 1,0,-1,1,-1,1,0,-1 };

	for (int i = 0; i < 8; i++)
	{
		int nex = x + next_x[i];
		int ney = y + next_y[i];

		if (nex >= 0 && ney >= 0 && nex < w && ney < h)
		{
			if (check[ney][nex] == false)
			{
				check[ney][nex] = true;
				if (input[ney][nex] == 1)
					dfs(nex, ney, w, h);
			}
		}
	}
}

int main()
{
	while (1)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				scanf("%d", &input[i][j]);
		}

		int sum = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (check[i][j] == false && input[i][j] == 1)
				{
					sum++;
					dfs(j, i, w, h);
				}
			}
		}
		printf("%d\n", sum);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				check[i][j] = false;
		}
	}
}