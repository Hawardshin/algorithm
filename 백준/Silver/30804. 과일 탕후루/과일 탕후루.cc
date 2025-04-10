#include<iostream>
#include<algorithm>
using namespace std;

int countAr(int *ar){
    int ret = 0;
    for(int i=0;i<11;i++){
        if (ar[i] !=0)
            ret++;
    }
    return ret;
}

int main(){
    int n; int cnt[11];
    int input[200000];
    fill(cnt,cnt+11,0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int L =0;int R = 0;
    int max_len = 0;
    cnt[input[0]]++;
    while(L < n){
        while(countAr(cnt) <= 2 && R < n){
            R++;
            if (R!= n)
                cnt[input[R]]++;
            // cout << "?"<<countAr(cnt)<<"\n";
        }
        // cout <<"LR"<< L << R <<"\n";
        max_len = max(max_len, R-L);
        cnt[input[L]]--;
        L++;
    }

    cout << max_len <<"\n";
}