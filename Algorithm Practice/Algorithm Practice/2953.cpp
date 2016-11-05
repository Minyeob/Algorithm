#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int score[5][5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
		score[i][4] = score[i][0] + score[i][1] + score[i][2] + score[i][3];
	}

	int maxscore = score[0][4];
	int maxloc = 0;
	
	for (int i = 1; i < 5; i++)
	{
		if (maxscore < score[i][4])
		{
			maxscore = score[i][4];
			maxloc = i;
		}
	}

	printf("%d %d", maxloc + 1, maxscore);

	return 0;
}