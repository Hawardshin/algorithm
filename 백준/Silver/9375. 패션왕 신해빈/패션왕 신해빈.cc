#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<map>

using namespace std;
int tc, n;
string a, b;
int main(){
	cin >> tc;
	for(int i = 0; i < tc; i++){
		cin >> n;
		map<string, int> _map1; // 옷 종류별로 갯수를 세는 map 생성
		for(int j = 0; j < n; j++){
		cin >> a >> b;
		_map1[b] += 1; // 옷 종류에 따라 갯수 +1씩 증가시킨다.
		}
		long long result = 1;
		for(auto a : _map1){
			result *= ((long long)a.second+1); // (각 옷 종류별 갯수+1)를 곱한 뒤 1을 뺀다.
		}
		result--;
		cout << result << "\n";
	}
	return 0;
}
