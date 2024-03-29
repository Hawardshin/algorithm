#include <iostream>
#include <queue>
using namespace std;
int N;
int input[103][103];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int area_val = 0;
int min_len = 2147483647;
// void printall(){
// 	for(int i=0;i <N;i++){
// 		for(int j=0; j<N;j++){
// 			cout << input[i][j];
// 		}
// 		cout << "\n";
// 	}
// 	cout << "-------------------\n";
// }
void init(int i, int j){
	queue<pair<int,int> > Q;
	Q.push({i,j});//y,x
	area_val--;
	input[i][j] = area_val;
	while (!Q.empty()){
		auto a = Q.front();
		int my = a.first;
		int mx = a.second;
		Q.pop();
		for(int i=0;i<4;i++){
			int ty = my+dy[i];
			int tx = mx + dx[i];
			if (ty < 0 || tx < 0 || ty >=N ||tx >= N)
				continue;
			if (input[ty][tx] != 1)
				continue;
			input[ty][tx] = area_val;
			Q.push({ty,tx});
		}
	}
}
// -1000-2
// 00000
// 00000
// 00000
// 0-300-4
void find_mini(int i,int j){//y,x
	int start_id = input[i][j];
	queue<pair<int,int> >Q;
	Q.push({i,j});//y,x
	while (!Q.empty()){
		auto a = Q.front();
		Q.pop();
		int my = a.first;
		int mx = a.second;
		for(int i=0;i<4;i++){
			int ty = my+dy[i];
			int tx = mx + dx[i];
			if (ty < 0 || tx < 0 || ty >=N ||tx >= N)
				continue;
			if (start_id < 0 && input[ty][tx] == start_id)//같은 섬이면
				continue;
			if (input[ty][tx] < 0)//다른 섬이면
			{
				if (min_len >  input[my][mx])
					min_len = input[my][mx];
				continue;
			}
			if (input[ty][tx] == 0){//아직 방문하지 않은 곳이라면 
				if (input[my][mx] > 0)
					input[ty][tx] = input[my][mx] + 1;
				else
					input[ty][tx] = 1;
				Q.push({ty,tx});
			}
			else if (input[ty][tx] > 0 && input[ty][tx] > input[my][mx] + 1)//또는 이미 방문했는데 이전에 방문했던 거리보다 더 짧아진 경우
			{
				if (input[my][mx] > 0)
					input[ty][tx] = input[my][mx] + 1;
				else
					input[ty][tx] = 1;
				Q.push({ty,tx});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){//input
		for(int j=0;j<N;j++){
			cin >> input[i][j];
		}
	}
	for(int i=0;i<N;i++){//init island
		for(int j=0;j<N;j++){
			if (input[i][j] == 1)
				init(i,j);
		}
	}
	// cout << "island " << area_val <<"\n";
	for(int i=0;i<N;i++){//min value find
		for(int j=0;j<N;j++){
			if (input[i][j] < 0){
				// printall();
				find_mini(i,j);
			}
		}
	}
	// printall();
	cout << min_len << "\n";

}