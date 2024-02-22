#include <iostream>
#include <queue>
#include <vector>
// #include <priority_queue>

using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int>> pq;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if (x ==0){
			// cout << "aa";
			if (pq.empty())
				cout<< 0 << "\n";
			else {
				cout << pq.top() <<"\n";
				pq.pop();
			}
		}
		else 
			pq.push(x);
	}

}
