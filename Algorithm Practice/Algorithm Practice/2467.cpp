#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> minu;
vector<int> plu;

int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp >= 0)
			plu.push_back(temp);
		else
			minu.push_back(temp);
	}

	int final = 2e9;
	int ans_one = 0;
	int ans_two = 0;
	int minu_size = minu.size();
	int plu_size = plu.size();
	if (minu_size == 0)
	{
		printf("%d %d", plu[0], plu[1]);
	}
	else if (plu_size == 0)
	{
		printf("%d %d", minu[minu_size - 2], minu[minu_size - 1]);
	}
	else
	{
		int loc = 0;
		for (int i = minu_size-1; i >= 0; i--)
		{
			int first = minu[i];
			for (int j = loc; j < plu_size; j++)
			{
				int sum = first + plu[j];
				if (abs(sum) < final)
				{
					final = abs(sum);
					ans_one = first;
					ans_two = plu[j];
				}
				if (sum >= 0)
				{
					loc = j;
					break;
				}
			}
		}
		printf("%d %d", ans_one, ans_two);
	}

}
