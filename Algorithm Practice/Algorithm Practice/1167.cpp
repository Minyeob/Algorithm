#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<vector<int>> length;
int max_length;

int check[100001];
int part_length[100001];

void dfs(int parent, int node, int root)
{
	for (int i = 0; i < vec[node].size(); i++)
	{
	
		int next = vec[node][i];
		if (vec[node].size() == 1 && next==parent)
		{
			if (part_length[node] > max_length)
				max_length = part_length[node];
			break;
			
		}

		if (next != parent)
		{	
			part_length[next] = part_length[node] + length[node][i];
			dfs(node, next, root);
		}
	}
}

int main()
{
	int v;
	scanf("%d", &v);
	vec.resize(v + 1);
	length.resize(v + 1);
	int root;

	for (int i = 0; i < v; i++)
	{
		int a;
		scanf("%d", &a);
		int b;
		scanf("%d", &b);
		while (b != -1)
		{
			int c,d;
			scanf("%d", &c);
			vec[a].push_back(b);
			length[a].push_back(c);
			scanf("%d", &b);
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (vec[i].size() == 1)
		{
			root = i;
			break;
		}
	}

	dfs(root, root, root);

	printf("%d", max_length);
}