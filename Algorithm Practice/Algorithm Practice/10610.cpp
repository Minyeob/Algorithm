#include <cstdio>

char s[100001];
int num[100001];

void quick(int start, int end)
{
	if (start >= end)
		return;

	int loc = start;
	int pivot = num[start];
	num[start] = num[end];
	num[end] = pivot;

	for (int i = start; i < end; i++)
	{
		if (num[i] < pivot)
		{
			int temp = num[i];
			num[i] = num[loc];
			num[loc] = temp;
			loc++;
		}
	}
	int temp = num[loc];
	num[loc] = pivot;
	num[end] = temp;

	quick(start, loc - 1);
	quick(loc + 1, end);
}

int main()
{
	scanf("%s", s);
	int loc = 0;
	for (int i = 0; i < 100001; i++)
	{
		//printf("i is %d\n", i);
		if (s[i] == '\0')
		{
			loc = i;
			break;
		}
	}
	//printf("loc is %d\n", loc);
	
	for (int i = 0; i < loc; i++)
	{
		num[i] = s[i] - 48;
		//printf("num %d   is %d \n", i, num[i]);
	}
	
	quick(0, loc - 1);
	int sum = 0;

	if (num[0] != 0)
	{
		printf("-1");
		return 0;
	}
	else
	{
		for (int i = 0; i < loc; i++)
		{
			sum = sum + num[i];
		}
	}
	if (sum % 3 == 0)
	{
		for (int i = loc - 1; i >= 0; i--)
		{
			printf("%d", num[i]);
		}
	}
	else
		printf("-1");

}