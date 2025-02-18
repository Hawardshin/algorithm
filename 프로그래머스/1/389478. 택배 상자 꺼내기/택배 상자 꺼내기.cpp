#include <string>
#include <vector>
#include <iostream>
using namespace std;

int getHigh(int n, int w){
    return (n-1)/w +1;
}

int getIdx(int n, int w){
    int h = getHigh(n,w);
    if (h %2 ==0){
        if (n%w ==0){
            return 1;
        }else {
            return (w - n%w) + 1;
        }
    }else{
        if (n%w ==0)
            return w;
        return n%w;
    }
}

int solution(int n, int w, int num) {
    int answer = 0;
    int n_h = getHigh(n,w);
    int num_h = getHigh(num, w);
    int n_idx = getIdx(n,w);
    int num_idx = getIdx(num,w);
    answer = n_h - num_h; // 높이 차
    if ((n_h % 2 == 0 && n_idx <= num_idx)|| (n_h % 2 == 1 && n_idx>= num_idx)){
        cout <<getIdx(n,w) <<"," << getIdx(num,w) <<"\n";
        answer++;
    }else if (answer ==0)
        answer++;
    return answer;
}