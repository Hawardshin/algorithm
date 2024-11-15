#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int> &num, int target, int &ret, int ni, int now){
    // cout << ni << ":" << num[ni]  << " " << now << " " << s << "\n";
    if (ni == num.size()){
        if (now == target){
            // cout <<"RET\n";
            ret++;    
        }
        return;
    }
    dfs(num,target,ret,ni+1,now+num[ni]);
    dfs(num,target,ret,ni+1,now-num[ni]);
    
}

int solution(vector<int> numbers, int target) {
    //2^20
    int ret = 0;
    dfs(numbers, target, ret, 0, 0);
    return ret;
}