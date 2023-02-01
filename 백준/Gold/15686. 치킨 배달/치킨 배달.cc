#include <iostream>
#include <algorithm>
#include <queue>
int mapp[51][51];//지도
int	vis[51][51];//bfs
int valid[51][51];//치킨집 사용가능여부
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// int chi_num;
using namespace std;
//
int min_point=21474836;

int	find_min(int y,int x)
{
	int len = 0;
	int min = 21474836;
	for (int i=1;i <= n; i++)
	{
		for (int j=1;j <=n; j++)
		{
			if (valid[i][j] == 1)
			{
				// cout<<i << " "<< j<< "\n";
				len = abs(x - j) + abs(y - i);
				if(len < min)
					min = len;
			}
		}
	}
	// cout<< min << "----\n";
	return (min);
}

void	cal_point()
{
	int	min =0;
	for (int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (mapp[i][j] == 1)
				min += find_min(i,j);
		}
	}
	if (min < min_point)
		min_point = min;
}

void	valid_recur(int depth, int i,int j)
{
	if (depth == m)
		cal_point();
	if (i == n + 1)
		return ;
	for (int ti=i;ti <=n;ti++)
	{
		for (int tj=0;tj<=n;tj++)
		{
			if (i == ti && tj == 0)
				tj = j;
			if (mapp[ti][tj] == 2)
			{
				valid[ti][tj] = 1;
				if (tj == n)
					valid_recur(depth+1,ti+1,0);
				else
					valid_recur(depth+1,ti,tj + 1);
				valid[ti][tj] = 0;
			}
		}
	}
}
int main()
{
	cin >> n>>m;

	for (int i=1;i <=n;i++)
	{
		for (int j=1;j <=n;j++)
		{
			cin >> mapp[i][j];
		}
	}
	// for (int i=0; i <=n;i++)
	// {
	// 	for (int j=0;j<=n;j++) cout<< mapp[i][j] << " ";
	// 	cout<<endl;
	// }
	// cal_point();
	valid_recur(0,0,0);
	cout<< min_point;
}
