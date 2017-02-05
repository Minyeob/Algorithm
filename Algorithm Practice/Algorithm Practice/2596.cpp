#include <cstdio>

char number[60];
char temp[6];
char A[6] = { '0', '0', '0', '0', '0', '0' };
char B[6] = { '0', '0', '1', '1', '1', '1' };
char C[6] = { '0', '1', '0', '0', '1', '1' };
char D[6] = { '0', '1', '1', '1', '0', '0' };
char E[6] = { '1', '0', '0', '1', '1', '0' };
char F[6] = { '1', '0', '1', '0', '0', '1' };
char G[6] = { '1', '1', '0', '1', '0', '1' };
char H[6] = { '1', '1', '1', '0', '1', '0' };
int result[8];
char final[10];

void check(char temp[])
{
	int count = 0;
	int loc = 0;
	for (int i = 0; i < 6; i++)
	{
		if (A[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (B[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (C[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (D[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (E[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (F[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (G[i] != temp[i])
			count++;
	}
	result[loc] = count;
	count = 0;
	loc = loc + 1;
	for (int i = 0; i < 6; i++)
	{
		if (H[i] != temp[i])
			count++;
	}
	result[loc] = count;
}

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", number);
	int loc = 1;
	while (loc<=n)
	{
		for (int i = 0; i < 6; i++)
		{
			temp[i] = number[i];
		}
		check(temp);
		int min = 9999;
		int minloc = 0;
		for (int i = 0; i < 8; i++)
		{
			if (result[i] < min)
			{
				min = result[i];
				minloc = i;
			}
		}
		//printf("min is %d minloc is %d\n", min, minloc);
		if (min >= 2)
		{
			printf("%d", loc);
			return 0;
		}
		else
			final[loc] = minloc + 65;
		loc = loc + 1;

		for (int i = 0; i < (n - 1) * 6; i++)
		{
			number[i] = number[i + 6];
		}
	}
	for (int i = 1; i < loc; i++)
	{
		printf("%c", final[i]);
	}

}