#include <cstdio>
#include <vector>
using namespace std;

int num[20000000];
vector<int> v;

void find(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (num[i] == 0)
		{
			for (int j = 2; j <= i; j++)
			{
				//printf("%d\n", i*j);
				if (i*j > n)
					break;
				else
					num[i*j] = 1;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	find(n);

	for (int i = 2; i <= n; i++)
	{
		if (num[i] == 0)
		{
			while (n%i == 0)
			{	
				v.push_back(i);
				n = n / i;
			}
			if (n == 0)
				break;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v[i]);
	}
	
}