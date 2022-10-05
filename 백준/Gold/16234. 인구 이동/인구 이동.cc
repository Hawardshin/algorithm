#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include <cstdlib>

#include<utility>
#define X first
#define Y second
using namespace std;

int map1[51][51];
// int map2[51][51];
int vis1[51][51];
int vis2[51][51];
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};
/* 큐 2개 맵 2개 방문 배열 2개 해서 방문 배열은 각 횟수마다 다시 0으로 초기화해주면 루프를 돌 때 마다 다시 사용가능하다.
한바퀴를 돌면서 열수 국경선에 열 수 있는 모든 녀석들을 큐에 넣는다. 이때 오른쪽과 아래만 보면 된다. 전부다 큐에 들어갔다면 이제 시작을 한다.
--- 굳이 이렇게 할 필요 없이 아에 처음에 넣으면서 탐색을 진행하면 뭐가 문제일까? 첫번째 큐가 빌 때까지 하면 되고 맵이 2개기 때문에 상관없다.
그렇다면 큐 2개면 헷갈리니까 맵 2개로 한다.
첫번째 큐에 들어간 모든 녀석들에 대해서 4가지 움직임을 실행한다. 새로운 큐에 넣음으로써 즉 바깥조건은 첫번째 큐가 빌때까지
안쪽 조건은 안쪽 큐가 빌 때 까지로 해서 한다.
단 여기서 주의할 점이 몇가지 있는데
우선 방문 처리. 첫번째 큐에서 꺼낼 때 두번째 큐에서 한 너비 탐색중 이미 방문한 경우 이 숫자는 두번째 큐에 푸쉬 하지 않는다.
두번째 큐가 다 빠져나왔을 때 각 숫자들을 다 더한 평균을 그 맵에 넣어줘서 데이터를 갱신 한다. 즉 갱신 할 맵을 따로 만드는게 좋은 것 같다.
새로운 맵 갱신하고 이제 다시 첫번째 큐로 가고 거기서 검사는 인덱스와 방문여부이다.
마지막 위치를 아니까 그 위치에서 총합을 갯수만큼 나눠서 갱신을 해준다.
첫번 째 큐도 끝이 난다면 이제 하루가 증가하고 다시 처음부터 로직을 시작하면 된다.
만약 단 한번도 첫번째 큐로 푸쉬가 되지 않는다면 프로그램은 종료된다.
*/

void print_all_map(int n)
{

	cout << "\n--------map1-------------\n";
	for (int i=0; i < n; i++)
	{
		for (int j =0; j < n;j++)
		{
			cout << map1[i][j] << " ";
		}
		cout << "\n\n";
	}
}

void	clear_vis(int n)
{
	for (int i=0; i < n;i++)
	{
		for (int j =0; j <n; j++)
			vis1[i][j] = 0;
	}
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int N,L,R;
	cin >> N >> L>> R;
	for (int i=0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map1[i][j];
		}
	}
	int day = -1;
	queue<pair<int, int> >Q;
	queue<pair<int ,int> >MQ;
	int flag = 1;
	long long sum = 0;
	while (flag == 1)
	{
		day++;
		flag = 0;
		for (int i=0; i < N;i++)
		{
			for (int j=0; j <  N;j++)
			{
				//돌기전에 가능한 녀석을 찾아서 큐에 푸쉬해주고 돌리고 끝나면 그녀석들을 뒤의 맵 자체를 갱신 단 방문한경우 절대 그 값이 푸쉬되지 않으니 영향을
				//미칠 것을 고려하지 않아도 되나? 맞다.

				int num = 0;
				for (int r = 0; r < 2; r++)
				{
					int ddx = j + mx[r];
					int ddy = i + my[r];
					// if ((day % 2 == 0 && vis1[i][j] == 1) || (day % 2 == 1 && vis2[i][j] == 1))
					// 	continue;
					if (vis1[i][j] == 1)
						continue ;
					if (ddx <0 || ddy < 0 || ddx >=N || ddy >= N)
						continue;
					// if (day % 2== 0)
					// {
					if ((L <= abs((map1[i][j] - map1[ddy][ddx]))) && (abs((map1[i][j] - map1[ddy][ddx])) <= R))
					{
						flag = 1;
						// sum += map1[i][j];
						Q.push({j ,i});
						// cout << "first\n";
						// cout << i << " " << j << "\n";
						//
						break;
					}
					// }
					// else
					// {
					// 	if ((L <= abs((map2[i][j] - map2[ddy][ddx]))) && (abs((map2[i][j] - map2[ddy][ddx])) <= R))
					// {
					// 	flag = 1;
					// 	sum += map2[i][j];
					// 	Q.push({j ,i});
					// 	cout << "first\n";
					// 	cout << i << " " << j << "\n";
					// 	//

					// 	break;
					// 	}
					// }
					// }
				}
				while (!Q.empty())
				{
					pair<int ,int > ar = Q.front();
					Q.pop();
					// cout <<"X ::"<< ar.X << "\n" << "Y ::"<<ar.Y << "\n";
					// if ((day % 2 == 0 && vis1[ar.Y][ar.X] == 1) || (day % 2 == 1 && vis2[ar.Y][ar.X] == 1))
					// 	continue;
					num++;
					sum += map1[ar.Y][ar.X];
					vis1[ar.Y][ar.X] = 1;
					// vis2[ar.Y][ar.X] = 1;
					MQ.push({ar.X,ar.Y});
					for (int k = 0; k < 4; k++)
					{
						int dx = ar.X + mx[k];
						int dy = ar.Y + my[k];
						if (dx <0 || dy < 0 || dx >=N || dy >= N)
							continue;
						if (vis1[dy][dx] == 1)
							continue;
						// if (day % 2 == 0 && vis1[dy][dx])
						// 	continue ;
						// if (day % 2 == 1 && vis2[dy][dx])
						// 	continue ;
						if ((L <= abs((map1[ar.Y][ar.X] - map1[dy][dx]))) && ((abs((map1[ar.Y][ar.X] - map1[dy][dx])) <= R)))
						{
							// cout << "map" << abs((map1[ar.Y][ar.X] - map1[dy][dx])) << "\n";
							// cout << dy << " " << dx << "\n";
							flag = 1;
							vis1[dy][dx] = 1;
							// vis2[dy][dx] = 1;
							Q.push({dx ,dy});
							// cout << "aaaa\n";
						}
					}
				}
				// update map
				if (num != 0 )
				{
					// cout << "day " << day <<"\n" << "num" << num << "\n";
					// print_all_map(N);
					int re = sum / num;
					while (!MQ.empty())
					{
						pair<int ,int> ss;
						ss = MQ.front();
						MQ.pop();
						map1[ss.Y][ss.X] = re;
					}
					sum =0;
					// print_all_map(N);
				}
			}
		}
		clear_vis(N);
	}
	cout <<day << "\n";
}