#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

bool link[101][101];
int dist[101][101];


int main(){
	memset(dist,INF,sizeof(dist));
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		link[a][b] = true;
		link[b][a] = true;
		dist[a][b] = 1;
		dist[b][a] = 1;
 	}
	for(int i=1;i<=100;i++){//중간
		for(int k=1;k<=100;k++){//시작
			for(int j=1;j<=100;j++){//끝
				if (k == j){
					dist[k][j] =0;
				}else {
					dist[k][j] = min(dist[k][j],dist[k][i]+dist[i][j]);
				}
			}
		}
	}
	int max_sum =10000000;
	int max_idx = 0;
	for(int i=1;i<=n;i++){
		int now_sum = 0;
		for(int j=1;j<=n;j++){
			now_sum+= dist[i][j];
		}
		if (now_sum < max_sum)
		{
			max_sum = now_sum;
			max_idx = i;
		}
	}
	cout << max_idx << "\n";

}