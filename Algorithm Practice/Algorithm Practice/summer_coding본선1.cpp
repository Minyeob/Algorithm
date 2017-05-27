using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n > 0)
	{
		while (n % 2 == 0)
			n /= 2;
		n = n - 1;
		ans += 1;
	}

	return ans;
}