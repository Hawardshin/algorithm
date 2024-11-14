#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

bool canFill(int x,int y,int mat,vector<vector<string>>park){
    if (y + mat > park.size())
        return false;
    if (x+mat > park[0].size())
        return false;
    for(int i=0;i<mat;i++){    
        for(int j=0;j<mat;j++){
            if (park[i+y][j+x] != "-1")
                return false;
        }
    }
    return true;
}

bool matCanFill(int mat, vector<vector<string>> park){
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if (canFill(j,i,mat,park) == true)
                return true;
        }
    }
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(),mats.end());
    int answer = -1;
    for(int mat : mats){
        if (matCanFill(mat,park) == true)
            answer = mat;
        else 
            return answer;
    }
    return answer;
}