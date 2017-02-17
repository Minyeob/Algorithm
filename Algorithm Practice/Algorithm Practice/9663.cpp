#include<cstdio>


int N;
int ans = 0;

int a[16];

inline int abs(int a)
{
	return a > 0 ? a : -a;
}


bool check(int cur)
{
	for (int i = 0; i < cur; ++i)
	{
		if (a[i] == a[cur] || cur - i == abs(a[cur] - a[i]))
		{
			return false;
		}
	}
	return true;

}

void nqueen(int cur)
{
	if (N == cur)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		a[cur] = i;
		if (check(cur))
		{
			nqueen(cur + 1);
		}
	}

}

int main()
{
	scanf("%d", &N);
	nqueen(0);
	printf("%d\n", ans);

	return 0;
}