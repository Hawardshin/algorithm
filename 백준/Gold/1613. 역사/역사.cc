//2. https://www.acmicpc.net/problem/1613
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int way[401][401];
int n,k,s;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int a,b;
		cin >>a >>b;
		way[a][b] = -1;
		way[b][a] = 1;	
	}
	for(int i=1;i<=n;i++){//중간점
		for(int j=1;j<=n;j++){//시작
			for(int k=1;k<=n;k++){//끝점
				if (way[j][k] == 0){
					if (way[j][i] == 1 && way[i][k] == 1)
						way[j][k] = 1;
					else if (way[j][i] == -1 && way[i][k] == -1)
						way[j][k] = -1;
				}
			}
		}
	}
	cin >> s;
	for(int i=0;i<s;i++){
		int a,b;
		cin >>a >>b;
		cout << way[a][b] <<"\n";
	}
}

