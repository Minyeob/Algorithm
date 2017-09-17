#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> input;
int ranking[2000];
int car[2000];

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	int len = timetable.size();
	for (int i = 0; i < len; i++)
	{
		string temp = timetable[i];
		int si = (temp[0] - '0') * 10 + (temp[1] - '0');
		int min = (temp[3] - '0') * 10 + (temp[4] - '0');
		//cout << si << "  " << min << endl;
		int t = si * 60 + min;
		//cout << t << endl;
		input.push_back(t);
	}
	sort(input.begin(), input.end());

	int loc = 0;
	for (int i = 0; i < n; i++)
	{
		int check = 9 * 60 + t*i;
		for (int j = 0; j < m; j++)
		{
			if (input[loc] <= check)
			{
				car[loc] = i + 1;
				ranking[loc] = j + 1;
				loc++;
				if (loc == input.size())
					break;
			}
			else
				break;
		}
	}

	int last = loc - 1;
	if (loc == 0)
		last = loc;
	int final = 9 * 60 + (n - 1)*t;
	cout << final << endl;
	//cout << "last is " << ranking[last] << endl;
	if (ranking[last] == m && car[last] == n)
	{
		if (input[last] <= final)
			final = input[last] - 1;
	}
	int min = final % 60;
	int si = final / 60;
	answer.push_back(si / 10 + '0');
	answer.push_back(si % 10 + '0');
	answer.push_back(':');
	answer.push_back(min / 10 + '0');
	answer.push_back(min % 10 + '0');

	return answer;
}