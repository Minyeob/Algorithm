#include <cstdio>
#include <vector>
using namespace std;
bool check[1000001];
vector<int> v;

int main()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (check[i]==false)
		{
			for (int j = i*i; j < 1000001; j=j+i)
			{
				check[j] = true;
				//printf("%d\n", num);
			}
		}
	}

	for (int i = 3; i < 1000001; i++)
	{
		if (i % 2 == 1 && check[i] == false)
			v.push_back(i);
	}

	int input;
	scanf("%d", &input);
	while (input != 0)
	{
		bool test = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= input)
				break;
			int other = input - v[i];
			if (check[other] == false)
			{
				test = true;
				printf("%d = %d + %d\n", input, v[i], other);
				break;
			}
		}
		if (test == false)
			printf("Goldbach's conjecture is wrong.\n");

		scanf("%d", &input);
	}
}