#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int cc[10001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		cc[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (cc[i] != 0)
		{
			for (int j = 0; j < cc[i]; j++)
				printf("%d\n", i);
		}
	}
}