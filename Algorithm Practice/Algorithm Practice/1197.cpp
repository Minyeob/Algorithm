#include <cstdio>
#include <queue>
using namespace std;

int cost[10001][10001];
bool visit[10001];

struct node{
	int start;
	int next;
	int cost;

	node(){};
	node(const node& temp)
	{
		this->start = temp.start;
		this->next = temp.next;
		this->cost = temp.cost;
	};

	void operator=(const node& temp)
	{
		this->start = temp.start;
		this->next = temp.next;
		this->cost = temp.cost;
	}
};

node edge[100001];
queue<node> q;
int final_distance;

void swap(int a, int b)
{
	node temp = edge[a];
	edge[a] = edge[b];
	edge[b] = temp;
}

void push_sort(int loc)
{
	if (loc <= 1)
		return;
	int now = edge[loc].cost;
	int parent_loc = loc / 2;
	int parent = edge[parent_loc].cost;
	if (now < parent)
	{
		swap(loc, parent_loc);
		push_sort(parent_loc);
	}
	else
		return;
}

int heap_push(node e, int loc)
{
	edge[loc] = e;
	push_sort(loc);
	loc = loc + 1;
	return loc;
}

void pop_sort(int loc)
{
	int now_loc = 1;
	while (now_loc * 2 < loc)
	{
		int now = edge[now_loc].cost;
		int left_loc = now_loc * 2;
		int left = edge[left_loc].cost;
		int right_loc = now_loc * 2 + 1;
		int right = edge[right_loc].cost;
		int child = 0;
		int child_loc = 0;

		if (left < right)
		{
			child = left;
			child_loc = left_loc;
		}
		else
		{
			child = right;
			child_loc = right_loc;
		}
		if (child != 0)
		{
			if (now > child)
			{
				swap(now_loc, child_loc);
				now_loc = child_loc;
			}
			else
				break;
		}

		else
			break;
	}
	if (edge[now_loc].cost > edge[now_loc * 2].cost && edge[now_loc * 2].cost != 0)
		swap(now_loc, now_loc * 2);
}

int pop(int loc)
{
	if (visit[edge[1].next] == 0)
	{
		visit[edge[1].next] = true;
		int distance = edge[1].cost;
		//printf("selected from %d to %d cost is %d \n", edge[1].start, edge[1].next, edge[1].cost);
		final_distance = final_distance + distance;
		loc = loc - 1;
		swap(1, loc);
		edge[loc].cost = 0;
		edge[loc].next = 0;
		pop_sort(loc - 1);
		return loc;
	}
	else
	{
		loc = loc - 1;
		swap(1, loc);
		edge[loc].cost = 0;
		edge[loc].next = 0;
		pop_sort(loc);
		pop(loc);
	}
}



void prim(int start, int v, int e)
{
	int length = 0;
	int count = 0;
	visit[start] = true;
	int loc = start;

	for (int i = 1; i < v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (visit[j] == true)
			{
				for (int k = 1; k <= v; k++)
				{
					if (cost[j][k] != 0)
					{
						node n;
						n.cost = cost[j][k];
						n.next = k;
						n.start = j;
						loc = heap_push(n, loc);
						//printf("from %d to %d cost is %d loc is %d\n", n.start, n.next, n.cost,loc);
					}
				}
			}
		}
		loc = pop(loc);
		loc = 1;
		//printf("distance is %d\n", final_distance);
	}
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c;
		cost[b][a] = c;
	}

	prim(1, v, e);
	printf("%d", final_distance);
}