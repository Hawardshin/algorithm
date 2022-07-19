#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;

int dp[11];

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int sum;
	sum = 0;
	for (int i = 4; i< 11; i++)
		dp[i] = dp[i -1] + dp [i -2] + dp[i -3];
	for (int i=0; i< num; i++)
	{
		int in;
		cin >> in;
		cout << dp[in] << '\n';
	}
}
