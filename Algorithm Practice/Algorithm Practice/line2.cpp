#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

/*
* Description :
* Time complexity :
* Space complexity :
*/
int calc(long long n) {
	/* TODO implement your codes to here. */
	int count = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		int rem = n%i;
		if (rem == 0)
		{
			if (i*i == n)
				count++;
			else
				count = count + 2;
		}
	}
	return count;
}

int main(int argc, const char *argv[]) {
	long long n = 0;
	cin >> n;

	cout << calc(n) << endl;
}