#include <cstdio>
#include <algorithm>
using namespace std;

int input[9];
int temp[9];

int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	sort(input, input + n);
	int max = 0;
	int count = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			sum += abs(input[i] - input[i + 1]);
		}
		if (sum > max)
			max = sum;
	} while (next_permutation(input, input + n));	//next_permutation을 실행하면 first부터 last까지 현재 수의 조합부터 내림차순으로 permutation을 수행한다
	//next_permutation(start,end) 범위에 있는 원소들의 다음으로 큰 사전식 순열 생성 - 사전의 형태로 현재보다 사전의 뒤에 있는 경우의 
	//따라서 next_permutation으로 모든 경우의 수를 확인하기 위해서는 sort를 통해 오름차순으로 순서를 바꾼 뒤 수행하면 모든 경우의 수를 확인할 수 있다.
	printf("%d", max);
}