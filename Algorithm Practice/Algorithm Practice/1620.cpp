#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

char name[100005][21];
char temp[21];
map<string, int> dic;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", name[i]);
		dic[name[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		if (temp[0] - '0' < 10)
		{
			int length = strlen(temp);
			int sum = 0;
			for (int j = length - 1; j >= 0; j--)
			{
				sum = sum + (temp[j]-'0') * pow(10, length - 1 - j);
				//printf("j is %d sum is %d \n", j, sum);
			}
			printf("%s\n",name[sum]);
		}
		else
		{
			printf("%d\n", dic[temp]);
		}
	}

}