#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;

#define X first
#define Y second

int movex[4] = {0,1,0,-1};
int movey[4] = {1,0,-1,0};
//bool vis[1002][1002];//불의 방문여부
char map[1002][1002];//지도
int dis[1002][1002];//이동거리 시작은  0
int fdis[1002][1002];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int test_num;
	cin >> test_num;

	for(int i = 0; i< test_num; i++)
	{
		queue <pair<int ,int > > myQ;
		queue <pair<int ,int > >fQ;
		int wid,high,sx, sy;
		cin >> wid >> high;
		for (int i =0; i < high ; i++)
		{
			fill(map[i],map[i] + wid ,0);
			fill(dis[i],dis[i] + wid,-1);
			fill(fdis[i],fdis[i] + wid, -1);
		}
		for (int j =0; j < high; j++)
		{
			string input;
			cin >> input;
			for (int k =0; k < wid; k++)
			{
				map[j][k] = input[k];
				if(map[j][k] == '@')
				{
					dis[j][k] = 0;
					myQ.push({k,j});
				}
				if (map[j][k] == '*')
				{
					fdis[j][k] =0;
					fQ.push(make_pair(k,j));
				}
			}
		}
		int ret = 0;
		while (!fQ.empty())
		{
			auto b = fQ.front(); fQ.pop();
			for (int i =0; i < 4; i++)
			{
				int fx = b.X + movex[i];
				int fy = b.Y + movey[i];
				if (fx < 0 || fy < 0 || fx >= wid || fy >= high)
					continue;
				if(fdis[fy][fx] != -1|| map[fy][fx] == '#')
					continue;
				fdis[fy][fx] = fdis[b.Y][b.X] + 1;
				fQ.push({fx,fy});
			}
		}
		while (!myQ.empty())
		{
			auto a = myQ.front(); myQ.pop();
			for (int i =0; i < 4; i++)
			{
				int mx = a.X + movex[i];
				int my = a.Y + movey[i];
				if (mx < 0 || my < 0 || mx >= wid || my >= high )
				{
					ret = dis[a.Y][a.X] + 1;
					break;
				}
				if (dis[my][mx] != -1 || (fdis[my][mx] != -1 && fdis[my][mx] <= dis[a.Y][a.X] + 1) || map[my][mx] == '#')
					continue;
				dis[my][mx] = dis[a.Y][a.X] + 1;
				myQ.push({mx,my});
			}
			if (ret !=0)
				while (!myQ.empty())
					myQ.pop();
		}
		if (ret == 0)
			cout << "IMPOSSIBLE\n";
		else
			cout << ret << '\n';
		}
}
