/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>

using namespace std;

int Answer;
long long input[100000];

int main(int argc, char** argv)
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
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &input[i]);
		}
		long long dif = 1000000000000;
		for (int i = 0; i < n-1; i++)
		{
			long long temp = input[i + 1] - input[i];
			if (temp < dif)
				dif = temp;
		}
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		if (dif == 0)
		{
			bool check = true;
			for (int i = 0; i < n-1; i++)
			{
				if (input[i + 1] != input[i])
				{
					check = false;
					break;
				}
			}
			if (check == true)
				Answer = 1;
		}
		else
		{
			for (int i = 1; i <= dif; i++)
			{
				if (dif%i == 0)
					Answer++;
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}