/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
int input[100000];

using namespace std;

int Answer;

int main()
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, s;
		scanf("%d %d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d", &input[i]);
		int sum = 0;
		int count = 0;
		vector<int> v;
		for (int i = 0; i<n; i++)
		{
			sum += input[i];
			count++;

			while (sum >= s)
			{
				v.push_back(count);
				sum -= input[i + 1 - count];
				count--;
			}
		}
		if (count == n)
			v.push_back(0);
		sort(v.begin(), v.end());
		// Print the answer to standard output(screen).
		cout << "#testcase" << test_case + 1 << endl;
		cout << v[0] << endl;
		v.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}