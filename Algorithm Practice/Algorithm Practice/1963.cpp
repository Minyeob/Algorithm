#include <cstdio>
#include <queue>
using namespace std;
bool check[10000];
bool visit[10000];
queue<pair<int,int>> q;
int temp[4];

int find(int now, int goal)
{
	if (now == goal)
		return 0;
	q.push(make_pair(now, 0));
	while (!q.empty())
	{
		int cur = q.front().first;
		//printf("cur is %d\n", cur);
		int same = cur;
		int num = q.front().second;
		q.pop();
		temp[0] = cur / 1000;
		cur = cur %1000;
		temp[1] = cur / 100;
		cur = cur%100;
		temp[2] = cur / 10;
		temp[3] = cur % 10;
		int test = 0;
		//printf("0 is %d 1 is %d 2 is %d 3 is %d \n", temp[0], temp[1],temp[2],temp[3]);
		
		//천의자리 변경
		for (int i = 1; i < 10; i++)
		{
			test = i * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
			if (test == same)
				continue;
			if (check[test] == false && visit[test]==false)
			{
				if (test == goal)
					return num + 1;
				q.push(make_pair(test, num + 1));
				visit[test] = true;
			}
		}
		
		//백의 자리 변경
		for (int i = 0; i < 10; i++)
		{
			test = temp[0] * 1000 + i * 100 + temp[2] * 10 + temp[3];
			if (test == same)
				continue;
			if (check[test] == false && visit[test] == false)
			{
				if (test == goal)
					return num + 1;
				q.push(make_pair(test, num + 1));
				visit[test] = true;
			}
		}

		//십의 자리 변경
		for (int i = 0; i < 10; i++)
		{
			test = temp[0] * 1000 + temp[1] * 100 + i * 10 + temp[3];
			if (test == same)
				continue;
			if (check[test] == false && visit[test] == false)
			{
				if (test == goal)
					return num + 1;
				q.push(make_pair(test, num + 1));
				visit[test] = true;
			}
		}

		//일의 자리 변경
		for (int i = 0; i < 10; i++)
		{
			test = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + i;
			if (test == same)
				continue;
			if (check[test] == false && visit[test] == false)
			{
				if (test == goal)
					return num + 1;
				q.push(make_pair(test, num + 1));
				visit[test] = true;
			}
		}
	}

	return -1;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 2; i < 10000; i++)
	{
		if (check[i] == false)
		{
			for (int j = i*i; j < 10000; j = j + i)
				check[j] = true;
		}
	}
	for (int i = 0; i < t; i++)
	{
		int input, output;
		scanf("%d %d", &input, &output);
		int count = find(input, output);
		while (!q.empty())
			q.pop();
		for (int i = 1000; i < 10000; i++)
			visit[i] = false;
		if (count == -1)
			printf("Impossible\n");
		else
			printf("%d\n", count);
	}
	
	
}