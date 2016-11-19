#include <iostream>
#include <algorithm>
using namespace std;
char tree[27][3];
char store[27][3];

void preorder(int start)
{
	cout << store[start][0];
	if (store[start][1])
		preorder((int)store[start][1]);
	if (store[start][2])
		preorder((int)store[start][2]);
}

void inorder(int start)
{
	if (store[start][1])
		inorder((int)store[start][1]);
	cout << store[start][0];
	if (store[start][2])
		inorder((int)store[start][2]);
}

void postorder(int start)
{
	if (store[start][1])
		postorder((int)store[start][1]);
	if (store[start][2])
		postorder((int)store[start][2]);
	cout << store[start][0];
}

void find(char obj, int loc, int n)
{
	if (loc >= 27)
		return;

	tree[loc][0] = obj;
	for (int i = 1; i < n + 1; i++)
	{
		if (store[i][0] == obj)
		{
			if (store[i][1] != '.')
			{
				tree[loc][1] = store[i][1];
				find(store[i][1], loc * 2, n);
			}
			if (store[i][2] != '.')
			{
				tree[loc][2] = store[i][2];
				find(store[i][2], loc * 2 + 1, n);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int loc = 1;
	tree[loc][0] = 'A';
	for (int i = 1; i < n+1; i++)
	{
		char a;
		cin >> a;
		int num = a - 'A' + 1;
		store[num][0] = a;
		char b;
		cin >> b;
		if (b != '.')
			store[num][1] = b-'A'+1;
		char c;
		cin >> c;
		if (c != '.')
			store[num][2] = c-'A'+1;
	}

	find(tree[loc][0], loc, n);

	int start = 1;
	preorder(start);
	cout << endl;
	inorder(start);
	cout << endl;
	postorder(start);
	cout << endl;
}

