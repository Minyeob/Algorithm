#include <cstdio>

bool room[101];

int check(int n)
{
	int people = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j = j + i)
		{
			if (room[j] == true)
			{
				room[j] = false;
				people--;
			}
			else
			{
				room[j] = true;
				people++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		room[i] = false;
	return people;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int people = check(n);
		printf("%d\n", people);
	}
	
}