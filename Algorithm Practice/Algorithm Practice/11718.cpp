#include <cstdio>
#include <iostream>

int main()
{
	char temp[102];
	while (std::cin.getline(temp,102))
	{
		printf("%s\n", temp);
		for (int i = 0; i < 101; i++)
		{
			temp[i] = 0;
		}
	}
}