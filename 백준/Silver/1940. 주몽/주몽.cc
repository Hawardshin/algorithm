#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> input_ar;
int main()
{
	cin.tie(0);
	ios :: sync_with_stdio(0);
	int n,m,input;
	int cnt =0;
	cin >> n >> m;
	for (int i=0;i <n;i++)
	{
		cin >> input;
		input_ar.push_back(input);
	}
	sort(input_ar.begin(), input_ar.end());
	for (int i =0; i < n;i++)
	{
		for (int j=n-1;j > i;j--)
		{
			if (input_ar[j] + input_ar[i] == m)
				cnt++;
			// else if (input_ar[j] +input_ar[i] < m)
			// 	break;
		}
	}
	cout << cnt;
}
