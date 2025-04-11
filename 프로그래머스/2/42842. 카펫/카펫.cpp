#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int x=0,y=0;
    vector<int> answer;
    for(int i=2;i<5000;i++){
        if ((i-2) * (brown - 2*i) == 2*yellow){
            x = i;
            y = (brown/2) + 2 - x;
            cout << x<<y<<"\n";
            if (x >= y){
                answer.push_back(x);
                answer.push_back(y);
                return answer;
            } 
        }
    }
    return answer;
}