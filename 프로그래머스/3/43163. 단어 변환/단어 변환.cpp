#include <string>
#include <vector>
#include <queue>
using namespace std;

bool canMove(string now, string nxt){
    int same_cnt = 0;
    for(int i=0;i<now.length();i++){
        if (now[i] == nxt[i])
            same_cnt++;
    }
    if (same_cnt == now.length()-1)
        return true;
    return false;
}


int solution(string begin, string target, vector<string> words) {
    queue<pair<string,int>> Q;
    Q.push({begin,0});
    bool vis[51] = {0,};
    while(!Q.empty()){
        auto nq = Q.front();
        Q.pop();
        if (nq.first == target)
            return nq.second;
        for(int i=0;i<words.size();i++){
            if (vis[i] == true) continue;
            if (canMove(nq.first,words[i])){
                vis[i]=true;
                Q.push({words[i],nq.second+1});
            }
        }
    }
    return 0;
}