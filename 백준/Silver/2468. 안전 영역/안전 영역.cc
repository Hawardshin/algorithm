#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
#define X first
#define Y second
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, -1, 0, 1};

int main()
{

	ios ::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> arr(n);
	queue<pair<int, int>> Q;
	vector<vector<bool>> vis(100, vector<bool>(100, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	} // n까지 잠긴다.
	int cnt = 0;
	int max_cnt = 0;
	int now = 0;
	for (; now < 100; now++)
	{
		cnt =0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (arr[i][j] > now && !vis[i][j])
				{
					vis[i][j] = true;
					Q.push({j, i});
					while (!Q.empty())
					{
						pair<int, int> a = Q.front();
						Q.pop();
						for (int k = 0; k < 4; k++)
						{
							int dx = a.X + mx[k];
							int dy = a.Y + my[k];
							if (dx < 0 || dy < 0 || dy >= n || dx >= n)
								continue;
							if (vis[dy][dx])
								continue;
							vis[dy][dx] = true;
							if (arr[dy][dx] > now)
							{
								Q.push({dx, dy});
							}
						}
					}
					cnt++;
				}
			}
		}
		if (cnt > max_cnt)
			max_cnt = cnt;
		// memset(arr, 0, sizeof(arr));
		// memset(vis, 0, sizeof(vis));
		for (int i=0; i < n;i++)
		{
			for (int j =0; j < n; j++)
			{
					vis[i][j] = 0;
			}
		}
	}
	// if (flag == 0 && cnt == 1)
	// 	cnt = 0;
	cout << max_cnt << "\n";
}
