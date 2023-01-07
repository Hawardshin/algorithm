#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n,m;

int do_find(vector<vector<int>> to_find)
{//맵이 고정됐으니까 이제 각 값들에 대해서 안전영역이 몇개인지 찾기.
	vector vis(n,vector<int>(m,0));
	for (int i=0;i < n; i++)
	{
		for (int j =0;j < m;j++)
		{
			if (to_find[i][j] == 2 && vis[i][j] == 0)
			{
				vis[i][j] = 1;
				queue<pair<int,int>> Q;
				Q.push({i,j});//y,x
				while (!Q.empty())
				{
					pair<int,int> p = Q.front();
					Q.pop();
					for (int k=0;k < 4;k++)
					{
						if (p.first + dy[k]< 0 ||  p.second + dx[k] < 0 || p.first + dy[k] >= n || p.second + dx[k] >=m)
							continue;
						if (vis[p.first + dy[k]][p.second + dx[k]] == 1 || to_find[p.first + dy[k]][p.second + dx[k]] == 1)
							continue ;
						vis[p.first + dy[k]][p.second + dx[k]] = 1;
						to_find[p.first + dy[k]][p.second + dx[k]] = 2;
						Q.push({p.first + dy[k],p.second + dx[k]});
					}
				}
			}
		}
	}
	//bfs를 완료해서 현재 맵에서 2가 인접한 부분들은 전부 다 2로 바뀜
	// 이제 총 0의 갯수를 세서 리턴
	int cnt =0;
	for (int i=0;i < n;i++)
	{
		for (int j=0;j < m; j++)
		{
			if (to_find[i][j] == 0)
				cnt++;
		}
	}
	return (cnt);
}

int map_change(vector<vector<int>> to_find)
{
	int ret =0;
	int max = 0;
	for (int i=0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (to_find[i][j] == 0)
			{//1번 잡아두고
				to_find[i][j] = 1;
				for (int b1 = 0; b1 <n; b1++)
				{
					for(int b2 = 0;b2 < m;b2++)
					{
						if (to_find[b1][b2] == 0)
						{//2번 잡아두고
							to_find[b1][b2] = 1;
							for(int c1 = 0;c1 < n; c1++)
							{
								for (int c2 = 0; c2 < m; c2++)
								{// 3번 잡아두고
									if (to_find[c1][c2] == 0)
									{//3번까지 잡았으면
										to_find[c1][c2] = 1;
										ret = do_find(to_find);
										if (max < ret)
											max = ret;
										to_find[c1][c2] = 0;
									}
								}
							}
							to_find[b1][b2] = 0;
						}
					}
				}
				to_find[i][j] = 0;
			}
		}
	}
	return (max);
}

int main()
{
	// ios:: sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector arr(n + 1,vector<int>(m + 1,0));
	for (int i=0;i < n;i++)
	{
		for (int j=0;j < m;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << map_change(arr);
}
/*

1 2 1 1
1 0 1 2
1 0 0 0
2 0 0 0

*/
