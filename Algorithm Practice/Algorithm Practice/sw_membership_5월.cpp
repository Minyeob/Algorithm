/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <queue>
char board[3][7];


using namespace std;
queue<char> q;
queue<char> alpha;
int Answer;

char move(int a,int b)
{
	int x = a - 1;
	if (x < 0)
		x = x + 3;
	int y = b + 1;
	if (y > 6)
		y = y - 7;

	return board[x][y];
}

char next(char a)
{
	return a + 1;
}

struct popo
{
	char str[100];
	int size;
};

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

	board[0][0] = 'Q';
	board[0][1] = 'W';
	board[0][2] = 'E';
	board[0][3] = 'R';
	board[0][4] = 'R';
	board[0][5] = 'T';
	board[0][6] = 'Y';

	board[1][0] = 'A';
	board[1][1] = 'S';
	board[1][2] = 'D';
	board[1][3] = 'F';
	board[1][4] = 'G';
	board[1][5] = 'H';
	board[1][6] = 'J';

	board[2][0] = 'Z';
	board[2][1] = 'X';
	board[2][2] = 'C';
	board[2][3] = 'V';
	board[2][4] = 'B';
	board[2][5] = 'N';
	board[2][6] = 'M';

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d");
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer = 0;
		char first, second;
		scanf("%c %c", &first,&second);
		char full[100];
		int loc = 0;

		full[loc] = first;
		loc++;
		


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}