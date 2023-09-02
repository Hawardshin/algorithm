#include <iostream>
using namespace std;
int input[1001];
int links[1001][1001];
int N,M;
void dfs(int start){
	for(int i=1;i <= N;i++){
		if (links[i][start]){
			links[i][start] = 0;
			links[start][i] = 0;
			dfs(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a,b;
	int ret = 0;
	int cnt =0;
	for(int i=0;i<M;i++){
		cin >> a >>b;
		links[a][b] = 1;
		links[b][a] = 1;
		if (!input[a])
			cnt++;
		if (!input[b])
			cnt++;
		input[a] = 1;
		input[b] = 1;
	}
	for(int i=1;i <= N;i++){
		int bef = i - 1;
		for(int j=i + 1; j <= N;j++){
			if (links[i][j]){
				dfs(i);
				ret++;
			}
		}
	}
	ret += (N - cnt);
	cout << ret<<"\n";
}
