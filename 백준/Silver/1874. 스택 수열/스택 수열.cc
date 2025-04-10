#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n; cin >>n;
    stack <int> st;
    int input[100001];
    for(int i=0;i<n;i++) cin >> input[i];
    int i_idx = 0;
    bool answer[200001];
    int num = 1;
    int a_idx = 0;
    while(i_idx < n && a_idx < 2*n){
        if (st.empty() || num != st.top()){
            st.push(num);
            answer[a_idx++]= true;
            num++;
        }
        while (!st.empty() && st.top() == input[i_idx]){
            st.pop();
            answer[a_idx++] = false;
            i_idx++;
        }
    }
    if (!st.empty() || i_idx != n)
        cout << "NO\n";
    else{
        for(int i=0;i<a_idx;i++){
            if (answer[i] == true)
                cout << "+\n";
            else
                cout << "-\n";
        }
    }
}