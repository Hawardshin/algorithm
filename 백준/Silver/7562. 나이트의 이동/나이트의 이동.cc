#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;


int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int	how_much_move ()
{
	int map_size,startx,starty,gox,goy;
	cin >> map_size >> startx>>starty >>gox >> goy;
	int dist[302][302];
	fill(dist[0], dist[302], -1);
	queue <pair <int,int> >Q;
	dist[startx][starty] = 0;
	Q.push(make_pair(startx, starty));
	while (!Q.empty())
	{
		//cout << "a";
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();
		if (X == gox && Y == goy)
			return (dist[X][Y]);
		for (int k = 0; k < 8; k++)
		{
			int myx = X+dx[k];
			int myy = Y+dy[k];
			if (myx < 0 || myy < 0 || myx >= map_size || myy >= map_size)
				continue;
			if (dist[myx][myy] != -1)
				continue;
			dist[myx][myy] = dist[X][Y] + 1;
			Q.push(make_pair(myx,myy));
		}
	}
	return (0);
}



int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int case_num;
	cin >> case_num;
	for (int i=0; i < case_num;i++)
	{
		cout << how_much_move() << "\n";
	}
}
