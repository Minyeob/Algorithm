#include <cstdio>

bool visit[101][101];
int go[101][101];
int num;

void dfs(int start,int now,int max)
{
	num++;
	printf("%d\n", num);
	for (int i = 0; i < max; i++)
	{
		if (go[now][i] == 1 && visit[now][i] == false)
		{
			go[start][i] = 1;
			visit[now][i] = true;
			dfs(start, i, max);
			visit[now][i] = false;
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
			scanf("%d", &go[i][j]);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (go[i][k]==1 && go[k][j]==1) {
					//printf("i is %d j is %d \n", i, j);
					go[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", go[i][j]);
		}
		printf("\n");
	}
}