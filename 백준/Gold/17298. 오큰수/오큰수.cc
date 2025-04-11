#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<utility>
#include<string.h>

using namespace std;

int result[1000000];
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int,int>> input;
	int num;
	cin >> num;
	int tmp;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		if (input.empty() || input.top().second >= tmp)
		{
			input.push(make_pair(i,tmp));
		}
		else
		{
			while (!input.empty() && input.top().second < tmp)
			{
				result[input.top().first] = tmp;
				input.pop();
				//cout << tmp;
			}
			input.push(make_pair(i,tmp));
		}
	}
	while (!input.empty())
	{
		result[input.top().first] = -1;
		input.pop();
	}
	for (int i =0; i < num; i++)
	{
		cout << result[i] << ' ';
	}
}