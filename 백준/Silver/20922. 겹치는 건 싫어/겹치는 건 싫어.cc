#include <iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int N,K;
    int input[200001];
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >>input[i];
    }
    int L=0,R=0;
    map<int,int> m;
    m[input[0]]++;
    int ans = 0;
    while(R < N && L < N ){
        // cout << "L R" << L << R <<"\n";
        if (m[input[R]]>K){
            m[input[L]]--;
            L++;
        }else {
            R++;
            ans = max(ans,R-L);
            if (R >= N)
                break;
            m[input[R]]++;  
        }
    }
    cout << ans <<"\n";
}