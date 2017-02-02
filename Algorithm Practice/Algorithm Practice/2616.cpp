#include <cstdio>
#include <algorithm>

int people[50001];
int maxsum;

struct train{
	int sum;
	int loc;

	train(){};
	train(const train& temp)
	{
		sum = temp.sum;
		loc = temp.loc;
	}

	void operator=(const train& temp)
	{
		sum = temp.sum;
		loc = temp.loc;
	}

	bool operator<(const train& temp)
	{
		return sum < temp.sum;
	}

	bool operator==(const train& temp)
	{
		if (sum == temp.sum && loc == temp.loc)
			return true;
		else
			return false;
	}
	bool operator!=(const train& temp)
	{
		if (sum == temp.sum && loc == temp.loc)
			return false;
		else
			return true;
	}
};
train t[50001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &people[i]);
	}
	int capable;
	scanf("%d", &capable);
	
	for (int i = 0; i <= n - capable; i++)
	{
		int temp = 0;
		if (i + capable <= n)
		{
			for (int j = i; j < i+capable; j++)
			{
				temp = temp + people[j];
			}
			train tra;
			tra.sum = temp;
			tra.loc = i;
			t[i] = tra;
		}
	}
	std::sort(t, t + n - capable + 1);

	int loc = 0;
	for (int z= n - capable; z > n - (2 * capable); z--)
	{
			train first = t[z];
			//printf("first sum is %d loc is %d\n", first.sum,first.loc);
			train second = first;
			train third = first;
			int startloc = z - 1;
			//printf("start loc is %d\n", startloc);
			for (int k = 0; k < 3; k++)
			{
				for (int i = startloc; i >= 0; i--)
				{
					if (t[i].loc <= first.loc - capable || t[i].loc >= first.loc + capable)
					{
						second = t[i];
						//printf("second is %d loc is %d\n", second.sum,second.loc);
						startloc = i - 1;
						break;
					}
				}

				if (first != second)
				{
					for (int i = startloc; i >= 0; i--)
					{
						if (t[i].loc <= first.loc - capable || t[i].loc >= first.loc + capable)
						{
							if (t[i].loc <= second.loc - capable || t[i].loc >= second.loc + capable)
							{
								third = t[i];
								//printf("third is %d loc is %d\n", third.sum, third.loc);
								break;
							}
						}
					}
				}

				if (first != second && first != third)
				{
					int sum= first.sum + second.sum + third.sum;
					if (sum > maxsum)
						maxsum = sum;
				}
			}
	}
	printf("%d", maxsum);
}