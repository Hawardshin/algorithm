#include <iostream>
#include <algorithm>
using namespace std;
int input[100001];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for (int i=0; i < n; i++){
		cin >> input[i];
	}
	sort(input, input+ n);
	int start = 0;
	int end = 0;
	int ret = 2147483647;
	for (; start < n; start++){
		while(end< n && input[end] - input[start] < m) end++;
		if (end == n) break;
		ret = min (ret, input[end] - input[start]);
	}
	cout << ret << "\n";
}