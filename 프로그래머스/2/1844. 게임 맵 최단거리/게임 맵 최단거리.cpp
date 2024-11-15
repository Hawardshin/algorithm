#include<vector>
#include <queue>
#include <cstring>
#define Y first
#define X second
using namespace std;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int vis[101][101];
    memset(vis,-1,sizeof(vis));
    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;
    while (!Q.empty()){
        auto nq = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int ny = nq.Y + dy[i];
            int nx = nq.X + dx[i];
            if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size()) continue;
            if (vis[ny][nx] != -1) continue;
            if (maps[ny][nx] == 0) continue;
            vis[ny][nx] = vis[nq.Y][nq.X]+1;
            Q.push({ny,nx});
        }
    }
    return vis[maps.size()-1][maps[0].size()-1];
}