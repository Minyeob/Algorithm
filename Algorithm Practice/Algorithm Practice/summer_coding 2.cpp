#include <vector>
#include <cstdio>
using namespace std;
int point[100001];
bool check[100001];

int solution(vector<int> sticker)
{
	int answer = 0;
	point[1] = sticker[0];
	for (int i = 1; i < sticker.size()-1; i++)
	{
		if (point[i] < point[i - 1] + sticker[i])
		{
			point[i + 1] = point[i - 1] + sticker[i];
		}
		else
			point[i + 1] = point[i];
	}
	int max= point[sticker.size()-1];


	if(sticker.size()>1)
	{	
		point[1] = 0;
		point[2] = sticker[1];
		for (int i = 2; i < sticker.size(); i++)
		{
			if (point[i] < point[i - 1] + sticker[i])
			{
				point[i + 1] = point[i - 1] + sticker[i];
			}
			else
				point[i + 1] = point[i];
		}
	}

	if (max < point[sticker.size()])
		max = point[sticker.size()];

	answer = max;
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(1);

	int a = solution(v);
	printf("%d", a);
}