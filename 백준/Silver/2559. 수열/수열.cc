#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int day;
	int c_time;
	cin >> day >> c_time;
	vector<int> tp(day, -2147483647);
	vector<int> sum(day, -2147483647);
	for (int i=0 ;i < day;i++)
	{
		cin >> tp[i];
		if (i == c_time -1)
		{
			sum[i] =0;
			for (int j = 0; j < c_time; j++)
			{
				sum[i]+= tp[j];
			}
		}
		else if (i >= c_time)
			sum[i] = sum[i - 1] + tp[i] - tp[i-c_time];
		// cout << sum[i] << " ";
	}
	sort(sum.begin(), sum.end(),greater<int>());
	cout << sum[0];
}
