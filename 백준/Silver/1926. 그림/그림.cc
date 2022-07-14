#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<utility>
#include<string.h>
#include<queue>
using namespace std;
#define X first
#define Y second

int board[502][502];
int visit[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int col,row;
	cin >> col >> row;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> board[i][j];
		}
	}
	int mx = 0; // 그림의 최대값.
	int num = 0; //그림의 숫자.
	for (int i = 0; i< col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (board[i][j] == 0 || visit[i][j])
				continue;
			else
			{//방문하지 않고 벽이 아닌곳에 들어왔을때.
				num++;//한번 들어왔을때 그 공간 더해줌
				queue< pair<int, int> > Q;
				visit[i][j] = 1;//방문처리
				Q.push(make_pair(i,j));//그 위치 저장
				int area = 0;
				while (!Q.empty())
				{//Q 값이 빌때까지 while문 반복
					area++;
					pair<int, int> cur =Q.front();
					Q.pop();
					//4방향 돌려보기
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= col || ny < 0 || ny >= row)
							continue;
						if (visit[nx][ny] || board[nx][ny] != 1)
							continue;
						visit[nx][ny] = 1;
						Q.push(make_pair(nx,ny));
					}
				}
				mx = max(mx,area);
			}
		}
	}
	cout << num << "\n" << mx;
}
