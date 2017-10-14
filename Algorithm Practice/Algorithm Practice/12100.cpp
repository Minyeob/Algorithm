#include <cstdio>

int board[6][20][20];
int max;
void left(int n, int now);
void up(int n, int now);
void down(int n, int now);
void right(int n,int now)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[5][i][j] > max)
					max = board[5][i][j];
			}
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		//확인하고 점수 합치기
		for (int j = 0; j < n-1; j++)
		{
			int cur = board[now][i][j];
			if (cur != 0)
			{
				board[now + 1][i][j] = cur;
				for (int k = j + 1; k < n; k++)
				{
					int next = board[now][i][k];
					if (next == 0)
					{
						board[now + 1][i][k] = cur;
						board[now + 1][i][k - 1] = 0;
					}
					else
					{
						if (cur == next)
						{
							board[now + 1][i][k] = cur + next;
							j = j + 1;
							break;
						}
						else
							break;
					}
				}
			}
		}

		//마지막 밀기
		for (int j = 0; j < n - 1; j++)
		{
			int cur = board[now+1][i][j];
			if (cur != 0)
			{
				for (int k = j + 1; k < n; k++)
				{
					int next = board[now+1][i][k];
					if (next == 0)
					{
						board[now + 1][i][k] = cur;
						board[now + 1][i][k - 1] = 0;
					}
					else
						break;
				}
			}
		}
	}
	left(n, now + 1);
	right(n, now + 1);
	up(n, now + 1);
	down(n, now + 1);
}

void left(int n, int now)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[5][i][j] > max)
					max = board[5][i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		//확인하고 점수 합치기
		for (int j = n; j > 0; j--)
		{
			//printf("i is %d j is %d now is %d\n",i, j,now);
			int cur = board[now][i][j];
			//printf("cur is %d \n", cur);
			if (cur != 0)
			{
				board[now + 1][i][j] = cur;
				for (int k = j - 1; k >= 0; k--)
				{
					int next = board[now][i][k];
					if (next == 0)
					{
						board[now + 1][i][k] = cur;
						board[now + 1][i][k + 1] = 0;
					}
					else
					{
						if (cur == next)
						{
							board[now + 1][i][k] = cur + next;
							//printf("sum is %d \n", board[now + 1][i][k]);
							j = j - 1;
							break;
						}
						else
							break;
					}
				}
			}
		}

		//마지막 밀기
		for (int j = n; j > 0; j--)
		{
			int cur = board[now + 1][i][j];
			if (cur != 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					int next = board[now + 1][i][k];
					if (next == 0)
					{
						board[now + 1][i][k] = cur;
						board[now + 1][i][k + 1] = 0;
					}
					else
						break;
				}
			}
		}
	}
	left(n, now + 1);
	right(n, now + 1);
	up(n, now + 1);
	down(n, now + 1);
}

void down(int n, int now)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[5][i][j] > max)
					max = board[5][i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		//확인하고 점수 합치기
		for (int j = 0; j < n - 1; j++)
		{
			//printf("i is %d j is %d now is %d\n", i, j, now);
			int cur = board[now][j][i];
			//printf("cur is %d \n", cur);
			if (cur != 0)
			{
				board[now + 1][j][i] = cur;
				for (int k = j + 1; k < n; k++)
				{
					int next = board[now][k][i];
					if (next == 0)
					{
						board[now + 1][k][i] = cur;
						board[now + 1][k-1][i] = 0;
					}
					else
					{
						if (cur == next)
						{
							board[now + 1][k][i] = cur + next;
							j = j + 1;
							break;
						}
						else
							break;
					}
				}
			}
		}

		//마지막 밀기
		for (int j = 0; j < n - 1; j++)
		{
			int cur = board[now + 1][j][i];
			if (cur != 0)
			{
				for (int k = j + 1; k < n; k++)
				{
					int next = board[now + 1][k][i];
					if (next == 0)
					{
						board[now + 1][k][i] = cur;
						board[now + 1][k-1][i] = 0;
					}
					else
						break;
				}
			}
		}
	}
	left(n, now + 1);
	right(n, now + 1);
	up(n, now + 1);
	down(n, now + 1);
}

void up(int n, int now)
{
	if (now == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[5][i][j] > max)
					max = board[5][i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		//확인하고 점수 합치기
		for (int j = n; j > 0; j--)
		{
			int cur = board[now][j][i];
			if (cur != 0)
			{
				board[now + 1][j][i] = cur;
				for (int k = j - 1; k >= 0; k--)
				{
					int next = board[now][k][i];
					if (next == 0)
					{
						board[now + 1][k][i] = cur;
						board[now + 1][k+1][i] = 0;
					}
					else
					{
						if (cur == next)
						{
							board[now + 1][k][i] = cur + next;
							j = j - 1;
							break;
						}
						else
							break;
					}
				}
			}
		}

		//마지막 밀기
		for (int j = n; j > 0; j--)
		{
			int cur = board[now + 1][j][i];
			if (cur != 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					int next = board[now + 1][k][i];
					if (next == 0)
					{
						board[now + 1][k][i] = cur;
						board[now + 1][k+1][i] = 0;
					}
					else
						break;
				}
			}
		}
	}
	left(n, now + 1);
	right(n, now + 1);
	up(n, now + 1);
	down(n, now + 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &board[0][i][j]);
	}
	left(n, 0);
	right(n, 0);
	up(n, 0);
	down(n, 0);

	printf("%d", max);
}