#include <iostream>

using namespace std;

int A;
long long result(long long n )
{
	if (n == 1 || A == 1)
		return (1);
	else
	{
		for (long long i =0;i < 10; i++)
		{
			if (((A * i) + n) % 10 == 1)
			{
				return (result(((A * i) + n)/10) +1);
			}
		}
	}
}

int main()
{


	while (cin >> A)
	{
		cout << result(0)<< "\n";
	}
}
