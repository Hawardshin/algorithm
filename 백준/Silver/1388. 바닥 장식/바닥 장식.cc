#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

#define X first
#define Y second
using namespace std;

char map[51][51];
int vis[51][51];

// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};

int dx[2] ={1,0};
int dy[2] {0,1};
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >>n >>m;
	for (int i=0; i < n; i++)
	{
		for (int j= 0;j < m;j++)
		{
			cin >> map[i][j];
		}
	}
	queue <pair<int, int> > Q;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j =0; j < m; j++)
		{
			if (vis[i][j] == 0)
			{
				cnt++;
				// cout << "j" << j <<"i" <<i << "\n";
				Q.push({j,i});
				vis[i][j] = 1;
			}
			while (!Q.empty())
			{
				pair<int,int > mQ = Q.front();
				Q.pop();
				for (int i=0; i < 2; i++)
				{
					int nx = mQ.X + dx[i];
					int ny = mQ.Y + dy[i];
					if (nx<0 || ny <0 || nx >=m || ny >=n)
						continue;
					if (vis[ny][nx] == 1)
						continue;
					if (map[mQ.Y][mQ.X] == '-' && i == 1)
						continue;
					if (map[mQ.Y][mQ.X] == '|' && i == 0)
						continue;
					if ((map[mQ.Y][mQ.X] == '-' && map[ny][nx	]== '-')|| (map[mQ.Y][mQ.X] == '|' && map[ny][nx]== '|'))
					{
						vis[ny][nx] =1;
						Q.push({nx, ny});
					}
				}
			}

		}
	}
	cout << cnt << "\n";
}
