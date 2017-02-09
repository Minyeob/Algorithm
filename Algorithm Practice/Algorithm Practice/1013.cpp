#include <cstdio>
char s[402];

int next[11][2];

int main()
{
	next[1][1] = 2;
	next[1][0] = 3;
	next[3][1] = 10;
	next[10][0] = 3;
	next[10][1] = 2;
	next[2][0] = 4;
	next[4][0] = 5;
	next[5][0] = 5;
	next[5][1] = 6;
	next[6][0] = 3;
	next[6][1] = 7;
	next[6][0] = 3;
	next[7][1] = 7;
	next[7][0] = 8;
	next[8][1] = 10;
	next[8][0] = 9;
	next[9][0] = 9;
	next[9][1] = 6;

	scanf("%s", s);

	int j = 0;
	bool check = false;
	int k = 1;

	while (s[j] != '\0')
	{
		k = next[k][s[j]-48];
		//printf("s[j]  is %d  k is %d\n", s[j]-48,k);
		if (k == 0)
		{
			printf("NOISE\n"); 
			check = true;
			break;
		}
		j++;
	}
	if (k == 6 || k==7 || k==10)
		printf("SUBMARINE\n");
	else if (check==false)
		printf("NOISE\n");
			
}