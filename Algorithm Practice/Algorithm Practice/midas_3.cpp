#include <cstdio>
#include <algorithm>
using namespace std;
int input[101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	sort(input, input + n);

	int count = 0;
	int loc = 0;
	while (loc < n)
	{
		count++;
		int now = input[loc];
		while (loc < n)
		{
			loc = loc + 1;
			if (input[loc] > now + 4)
				break;
		}
	}
	printf("%d", count);
}