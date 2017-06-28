/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int Answer,now;

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

		Answer = 0;
		now = 0;
		int n;
		int temp;
		int k;
		int last = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			q.push(temp);
			last = temp;
		}
		scanf("%d", &k);
		int goal = 0;
		while (!q.empty())
		{
			temp = q.front();
			while (now + k >= temp)
			{
				if (temp == goal)
					break;
				goal = temp;
				q.pop();
				if(!q.empty())
					temp = q.front();
			}
			if (now == goal)
				break;
			else
			{
				Answer++;
				now = goal;
			}
		}
		while (!q.empty())
			q.pop();

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		if (now == last)
			cout << Answer << endl;
		else
			cout << -1 << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}