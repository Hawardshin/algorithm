#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
   int ar[100001];
    for(int i=0;i<N;i++){
        cin >> ar[i];
    }
    sort(ar,ar+N);
    int L=0,R=N-1;
    int min = 2100000000;
    int answer[2] = {0,};
    while(L < R){
        int sum = ar[L] + ar[R];
        if (abs(sum) < min){
            answer[0] = ar[L];
            answer[1] = ar[R];
            min = abs(sum);
        }
        if (sum == 0)
            break;
        if (sum < 0)
            L++;
        else if (sum >0)
            R--;
    }
    cout << answer[0] << " " << answer[1] << "\n";
}