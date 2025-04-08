#include<iostream>
using namespace std;
int main(){
    int n,m;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>> n>>m;
    int arr[1025][1025];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> arr[i][j];
            if (j != 0)
                arr[i][j] = arr[i][j] + arr[i][j-1];
        }
    }
    int x1,y1,x2,y2;
    int answer;
    for(int i=0;i<m;i++){
        answer = 0;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1-1;j<x2;j++){
            answer += arr[j][y2-1];
            if (y1 > 1)
                answer-= arr[j][y1-2];
        }
        cout << answer << "\n";
    }
}