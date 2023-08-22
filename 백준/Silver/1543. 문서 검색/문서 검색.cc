# include <iostream>
# include <string>
# include <algorithm>

using namespace std;
int main(){
	string a,b;
	// cin >> a >> b;
	getline(cin,a);
	getline(cin,b);
	int ret = 0, idx = 0;
	idx = a.find(b);
	int b_size = b.length();
	while (idx != string::npos){
		ret++;
		a.erase(0, idx + b_size);
		idx = a.find(b);
	}
	cout << ret << "\n";
}