#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
string cache[30];
int last[30];

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int loc = 0;
	int size = 0;
	int len = cities.size();
	cout << 1 << endl;
	for (int i = 0; i < len; i++)
	{
		cout << i << endl;
		string input = cities[i];
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		cout << "input is " << input << endl;
		bool test = false;
		for (int j = 0; j<size; j++)
		{
			cout << cache[j] << endl;
			if (input.compare(cache[j]) == 0)
			{
				answer += 1;
				test = true;
				last[j] = i;
				break;
			}
		}
		//cache에 현재 문자열이 없을 때
		if (test == false)
		{
			if (size == cacheSize)
			{
				int temp = last[0];
				int loc = 0;
				for (int j = 1; j < size; j++)
				{
					if (last[j] < temp)
					{
						temp = last[j];
						loc = j;
					}
				}
				cache[loc] = input;
				last[loc] = i;
			}
			else
			{
				cache[size] = input;
				last[size] = i;
				size++;
			}
			answer += 5;
		}
		printf("%d \n", answer);
	}


	return answer;
}

int main()
{
	vector<string> a;
	a.push_back("jeJu");
	a.push_back("Pangyo");
	a.push_back("Seoul");
	a.push_back("NewYork");
	a.push_back("LA");
	a.push_back("Jeju");
	a.push_back("Pangyo");
	a.push_back("Seoul");
	a.push_back("NewYork");
	a.push_back("LA");
	int t = solution(3, a);
	cout << t;
}