#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;


// unsigned long long fac(int n)
// {
// 	if (n == 0)
// 		return (1);
// 	else if (n == 1)
// 		return (1);
// 	return (n* fac(n -1));
// }

int two;
int five;
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	int count = 0;
	//num = fac(num);
	for (int i = num; i > 0; i--)
	{
		int tmp = i;
		while (tmp % 2 == 0 && tmp)
		{
			tmp /= 2;
			two++;
		}
		while (tmp % 5 == 0 && tmp)
		{
			tmp /= 5;
			five++;
		}
	}
	cout << min(two,five);
}