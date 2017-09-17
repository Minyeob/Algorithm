#include <string>
#include <vector>
#include <iostream>
#include <cctype>
int first[10000];
int second[10000];
int final[10000];

using namespace std;
vector<int> one;
vector<int> two;

int solution(string str1, string str2) {
	int answer = 0;
	int len = str1.size();
	for (int i = 0; i < len - 1; i++)
	{
		if (!isalpha(str1[i]))
			continue;
		int a = toupper(str1[i]) * 100;
		if (!isalpha(str1[i + 1]))
			continue;
		int b = toupper(str1[i + 1]);
		int num = a + b;
		first[num]++;
		one.push_back(num);
		if (final[num] < first[num])
			final[num] = first[num];
	}

	int len2 = str2.size();
	for (int i = 0; i < len2 - 1; i++)
	{
		if (!isalpha(str2[i]))
			continue;
		int a = toupper(str2[i]) * 100;
		if (!isalpha(str2[i + 1]))
			continue;
		int b = toupper(str2[i + 1]);
		int num = a + b;
		second[num]++;
		two.push_back(num);
		if (final[num] < second[num])
			final[num] = second[num];
	}

	int bingo = 0;
	int entire = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (first[i] > 0 && second[i] > 0)
		{
			int temp = first[i];
			if (first[i] > second[i])
				temp = second[i];
			bingo += temp;
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (final[i] > 0)
			entire += final[i];
	}
	cout << "bingo is " << bingo << "entire is " << entire << endl;
	float ans = 65536;
	if(entire>0)
		ans = bingo * 65536 / entire;
	//cout << "ans is " << ans << endl;
	answer = (int)ans;
	return answer;
}

int main()
{
	string str1 = "E=M*C^2";
	string str2 = "e=m*c^2";
	int ans = solution(str1, str2);
	cout << ans;
	
}