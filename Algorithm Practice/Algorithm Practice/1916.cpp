#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

struct edge{
	int start;
	int end;
	int cost;
};
vector<edge> v;

int dist[1001];
int check[1001];

int main()
{
	int n, m;
	scanf("%d &m", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge e;
		e.start = a;
		e.end = b;
		e.cost = c;
		v.push_back(e);
	}
	int start_city, destination;
	scanf("%d %d", &start_city, &destination);

	int max = n * 100000;
	for (int j = 0; j < v.size(); j++)
	{
		edge now = v[j];
		if
	}
}