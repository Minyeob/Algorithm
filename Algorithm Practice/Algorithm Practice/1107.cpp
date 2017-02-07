#include <cstdio>
#include <algorithm>

bool count[500001];
int number[11];
bool check[11];

int abs(int n)
{
	if (n >= 0)
		return n;
	if (n < 0)
		return -n;
}

bool find(int n)
{
	int d = n % 10;
	if (check[d] == true)
		return false;
	while (n != 0)
	{
		d = n % 10;
		if (check[d] == true)
			return false;
		n = n / 10;
	}
	return true;
}

int main()
{
	count[100] = 0;
	int goal;
	scanf("%d", &goal);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		check[temp] = true;
	}

	for (int i = 0; i < 10; i++)
	{
		int min = 1;
		for (int j = i; j < 10; j++)
		{
			//printf("j is %d\n", j);
			int temp = j;
			if (j >= 10)
				temp = j - 10;
			if (check[temp] == false)
				break;
			else
				min = min + 1;
		}

		int cc = 1;
		for (int j = i; j >= 0; j--)
		{
			//printf("-----j is %d\n", j);
			int temp=j;
			if (j < 0)
				temp = j + 10;
			if (check[temp] == false)
			{
				if (cc < min)
					min = cc;
				break;
			}
			else
				cc = cc + 1;
		}

		number[i] = min;
	}	
	
	int sum = abs(goal - 100);
	//printf("sum2 is %d\n", sum2);

	int sum2 = 500001;
	int sum3 = 500001;
	int avail = 0;
	int multi = 1;
	int origin = goal;
	int origin2 = goal;
	bool good = false;
	while (!good)
	{
		good = find(origin);
		if (good == false)
			origin = origin - 1;
		if (origin < 0)
			break;
	}
	if (origin >= 0 && good == true)
	{
		sum2 = abs(origin - goal);
		int size = 0;
		if (origin == 0)
			size = 1;
		while (origin != 0)
		{
			origin=origin / 10;
			size = size + 1;
		}
		//printf("size is %d\n", size);
		sum2 = sum2 + size;
	}
	good = false;
	while (!good)
	{
		good = find(origin2);
		if (good == false)
			origin2 = origin2 + 1;
		if (origin2 > 1000000)
			break;
	}
	if (origin2 >= 0 && good == true)
	{
		sum3 = abs(origin2 - goal);
		int size = 0;
		if (origin2 == 0)
			size = 1;
		while (origin2 != 0)
		{
			origin2=origin2 / 10;
			size = size + 1;
		}
		sum3 = sum3 + size;
	}

	//printf("sum2 is %d sum3 is %d\n", sum2, sum3);

	int result = std::min(sum, sum2);
	result = std::min(result, sum3);
	printf("%d", result);
}