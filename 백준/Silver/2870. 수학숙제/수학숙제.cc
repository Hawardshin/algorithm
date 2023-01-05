#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void s_toi(string s,vector <string> &arr)
{
	char ar[100];
	int aridx=0;
	int size = s.size();
	long long  ret =0;
	int flag = 0;
	for (int i=0;i <size;i++)
	{
		if ('0'<=s[i] && s[i] <='9')
		{
			flag =1;
			if (aridx == 0 && i  != size - 1 &&  s[i] == '0' )
			{
				continue;
			}
			ar[aridx] = s[i];
			aridx++;
			if (i == size -1)
			{
				if (flag == 1 && aridx == 0)
				{
					ar[aridx] ='0';
					aridx ++;
				}
				ar[aridx] = '\0';
				arr.push_back(ar);
			}
		}
		else if (flag == 1)
		{
			if (flag == 1 && aridx == 0)
			{
					ar[aridx] ='0';
					aridx ++;
			}
			ar[aridx] = '\0';
			arr.push_back(ar);
			aridx = 0;
			flag =0;
		}
	}
}

int cmp(string a1, string a2)
{
	if (a1.size() > a2.size())
		return (0);
	else if (a1.size() < a2.size())
		return (1);
	for (int i=0; i < a1.size();i++)
	{
		if (a1[i] != a2[i])
		{
			return(a1[i] < a2[i]);
		}
	}
	return (1);
}
int main()
{
	ios:: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <string> arr;
	for (int i=0;i < n; i++)
	{
		string s;
		cin >> s;
		s_toi(s,arr);
	}
	sort (arr.begin(),arr.end(),cmp);
	for (auto it : arr)
	{
		cout << it << "\n";
	}
}
