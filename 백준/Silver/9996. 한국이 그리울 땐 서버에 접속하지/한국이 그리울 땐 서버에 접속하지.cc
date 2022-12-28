#include <iostream>
#include <string>

using namespace std;
char result[101];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string input;
	cin >>input;
	string head;
	string tail;
	for (int i=0; i < input.size(); i++)
	{
		if (input[i] == '*')
		{
			head = input.substr(0, i);
			tail = input.substr(i+1, input.size());
			break;
		}
	}
	string cmp;
	int i;
	for (i=0; i < n; i++)
	{
		cin >> cmp;
		if (cmp.size() < head.size() + tail.size())
		{
			result[i] = 2;
		}
		else
		{
			if (cmp.substr(0,head.size()) == head && cmp.substr(cmp.size() - tail.size(), tail.size()) == tail)
				result[i] = 1;
			else
				result[i] = 2;
		}
	}
	for (int j =0; j < i; j++)
	{
		if (result[j] == 1)
			cout << "DA\n";
		else if (result[j] == 2)
			cout << "NE\n";
	}

}
