#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int origin[31];
bool result[15001];

int main()
{
	v.push_back(0);
	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		int a;
		scanf("%d", &a);
		origin[i] = a;
		int size = v.size();
		//printf("size is %d\n", size);
		for (int j = 0; j < size; j++)
		{
			int sum = v[j] + a;
			if (result[sum] == false)
			{
				v.push_back(sum);
				result[sum] = true;
			}
			//printf("sum is %d\n", sum);
			sum = abs(v[j] - a);
			//printf("sum is %d\n", sum);
			if (result[sum] == false)
			{
				v.push_back(sum);
				result[sum] = true;
			}
		}
	}
	std::sort(origin, origin+number);
	
	//printf("size is %d", v.size());
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a > 15000)
		{
			printf("N ");
			continue;
		}
		if (result[a] == true)
			printf("Y ");
		else
			printf("N ");
	}
}