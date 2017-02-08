#include <cstdio>
#include <cmath>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		int distance = end - start;
		//printf("distance is %d\n", distance);

		//최소의 경우는 n제곱이므로 n제곱이하인 수를 찾는다
		int num = sqrt(distance);
		//printf("num is %d\n", num);

		int sum = 2 * num - 1;
		//printf("sum is %d\n", sum);
		int remain = distance - num*num;
		//printf("remain is %d\n", remain);
		sum = sum + (remain / num);
		while (remain%num != 0)
		{
			//printf("remain is %d\n", remain);
			remain = remain%num;
			num = num - 1;
			sum = sum + remain / num;
			if (num == 1)
				break;
		}
		printf("%d\n", sum);
	}
}