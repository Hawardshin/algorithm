#include<iostream>
#include <algorithm>
using namespace std;


int main(){
    int n; cin >>n;
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    long long input[2000];
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    int answer = 0;
    sort(input,input+n);
    for(int i=0;i<n;i++){
        int target = input[i];
        int s = 0;int e = n-1;
        while(s < e){
            if (target == input[s]+input[e]){
                if (s == i)
                    s++;
                else if (e == i)
                    e--;
                else{
                    answer++;
                    break;
                }
            }else if (target < input[s]+input[e]){
                e--;
            }else
                s++;
        }
    }
    cout <<answer <<"\n";

}