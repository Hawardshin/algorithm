#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    priority_queue<pair<int,int> ,vector <pair<int,int> >, greater<pair<int,int> > > pq;//절대값, 실제값.
    int n ;
    cin >>n;
    int t;
    for(int i=0;i<n;i++){
        cin >> t;
        if (t == 0){
            if (pq.empty())
                cout << 0 <<"\n";
            else {
                cout << pq.top().second <<"\n";
                pq.pop();
            }
        }else {
            pq.push(make_pair(abs(t),t));
        }
    }
}