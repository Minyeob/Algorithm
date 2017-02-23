#include <cstdio>
#include <iostream>

using namespace std;
int head[300001];
int input[300001];

int find(int loc,int size)
{
	int next = head[loc];
	if (input[next] == 0)
		return 0;
	else if (input[next] >= size)
	{
		return next;
	}
	else if (input[next] < size)
		return find(next, size);
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &input[i]);
		}

		for (int i = 2; i <= n; i++)
		{
			if (input[i] > input[i - 1])
			{
				head[i] = find(i - 1, input[i]);
			}
			else
				head[i] = i - 1;
			//printf("%d 's   head is %d  \n", i, head[i]);
		}

		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum = sum + head[i];
		}



		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%lld\n", sum);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}