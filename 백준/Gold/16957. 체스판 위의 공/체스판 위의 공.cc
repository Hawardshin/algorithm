#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>
#define X first
#define Y second
using namespace std;

int map[502][502];
int ball[502][502];
int mx[8] = {1,1,1,-1,-1,-1,0,0};
int my[8] = {0,1,-1,1,0,-1,1,-1};
int ttmp[8];
pair <int,int > kk[502][502];
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int r,c;
	cin >> r>> c;
	fill (ball[0] ,ball[r], 1);

	for (int i= 0; i< r; i++)
	{
		for (int j =0; j< c; j++)
		{
			cin >> map[i][j];
			kk[i][j] = {j,i};
		}
	}
	queue <pair <int, int> > Q;
	for (int i=0; i < r; i++)
	{
		for (int j=0; j< c; j++)
		{
			Q.push({j,i});
			ball[i][j]--;
			while (!Q.empty())
			{
				auto tmp = Q.front();Q.pop();
				int min = map[tmp.Y][tmp.X];
				int gox= tmp.X;
				int goy =tmp.Y;
				for (int k =0; k < 8; k++)
				{
					int yyy= tmp.Y + my[k];
					int xxx =tmp.X+mx[k];
					if (yyy < 0 || xxx <0 || yyy >= r || xxx >= c)
						continue;
					if (min > map[yyy][xxx])
					{
						min = map[yyy][xxx];
						gox = xxx;
						goy = yyy;
					//	cout << "kk";
					}
				}
				if (min != map[tmp.Y][tmp.X])
				{
					if (kk[tmp.Y][tmp.X].X != tmp.X || kk[tmp.Y][tmp.X].Y != tmp.Y)
					{
						ball[kk[tmp.Y][tmp.X].Y][kk[tmp.Y][tmp.X].X]++;
						kk[i][j] ={kk[tmp.Y][tmp.X].X, kk[tmp.Y][tmp.X].Y};
					}
					else
						Q.push({gox,goy});
				}
				else
				{
					kk[i][j] = {tmp.X,tmp.Y};
					ball[tmp.Y][tmp.X]++;
				}
			}
		}
	}
	for (int i=0 ;i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			cout << ball[i][j] << ' ';
		}
		cout << '\n';
	}
}
