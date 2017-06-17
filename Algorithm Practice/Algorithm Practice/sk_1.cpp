#include <string>
#include <cstdio>
using namespace std;
int input[10];

int solution(string N) {
	int answer = 0;
	for (int i = 0; i < N.length(); i++)
		input[N[i] - '0']++;
	for (int i = 1; i < 10; i++)
	{
		answer += (input[i] / 2)*2;
	}
	if (answer == 0)
		answer = 1;
	else
	{
		answer += (input[0] / 2)*2;
		for (int i = 0; i < 10; i++)
		{
			if (input[i] % 2 == 1)
			{
				answer += 1;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	string A = "123333";
	int a = solution("123300");
	printf("%d", a);
}