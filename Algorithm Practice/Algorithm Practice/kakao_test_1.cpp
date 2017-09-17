#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
int final[16][16];
int input[16];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	printf("n is %d \n", n);

	for (int i = 0; i < n; i++)
	{
		//arr1
		int temp = arr1[i];
		printf("temp is %d \n", temp);
		int last = n - 1;
		while (temp > 0)
		{
			input[last] = temp % 2;
			temp = temp / 2;
			last -= 1;
		}
		for (int j = last; j >= 0; j--)
			input[j] = 0;
		for (int j = 0; j < n; j++)
		{
			if (input[j] == 1)
				final[i][j] = 1;
		}

		//arr2
		temp = arr2[i];
		last = n - 1;
		while (temp > 0)
		{
			input[last] = temp % 2;
			temp = temp / 2;
			last -= 1;
		}
		for (int j = last; j >= 0; j--)
			input[j] = 0;
		for (int j = 0; j < n; j++)
		{
			if (input[j] == 1)
				final[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		string line;
		for (int j = 0; j < n; j++)
		{
			if (final[i][j] == 1)
				line.append("#");
			else
				line.append(" ");
		}
		answer.push_back(line);
	}
	return answer;
}

int main()
{
	vector<int> arr1;
	vector<int> arr2;

	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	vector<string> answer = solution(5, arr1, arr2);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}