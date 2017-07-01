/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
char input[1000000];
bool check[1000000];
stack<char> sta;
stack<int> last;

int Answer;

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
	int n;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%s", input);
		n = strlen(input);
		sta.push(input[0]);
		int last_loc = 0;
		last.push(0);
		for (int i = 1; i < n; i++)
		{
			//printf("last loc is %d \n", last_loc);
			char top = '*';
			if(!sta.empty())
				top = sta.top();
			if (input[i] == ')' && top == '(')
			{
				sta.pop();
				if(!last.empty())
				{
					last_loc = last.top();
					last.pop();
				}
				check[i] = true;
				check[last_loc] = true;
			}
			else if (input[i] == '}' && top == '{')
			{
				sta.pop();
				if (!last.empty())
				{
					last_loc = last.top();
					last.pop();
				}
				check[i] = true;
				check[last_loc] = true;
			}
			else if (input[i] == ']' && top == '[')
			{
				sta.pop();
				if (!last.empty())
				{
					last_loc = last.top();
					last.pop();
				}
				check[i] = true;
				check[last_loc] = true;
			}
			else
			{
				sta.push(input[i]);
				last.push(i);
			}
		}
		int length = 0;
		for (int i = 0; i < n; i++)
		{
			if (check[i] == true)
				length++;
			else
				length = 0;
			//printf("i is %d length is %d \n", i, length);
			if (length > Answer)
				Answer = length;
		}
		while (!sta.empty())
			sta.pop();
		while (!last.empty())
			last.pop();
		for (int i = 0; i < n; i++)
			check[i] = false;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}