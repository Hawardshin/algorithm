#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>
#include <tuple>
using namespace std;

int dp[10000]; // 배점 /시간 , 배점 , 시간
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int subject ,time;
	cin >> subject >> time;
	int s_time, score;
	pair <int , int > arr[101];
	for (int i=0; i< subject; i++)
	{
		cin >> s_time >> score;
		arr[i] = make_pair(s_time,score);
	}
	sort(arr,arr+ subject);
	for (int i = 0; i < subject; i++)
	{
		int fa = arr[i].first;
		int sa = arr[i].second;
		for (int j = time; j >= fa; j--)
		{
			dp[j] = max(dp[j],dp[j - fa] + sa);
		}
	}
	cout << dp[time];
}
