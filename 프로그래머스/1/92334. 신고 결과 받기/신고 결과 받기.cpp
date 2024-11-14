#include <string>
#include <vector>
#include <map>
#include<string.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> id_map;
    int table[1001][1001];
    memset(table,0,sizeof(table));   
    vector<int> answer;
    for(int i=0;i<id_list.size();i++){
        id_map[id_list[i]] = i;
        answer.push_back(0);
    }
    for(string s : report){
        string sender = s.substr(0,s.find(' '));
        string recv = s.substr(s.find(' ')+1,s.length());
        table[id_map[sender]][id_map[recv]] =1;
    }
    for(int i=0;i<id_list.size();i++){
        int reported_sum =0;
        for(int j=0;j<id_list.size();j++){
            reported_sum += table[j][i];
        }
        if (reported_sum >= k){
            for(int j=0;j<id_list.size();j++){
                if (table[j][i] == 1)
                    answer[j]++;
            }
        }
    }
    return answer;
}