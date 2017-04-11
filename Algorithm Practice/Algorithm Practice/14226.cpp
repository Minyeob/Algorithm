#include <cstdio>
#include <queue>
using namespace std;
bool check[10001][10001];

struct state {
	int screen;
	int clip;

	state(int a, int b)
	{
		screen = a;
		clip = b;
	}
};
queue<state> q;

int main()
{
	int s;
	scanf("%d", &s);
	
	q.push(state(1,0));
	check[1][0] = true;
	int count = 0;
	while (!q.empty())
	{
		int size = q.size();
		//printf("size is %d\n", size);
		for (int i = 0; i <size; i++)
		{
			state now = q.front();
			//printf("%d	%d	%d\n", now.screen,now.clip,now.time);
			//printf("%d\n", q.size());
			if (now.screen == s)
			{
				printf("%d", count);
				return 0;
			}
			q.pop();
			if (now.screen != now.clip && check[now.screen][now.screen] == false)
			{
				q.push(state(now.screen, now.screen));
				check[now.screen][now.screen] = true;
			}

			if (now.screen + now.clip < 1051 && check[now.screen + now.clip][now.clip] == false && now.clip != 0)
			{
				q.push(state(now.screen + now.clip, now.clip));
				check[now.screen + now.clip][now.clip] = true;
			}

			if (check[now.screen - 1][now.clip] == false && now.screen - 1 > 0)
			{
				q.push(state(now.screen - 1, now.clip));
				check[now.screen - 1][now.clip] = true;
			}
		}
		count++;
	}
}