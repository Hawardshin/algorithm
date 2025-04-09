#include<iostream>

using namespace std;
int main(){
    int n; cin>>n;
    int answer = 0;
    for(int i=n;i>0;i--){
        int sum= 0;
        for(int j=i;j>0;j--){
            sum+= j;
            if (sum > n)
                break;
            if (sum == n){
                answer++;
                break;
            }
        }
        if (sum < n)
            break;
    }
    cout << answer <<"\n";
}