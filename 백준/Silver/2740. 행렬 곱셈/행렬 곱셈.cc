#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

int first[101][101];
int second[101][101];

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int	n;
	int m;
	cin >> n >> m;
	for (int i=0; i < n; i++)
	{
		for (int j =0; j < m; j++)
		{
			cin >> first[i][j];
		}
	}
	int m1, k;
	cin >> m1 >> k;
	for(int i = 0; i < m1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> second[i][j];
		}
	}
	long long re = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j < k; j++)
		{
			re = 0;
			for (int c = 0; c < m1; c++)
			{
				re += first[i][c] * second[c][j];
			}
			cout << re << " ";
		}
		cout << "\n";
	}

}