#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue <int> people;
    int n, k, removedPeopleNum = 0;
    int current = 1;
    cin >> n >> k;
    for(int i = 1; i<=n; i++) people.push(i);
    cout << "<";
    while(removedPeopleNum!=n){
        while(1){
            if(current++ % k == 0){
                cout << people.front();
                people.pop();
                removedPeopleNum++;
                break;
            }
            else{
                people.push(people.front());
                people.pop();
            }
        }
        if(removedPeopleNum != n) cout << ", ";
    }
    cout << ">";
}