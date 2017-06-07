#include <cstdio>
#include <map>
using namespace std;
map<long long, long long> trans;
#define div 1000000007LL;

long long fibo(long long n)
{
	if (n == 1 || n == 2)
		return 1;
	else if (trans[n])
		return trans[n];
	else
	{
		if (n % 2 == 1)
		{
			long long m = (n + 1) / 2;
			long long result = fibo(m)*fibo(m) + fibo(m - 1)*fibo(m - 1);
			trans[n] = result%div;
			return result%div;
		}
		if (n % 2 == 0)
		{
			long long m = n / 2;
			long long result = (fibo(m - 1) + fibo(m + 1))*fibo(m);
			trans[n] = result%div;
			return result%div;
		}
	}
}

int main()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld", fibo(n));
}