#include <cstdio>

int input[100][100];
bool check[100][100];

void test(int x, int y,int n,int k)
{
	int next_x[4] = { 1,-1,0,0 };
	int next_y[4] = { 0,0,1,-1 };

	for (int i = 0; i < 4; i++)
	{
		int nex = x + next_x[i];
		int ney = y + next_y[i];
		if (nex >= 0 && ney >= 0 && nex < n && ney < n)
		{
			if (input[nex][ney] > k && check[nex][ney] != true)
			{
				check[nex][ney] = true;
				test(nex, ney, n, k);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}

	int max = 1;
	
	for (int k = 1; k < 100; k++)
	{
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (input[i][j] > k && check[i][j] != true)
				{
					check[i][j] = true;
					temp++;
					test(i, j, n, k);
				}
				else
					check[i][j] = true;
			}
		}
		if (max < temp)
			max = temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				check[i][j] = false;
		}
	}
	printf("%d", max);
}