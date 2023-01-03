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
int map[102][102];
int mx[4] ={0,1,0,-1};
int my[4] ={1,0,-1,0};
int all;
int result[10000];
// void printmap(int col,int row)
// {
// 	for (int i=col -1; i >= 0;i--)
// 	{
// 		for (int j=0; j < row; j++)
// 		{
// 			cout << map[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// }
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int col,row,snum;
	int lx,ly,rx,ry;
	cin >> col >> row >> snum;
	for(int i=0; i< snum;i++)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int j = ly; j < ry; j++)
		{
			for (int k = lx; k < rx; k++)
				map[j][k] = -1;
		}
	}
	//printmap(col,row);
	queue <pair<int, int> >Q;
	int cnt;
	for (int i=0; i < col; i++)
	{
		for (int j=0; j < row; j++)
		{
			if(map[i][j] != 0)
				continue;
			Q.push({j,i});
			cnt = 1;
			while (!Q.empty())
			{
				auto tmp = Q.front(); Q.pop();
				for (int k = 0; k < 4; k++)
				{
					int myx = tmp.X+mx[k];
					int myy = tmp.Y+my[k];
					if (myx <0 || myy <0 || myx >= row || myy >=col)
						continue;
					if (map[myy][myx] != 0)
						continue;
					cnt++;
					map[myy][myx] = cnt;

					Q.push({myx,myy});
				}
				if (Q.empty())
				{
					if (cnt !=1)
						cnt--;
					result[all] = cnt;
					all++;
				}
			}
		}
	}
	//printmap(col,row);
	cout << all << "\n";
	sort(result,result+all);
	for(int i=0; i< all; i++)
		cout << result[i] << ' ';
}
