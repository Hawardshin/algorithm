#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long countPeople(long long time ,vector<int> &times){
    long long cnt= 0;
    for(int i=0;i<times.size();i++){
        cnt += (time / times[i]);
    }
    return cnt;
}

long long make_min(vector<int> &times, long long time){
    long long min = 1000000000000000000;
    for(int i=0;i<times.size();i++){
        if (time % times[i] < min)
            min = time % (long long)times[i];  
    }
    return time - min;
}

long long solution(int n, vector<int> times) {
    long long L = 1;
    long long R = 1000000000000000000;
    while(L <= R){
        long long mid = (L + R) /2;//시간
        
        long long cnt = countPeople(mid,times);
        // cout << mid <<"::"<< cnt<<"\n";
        if (n == cnt){
            return make_min(times,mid);
        }
        else if (cnt < n){
            L = mid +1;
        }else{
            R = mid -1;
        }
    }
    
    return L;
}