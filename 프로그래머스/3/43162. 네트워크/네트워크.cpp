#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void moveAll(bool *vis,vector<vector<int>> &computers,int now){
    queue<int> Q;
    Q.push(now);
    while (!Q.empty()){
        int n = Q.front();
        Q.pop();
        for(int i=0;i<computers.size();i++){
            if (i != n && vis[i] != true && computers[i][n] == 1){
                Q.push(i);
                vis[i] = true;
            }
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    bool vis[201] = {0,};
    int answer = 0;
    for(int i=0;i<n;i++){
        if (vis[i] == false){
            answer++;
            vis[i] = true;
            moveAll(vis, computers, i);
        }
    }
    
    return answer;
}