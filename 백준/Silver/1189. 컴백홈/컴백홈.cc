#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

using namespace std;

int r,c,k;
int cnt =0;

// void	print_map(vector<vector<int>> arr)
// {
// 	for (int i=0;i < r;i++)
// 	{
// 		for (int j =0;j < c;j++)
// 		{
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
// }

void dfs(int x,int y,vector<vector<int>> arr,int depth)
{
	// cout << depth<< "\n";
	// print_map(arr);
	if (x == c-1 && y == 0)
	{
		if (depth == k)
			cnt++;
		return;
	}
	else if (depth == k)
		return ;
	for (int i=0;i <4;i++)
	{
		if (x + dx[i] < 0 || x + dx[i] >= c || y + dy[i] <0 || y + dy[i] >= r)
			continue;
		if (arr[y + dy[i]][x + dx[i]] == 0)
		{
			arr[y + dy[i]][x + dx[i]] = 1;
			dfs(x + dx[i],y + dy[i],arr,depth+1);
			arr[y + dy[i]][x + dx[i]] = 0;
		}
	}
}
int main()
{
	ios:: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> r >> c >> k;
	vector arr(r,vector<int>(c,0));
	for (int i=0;i < r;i++)
	{
		string s;
		cin >> s;
		for (int j=0; j<c;j++)
		{
			if (s[j] == '.')
				arr[i][j] = 0;
			else if (s[j] == 'T')
				arr[i][j] = -1;
		}
	}
	arr[r-1][0] =1;
	dfs(0,r -1,arr,1);
	cout << cnt;
}
