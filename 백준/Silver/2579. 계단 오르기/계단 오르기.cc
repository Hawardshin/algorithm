//백준 2579
#include<iostream>
#include<algorithm>
using namespace std;

int a[301];
int dp[301];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i]; }
    dp[1]=a[1];
    dp[2]= a[1]+a[2];
    dp[3]= max(a[1],a[2])+a[3];
    for(int y=4;y<=n;y++){
        dp[y]= max(dp[y-2]+a[y], dp[y-3]+a[y-1]+a[y]);
    }
    cout<< dp[n];
}