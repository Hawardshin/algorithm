#include <iostream>
#include <queue>
#define Y first
#define X second

using namespace std;

int table[1001][1001];
bool vis[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	queue<pair<int,int>>Q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> table[i][j];
			if (table[i][j] == 2){
				Q.push({i,j});
				table[i][j]=0;
				vis[i][j]= true;
			}
		}
	}
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int mx = q.X + dx[i];
			int my = q.Y + dy[i];
			if (mx <0 || my<0 || mx>=m || my>= n)
				continue;
			if (table[my][mx] == 0)
				continue;
			if (vis[my][mx] == true)
				continue;
			if (table[my][mx] != 1)
				continue;
			vis[my][mx] = true;
			table[my][mx] = table[q.Y][q.X] +1;
			Q.push({my,mx});
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (vis[i][j] == false && table[i][j] != 0)
				cout << -1 << " ";
			else 
				cout << table[i][j]<< " ";
		}
		cout << "\n";
	}

}