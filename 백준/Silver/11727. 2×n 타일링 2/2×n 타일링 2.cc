#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
int Dp[1001] = {0, 1, 3};

int f(int n)
{
	if (Dp[n])
		return(Dp[n]);
	Dp[n] = (f(n-1) % 10007 + 2 *f(n-2) % 10007) % 10007;
	return (Dp[n]);
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << f(n) << endl;
	return (0);
}