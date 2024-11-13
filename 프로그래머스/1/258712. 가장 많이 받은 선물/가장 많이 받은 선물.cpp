#include <string>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include<iostream>
using namespace std;
// 기록 없는 경우 -> 선물지수 큰 사람-> 작은사람.
// 선물지수 = 내가 준 선물 수 - 받은 선물 수

int solution(vector<string> friends, vector<string> gifts) {
    int f_point[51][51];
    int points[51];
    memset(f_point,0,sizeof(f_point));
    memset(points,0,sizeof(points));
    map<string, int> f_idx;
    int f_size = friends.size();
    for(int i=0;i<f_size;i++){
        f_idx[friends[i]] = i;    
    }
    for(string gift : gifts){
        //space 기준 띄워서 단어 분리
        string f1 = gift.substr(0,gift.find(' '));
        string f2 = gift.substr(gift.find(' ')+1, gift.length());
        f_point[f_idx[f1]][f_idx[f2]]++; //f1이 f2에게 선물을 줌.
    }
    for(int i=0;i<f_size;i++){
        for(int j=0;j<friends.size();j++){
            cout << f_point[i][j];
        }
        cout <<"\n";
    }
    //각각의 선물지수
    for(int i=0;i<f_size;i++){
        int give =0;
        int get = 0;
        for(int j=0;j<f_size;j++){
            give += f_point[i][j];
            get += f_point[j][i];
        }
        points[i] = give - get;
    }
    for(int i=0;i<f_size;i++){
        cout << i << ": "<<points[i] << "\n";
    }
    
    //선물을 주고 받은 수가 같고, 지수가 같은 경우만 안 주고 받으니 그것만 뺴자.
    int answer = (f_size*(f_size-1)) / 2;
    int max_cnt = 0;
    for(int i=0;i<f_size;i++){//0번째 캐릭터부터 확인
        int cnt =0;
        for(int j=0;j<f_size;j++){
            if (i == j)
                continue;
           if (f_point[i][j] > f_point[j][i]){
               // cout <<"MM"<< i << j << "\n";
               cnt++;
           }else if (f_point[i][j] == f_point[j][i] && points[i] > points[j]){
               cnt++;
           }
        }
        // cout << "cnt:"<<cnt << "\n";
        max_cnt = max(max_cnt, cnt);
    }
    answer = max_cnt;
    return answer;
}