#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char result[52];
int	a,b;
int	next_two_same(char a,char b)
{
	return (a == b);
}

int main()
{
	string s;
	cin >>s;
	sort(s.begin(), s.end());
	b = s.size() - 1;
	int	num = 1;
	int flag =0;
	int i =0;
	while (i < s.size())
	{
		if (i + 1 >= s.size())
		{
			result[a] = s[i];
			if (flag)
			{
				cout << "I'm Sorry Hansoo\n";
				return (0);
			}
		}
		if (next_two_same(s[i],s[i+1]))
		{
			result[a] = s[i];
			result[b] = s[i];
			a++;
			b--;
			i+= 2;
		}
		else
		{
			if (flag)
			{
				cout << "I'm Sorry Hansoo\n";
				return (0);
			}
			result[s.size()/2] = s[i];
			flag = 1;
			i++;
		}
	}
	cout << result;
}
