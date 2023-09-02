#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int main()
{
	int n,m;
	string s;

	cin >> n >> m;
	vector<vector<int>> arr(n + 1,vector<int>(m + 1,0));
	vector<vector<int>> vis(n + 1,vector<int>(m + 1,0));
	for (int i=0;i < n;i++)
	{
		cin >> s;
		for (int j=0;j < m; j++)
		{
			arr[i+ 1][j + 1] = s[j];
		}
	}
	queue <pair <int,int >> Q;
	Q.push({1,1});
	vis[1][1] = 1;
	while (!Q.empty())
	{
		pair<int,int> qu = Q.front();
		Q.pop();
		int X = qu.second;
		int Y = qu.first;
		if (Y == n && X== m)
		{
			cout << vis[Y][X] << "\n";
			return (0);
		}
		for (int i =0; i < 4;i++)
		{
			if (X + dx[i] <= 0 || X+ dx[i] > m || Y+dy[i] <=0 || Y+dy[i]>n)
				continue;

			if (vis[Y+dy[i]][X+dx[i]] == 0)
			{
				vis[Y+dy[i]][X+dx[i]] = vis[Y][X] + 1;
				if (arr[Y+dy[i]][X+dx[i]] == '1')
					Q.push({Y+dy[i],X+dx[i]});
			}
		}

	}

}
