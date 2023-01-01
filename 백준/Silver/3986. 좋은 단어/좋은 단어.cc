#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

stack <char> a;

int check(string s)
{
	if (s.size()%2 != 0)
		return (0);
	for (auto it : s)
	{
		if (a.empty())
			a.push(it);
		else if (a.top() == it)
			a.pop();
		else
			a.push(it);
	}
	char c1,c2;
	while (!a.empty())
	{
		 c1 = a.top();
		 a.pop();
		 if (a.empty())
		 	return (0);
		c2 = a.top();
		a.pop();
		 if (c1 != c2)
		 {
			while (!a.empty())
			{
				a.pop();
			}
			return (0);
		 }
	}
	return (1);
}

int main()
{
	int n;
	ios :: sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n;
	int	cnt =0;
	for (int i=0;i < n; i++)
	{
		cin >> s;
		if (check(s))
			cnt++;
	}
	cout << cnt;
}
