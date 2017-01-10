#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int>> vec;
vector<vector<int>> length;
int max_length;
int root_length;

int part_length[100001];
int check[100001];
int root;
int leaf;

void dfs(int parent, int node, int root)
{
	check[node] = 1;
	for (int i = 0; i < vec[node].size(); i++)
	{
		int next = vec[node][i];
		//printf("node is %d and next is %d\n", node, next);
		if (vec[node].size() == 1 && check[next]==1)
		{
			if (part_length[node] > max_length)
			{
				max_length = part_length[node];
				leaf = node;
			}
				
		}

		if (!check[next])
		{
			part_length[next] = part_length[node] + length[node][i];
			//printf("length is %d\n", part_length[next]);
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

	for (int i = 0; i < v; i++)
	{
		int a;
		scanf("%d", &a);
		int b;
		scanf("%d", &b);
		int b_length = 0;
		while (b != -1)
		{
			int c, d;
			scanf("%d", &c);
			vec[a].push_back(b);
			length[a].push_back(c);
			scanf("%d", &b);
		}
	}

	root = 1;
	dfs(root, root, root);
	memset(part_length, 0, sizeof(part_length));
	memset(check, 0, sizeof(check));

	dfs(leaf, leaf, leaf);
	printf("%d", max_length);
}