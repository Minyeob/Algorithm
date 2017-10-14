#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
* Description :
* Time complexity :
* Space complexity :
*/
int calc(vector<int> &numbers) {
	// TODO : implement your codes to here.
	int len = numbers.size();
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum + numbers[i];
	}
	int count = 0;
	while (sum / len < 9.5)
	{
		sum = sum + 10;
		len++;
		count++;
	}
	return count;
}

int main(int argc, const char* argv[]) {
	int n = 0;
	cin >> n;

	vector<int> numbers;
	for (int i = 0; i<n; i++) {
		int score = 0;
		cin >> score;
		numbers.push_back(score);
	}

	cout << calc(numbers) << endl;
}