#include<iostream>

using namespace std;

int main(){
    int x;cin>>x;
    int n = 1;
    int ret =0;
    while (n<=64){
        if (n & x){
            ret++;
            x = x -n;
        }
        n*=2;
    }
    cout << ret<<"\n";
}