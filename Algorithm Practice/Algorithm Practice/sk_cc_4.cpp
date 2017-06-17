#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> truck, vector<int> w) {
	vector<int> answer;
	int n = truck.size();
	int m = w.size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == n)
			{
				answer.push_back(-1);
				break;
			}
			if (truck[j] >= w[i])
			{
				truck[j] -= w[i];
				answer.push_back(j + 1);
				break;
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> truck;

	truck.push_back(1);
	truck.push_back(4);
	truck.push_back(5);
	truck.push_back(2);
	truck.push_back(4);

	vector<int> w;
	w.push_back(2);
	w.push_back(4);
	w.push_back(4);
	w.push_back(3);
	w.push_back(2);
	
	solution(truck, w);
}