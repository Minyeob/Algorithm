#include <cstdio>
#include <vector>
using namespace std;
vector<vector <int>> v;
int num[50];

bool check(int goal,int del)
{
	if (goal == del)
		return false;
	if (v[goal].size() == 0)
	{
		return true;
	}

	int next = v[goal][0];
	//printf("next is %d \n", next);
	if (next == del)
		return false;
	
	check(next,del);
}

int main()
{
	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	bool avail[50];
	for (int i = 0; i < 50; i++)
		avail[i] = true;

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);

		if (p == -1)
			continue;
		else
		{
			v[i].push_back(p);
			num[p]++;
		}
	}
	int del;
	scanf("%d", &del);

	for (int i = 0; i < n; i++)
	{
		bool t = check(i, del);
		if (t == false)
		{
			avail[i] = false;
			//printf("false is %d \n", i);
			if(v[i].size()!=0)
				num[v[i][0]]--;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (num[i] == 0 && avail[i] == true)
		{
			//printf("i is %d \n", i);
			sum++;
		}
	}
	printf("%d", sum);
	
}