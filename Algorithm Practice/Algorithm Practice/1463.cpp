#include <cstdio>
#include <queue>
using namespace std;


queue<pair<int, int>> q;

int main()
{
	int n;
	scanf("%d", &n);

	q.push(make_pair(n,0));

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		if (temp.first == 1)
		{
			printf("%d", temp.second);
			break;
		}
		if (temp.first % 3 == 0)
			q.push(make_pair(temp.first / 3, temp.second + 1));
		if (temp.first % 2 == 0)
			q.push(make_pair(temp.first / 2, temp.second + 1));
		if (temp.first % 3 == 0)
			q.push(make_pair(temp.first / 3, temp.second + 1));
	}
}