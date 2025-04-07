#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >>m;
    int ar[100001];
    for(int i=0;i<n;i++){
        cin >> ar[i];
        if (i !=0)
            ar[i] = ar[i]+ ar[i-1];
    }
    
    int a,b;
    for(int i=0;i<m;i++){
        cin >>a >>b;
        if (a == 1){
            cout << ar[b-1] <<"\n";
        }else{
            cout <<ar[b-1] - ar[a-2] <<"\n";
        }
    }
}