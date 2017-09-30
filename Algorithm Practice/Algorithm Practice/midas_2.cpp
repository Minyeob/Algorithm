#include <cstdio>
#include <cstring>
char input[10000];

int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%s", input);
		int last = strlen(input)-1;
		int num = 0;
		int score = 0;
		while (1)
		{
			int front = num;
			int back = last - num;
			if (front >= back)
				break;
			int point = abs(input[front] - input[back]);
			score = score + point;
			num++;
		}
		for (int i = 0; i <= last; i++)
			input[i] = 0;
		printf("%d\n", score);
	}
}