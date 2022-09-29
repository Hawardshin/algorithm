#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

#define Y first
#define X second

using namespace std;
int dx[8] = {1, 0 ,-1, 0,1,-1, 1, -1};
int	dy[8] = {0, 1, 0, -1,1,-1, -1, 1};
int map[52][52];
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int hi,wi;
	int mi,mj;
	hi = 1; wi = 1;
	queue<pair<int, int> >Q;
	while (wi || hi)
	{
		cin >> wi >> hi;
		if (wi ==0 && hi== 0)
			return 0 ;
		for (int i = 0; i < hi; i++)
		{
			for (int j = 0; j < wi; j++)
			{
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i  < hi; i++)
		{
			for (int j = 0; j < wi; j++)
			{
				if (map[i][j] == 1)
				{
					map[i][j] = 0;
					cnt++;
					Q.push({i, j});
					while (!Q.empty())
					{
						pair<int, int>cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 8; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || ny < 0 || nx >= wi || ny >= hi)
								continue;
							if (map[ny][nx] != 1)
								continue;
							map[ny][nx] = 0;
							Q.push({ny, nx});
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}
