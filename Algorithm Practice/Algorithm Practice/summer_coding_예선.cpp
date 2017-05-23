#include <vector>
#include <cstdio>
using namespace std;
bool check[20000001];

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < stations.size(); i++)
	{
		int loc = stations[i];
		check[loc] = true;
		for (int j = 1; j <= w; j++)
		{
			printf("loc is %d \n", loc);
			if (loc - j > 0)
				v.push_back(loc - j-1);
			if (loc + j < n + 1)
				v.push_back(loc + j);
		}
	}

	int loc = 1;
	for (int i = 0; i < v.size() - 1; i++)
	{
		int len = v[i + 1] - v[i];
		answer = answer + len / (2 * w + 1);
		if (len % (2 * w + 1) > 0)
			answer++;
	}
	printf("anwser is %d \n", answer);
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(11);
	int a = solution(11, v, 1);
	printf("%d",a);
}


