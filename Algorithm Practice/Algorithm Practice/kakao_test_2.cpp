#include <string>
#include <cctype>
int score[3];

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int loc = 0;
	int score_loc = 0;
	while (score_loc < 3)
	{
		int input = dartResult[loc]-'0';
		loc++;
		if (isdigit(dartResult[loc]))
		{
			input = 10;
			loc++;
		}
		char bonus = dartResult[loc];
		loc++;
		if (bonus == 'D')
			input = input * input;
		else if (bonus == 'T')
			input = input * input * input;
		score[score_loc] = input;
		//특별효과가 있을 때
		if (dartResult[loc])
		{
			if (!isdigit(dartResult[loc]))
			{
				char special = dartResult[loc];
				loc++;
				if (special == '#')
					score[score_loc] = -score[score_loc];
				else if (special == '*')
				{
					score[score_loc] = score[score_loc]*2;
					if(score_loc>0)
						score[score_loc-1]= score[score_loc-1] * 2;
				}
			}
		}
		printf("%d\n", score[score_loc]);
		score_loc++;
	}
	answer = score[0] + score[1] + score[2];
	
	return answer;
}

int main()
{
	string input = "1S2D*3T";
	int score = solution(input);
	printf("%d", score);
}