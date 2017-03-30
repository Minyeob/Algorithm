#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool num[21];
char temp[10];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		if (strcmp(temp,"add")==0)
		{
			int loc;
			scanf("%d", &loc);
			num[loc] = true;
		}
		else if (strcmp(temp, "remove") == 0)
		{
			int loc;
			scanf("%d", &loc);
			num[loc] = false;
		}
		else if (strcmp(temp, "check") == 0)
		{
			int loc;
			scanf("%d", &loc);
			if (num[loc] == true)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(temp, "toggle") == 0)
		{
			int loc;
			scanf("%d", &loc);
			if (num[loc] == true)
				num[loc] = false;
			else
				num[loc] = true;
		}
		else if (strcmp(temp, "all") == 0)
		{
			for (int j = 1; j < 21; j++)
				num[j] = true;
		}
		else if (strcmp(temp, "empty") == 0)
		{
			for (int j = 1; j < 21; j++)
				num[j] = false;
		}
	}
}