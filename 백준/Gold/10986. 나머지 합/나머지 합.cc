#include<iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n>>m;
    int *arr = new int[n+1];
    long long num_cnt[10001];
    memset(num_cnt,0,sizeof(num_cnt));
    for(int i=0;i<n;i++){
        cin>> arr[i];
        if (i!=0)
            arr[i] = (arr[i - 1] + arr[i]) % m;
        else 
            arr[i] = arr[i] % m;
        num_cnt[arr[i]]++;
    }
    long long answer = 0;
    for(int i=0;i<10001;i++){
        if (i == 0)
            answer += num_cnt[i];
        answer = answer + (num_cnt[i]* (num_cnt[i] -1))/2;
    }
    // answer += num_cnt[0];
    cout << answer<<"\n";
}