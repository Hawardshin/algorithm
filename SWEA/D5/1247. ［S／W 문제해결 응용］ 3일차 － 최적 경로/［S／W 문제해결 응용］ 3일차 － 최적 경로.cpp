#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(int &ret, vector < vector <int> > & dist, vector <bool> &vis, int cnt, int n_dist,int n_idx){
    if (n_dist >= ret) return;
    if (cnt ==0){
        ret = min(n_dist + dist[n_idx][1],ret);
        return ;
    }else{
        for(int i=2;i<vis.size();i++){
            if (vis[i] == true)
                continue;
            vis[i] = true;
            dfs(ret, dist, vis, cnt -1, n_dist + dist[n_idx][i],i);
            vis[i] = false;
        }
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
            int n;
            int input[12][2];
            cin>>n;
            for(int j=0;j<n+2;j++){
                cin >> input[j][0];
                cin >> input[j][1];
            }
            vector<vector<int>> dist(n+2, vector<int>(n+2,0));
            for(int j=0;j<n+2;j++){
                for(int k=j+1;k<n+2;k++){
                    int len = abs(input[j][0] - input[k][0])+ abs(input[j][1] - input[k][1]);
                    dist[j][k] = len;
                    dist[k][j] = len;
                }
            }
            int ret = 1000000000;
            vector<bool> vis(n+2,0);
            dfs(ret,dist,vis,n, 0,0);
            cout << "#" << test_case <<" " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}