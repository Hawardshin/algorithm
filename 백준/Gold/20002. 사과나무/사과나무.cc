//[시작점y][시작점 x] [길이][n][n][n]
// [y][x][len] = [y][x][len-1] + 모퉁이
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    int ret = -10000;
    int map[301][301];
    int sum[301][301];
    for(int i=0;i<301;i++){
        fill(map[i],map[i]+301,0);
        fill(sum[i],sum[i]+301,0);
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j] = map[i][j]+ sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(int len = 1;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            for(int j=1;j<=n-len+1;j++){
                int now = sum[i+len-1][j+len-1] - sum[i-1][j+len-1] -sum[i+len-1][j-1] + sum[i-1][j-1];
                ret = max(ret,now);
            }
        }
    }
    
    
    cout << ret<<"\n";
}