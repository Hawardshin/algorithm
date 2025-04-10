#include <iostream>

using namespace std;

bool isOk(int *cnt,int *now){
    for(int i=0;i<4;i++){
        if (cnt[i] != 0 && now[i] < cnt[i])
            return false;
    }
    return true;
}

int main(){
    int s,p;
    cin >> s >>p;
    string input;
    cin >> input;
    int L =0;
    int R = p;
    int answer = 0;
    int cnt[4];//A,C,G,T
    for(int i=0;i<4;i++){
        cin >> cnt[i];
    }
    int now[4] = {0,};//A,C,G,T
    for(int i=0;i<p;i++){
        if (input[i] == 'A')
            now[0]++;
        else if (input[i] == 'C')
            now[1]++;
        else if (input[i] == 'G')
            now[2]++;
        else if (input[i] == 'T')
            now[3]++;
    }
    if (isOk(cnt,now))
        answer++;
    while(true){
        
        if (R == s)
            break;
        if (input[R] == 'A')
            now[0]++;
        else if (input[R] == 'C')
            now[1]++;
        else if (input[R] == 'G')
            now[2]++;
        else if (input[R] == 'T')
            now[3]++;
        if (input[L] == 'A')
            now[0]--;
        else if (input[L] == 'C')
            now[1]--;
        else if (input[L] == 'G')
            now[2]--;
        else if (input[L] == 'T')
            now[3]--;
        R++;
        L++;
        if (isOk(cnt,now))
            answer++;
    }

    cout << answer<<"\n";
}