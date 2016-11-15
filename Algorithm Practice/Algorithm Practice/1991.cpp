#include <iostream>
#include <algorithm>
using namespace std;
char tree[27][3];

void preorder(int start)
{
	cout << tree[start][0];
	if (tree[start][1])
		preorder(start * 2);
	if (tree[start][2])
		preorder(start * 2 + 1);
}

void inorder(int start)
{
	int end;
	while (tree[start][1])
	{
		start = start * 2;
	}
	while (start > 1)
	{
		cout << tree[start][0];
		cout << tree[start / 2][0];
		cout << tree[start + 1][0];
		start = start / 2;
	}
	start = 1;
	cout << tree[start][0];
	while (tree[start][2])
	{
		while (tree[start][1])
		{
			start = start * 2;
		}
		while (start > 1)
		{
			cout << tree[start][0];
			cout << tree[start / 2][0];
			cout << tree[start + 1][0];
			start = start / 2;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int loc = 1;
	tree[loc][0] = 'A';
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		for (int j = 1; j < n+1; j++)
		{
			if (a == tree[j][0])
			{
				loc = j;
				break;
			}
		}
		char b;
		cin >> b;
		if (b == '.'){}
		else
		{
			tree[loc][1] = b;
			tree[loc*2][0] = b;
		}
		char c;
		cin >> c;
		if (c == '.'){}
		else
		{
			tree[loc][2] = c;
			tree[loc * 2 + 1][0] = c;
		}
	}

	int start = 1;
	preorder(start);
}