#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	ios:: sync_with_stdio(0);

	string s;
	getline(cin, s);
	// for (auto it : s)
	// {
	// 	if ('a'<= it && it <= 'a' + 12)
	// 		it +=13;
	// 	else if ('a' + 13<= it && it <= 'z')
	// 		it -=13;
	// 	else if ('A'<= it && it <= 'A' + 12)
	// 		it +=13;
	// 	else if ('A' + 13<= it && it <= 'Z')
	// 		it -=13;
	// }
	// cout << s;
	for (int i=0; i < s.size(); i++)
	{
		if ('a'<= s[i] && s[i] <= 'a' + 12)
			s[i] +=13;
		else if ('a' + 13 <= s[i] && s[i] <= 'z')
			s[i] -=13;
		else if ('A'<= s[i] && s[i] <= 'A' + 12)
			s[i] +=13;
		else if ('A' + 13<= s[i] && s[i] <= 'Z')
			s[i] -=13;
	}
	cout << s;
}
