#include <iostream>
#include <string>

using namespace std;
int check_pel(string &s)
{
	int first= 0;
	int last = s.size();
	last--;

	while (first < s.size()/2)
	{
		if (s[first] != s[last])
			return (0);
		first++;
		last--;
	}
	return (1);
}

int main()
{
	string s;
	cin >> s;
	cout << check_pel(s);
}
