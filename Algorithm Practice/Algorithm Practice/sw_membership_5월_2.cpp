/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
pair<int, int> p[200001];
int Answer;
int r,s,n;
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
		int loc = 0;
		scanf("%d", &n);
		for (int i = 0, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			if (y - x > 1)
			{
				//printf("x is %d y is %d \n", x, y);
				p[loc] = { x,1 };
				p[loc + 1] = { y,2 };
				loc = loc + 2;
			}
		}
		sort(p, p + loc);
		for (int i = 0; i < loc; i++) {
			if (p[i].second == 1)
				s += 1;
			else
				s -= 1;
			r = max(r, s);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << r << endl;
		r = 0;
		s = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}