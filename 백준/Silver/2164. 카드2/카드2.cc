#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> Q;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) Q.push_front(i);
    while (Q.size() > 1){
        Q.pop_back();
        int n = Q.back();
        Q.pop_back();
        Q.push_front(n);
    }
    cout << Q.front();
}