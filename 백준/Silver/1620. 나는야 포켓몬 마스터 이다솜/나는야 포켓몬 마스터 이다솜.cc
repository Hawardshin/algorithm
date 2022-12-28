#include <iostream>
#include <map>
#include <string>
#include<sstream>
using namespace std;

 map <string, int> dic;

// int s_to_num(string s)
// {
//         istringstream ss(s);
//         int x;
//         ss >> x;
//         return (x);
// }
string arr[1000000];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int in_num;
	int f_num;
	string s;
	cin >>  in_num >> f_num;
	for (int i = 1; i <=in_num;i++)
	{
		cin >> s;
		arr[i] = s;
		dic.insert({s,i});
	}
	for (int i=0; i < f_num;i++)
	{
		cin >> s;
		if ('0'<=s[0]&& s[0]<='9')
			cout << arr[stoi(s)] << "\n";
		else
			cout << (int)(dic.find(s)->second) << "\n";
	}
}