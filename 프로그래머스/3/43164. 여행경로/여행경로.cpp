#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool dfs(string target, vector<vector<string>>& tickets, 
         vector<string>& answer, vector<bool>& vis){
    if (answer.size() == tickets.size()){//종료 조건
        answer.push_back(target);
        return true;
    }
    for(int i=0;i<tickets.size();i++){
        if (tickets[i][0] == target && vis[i] == false){
            vis[i] = true;
            answer.push_back(target);
            if (dfs(tickets[i][1], tickets,answer,vis) == true)
                return true;
            vis[i] = false;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int a_idx =0;
    sort(tickets.begin(),tickets.end());
    vector<bool>vis(tickets.size(),0);
    string target = "ICN";
    for(int i=0;i<tickets.size();i++){
        if (tickets[i][0] == target){
            vis[i] =true;
            answer.push_back(target);
            if (dfs(tickets[i][1], tickets,answer,vis) == true)
                return answer;
            vis[i] = false;
            answer.pop_back();
        }
    }
    answer.push_back(target);
    return answer;
}