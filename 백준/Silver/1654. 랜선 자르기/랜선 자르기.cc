#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calcAll(vector<int> &ar,long long n, long long len){

    int ret =0;
    for(int a: ar){
        ret += (a/len);
    }
    if (ret < n)
        return 1;
    else if (ret > n)
        return -1;
    else
        return 0;
}

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> ar(k);
    for(int i=0;i<k;i++){
        cin >> ar[i];
    }
    long long left = 1;
    long long right = 2147483647;
    long long ret = 0;
    while(true){
        if (left > right)
            break;
        long long mid = (right +left)/2;
        long long r = calcAll(ar,n,mid);
        if (r <= 0){
            ret = max(ret,mid);
            left = mid+1;
        }else if (r >= 0){
            right = mid -1;
        }
    }
    cout << ret <<"\n";
}