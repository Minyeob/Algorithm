/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
int input[5][3];
long long record[5];
int final[5];

using namespace std;

struct box {
	int width;
	int height;
};

long long Answer;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int r = a%b;
	a = b;
	b = r;
	gcd(a, b);
}

int lcm(int a, int b)
{
	int c = a / gcd(a, b);
	int d = b / gcd(a, b);
	return gcd(a, b)*c*d;
}

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
			scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
		}

		Answer = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < 10000000; j++)
			{
				record[i] = (input[i][0] * j + input[i][2]) % input[i][1];
				if (record[i] == 0)
				{
					final[i] = j;
					//printf("i is %d j is %d \n", i, j);
					break;
				}
			}
		}

		long long max = final[0];
		for (int i = 1; i < n; i++)
		{
			max = lcm(max, final[i]);
		}
		printf("max is %d \n", max);

		for (int i = 1; i <= 5000000; i++)
		{
			bool check = true;
			for (int j = 0; j < n; j++)
			{
				record[j] = (input[j][0] * i*max + input[j][2]) % input[j][1];
				printf("div is %lld record is %d \n", max*i, record[j]);
				if (record[j]!=0)
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				Answer = i*max;
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}