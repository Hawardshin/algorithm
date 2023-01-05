#include <iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;
int t_n;
int f_n;

int main()
{
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		int ret2 = 0, ret5 = 0;
		for(int j = 2; j <= a; j *= 2){
			ret2 += a / j;
		}
		for(int j = 5; j <= a; j *= 5){
			ret5 += a / j;
		}
		cout << min(ret2, ret5) << "\n";
	}
	return 0;
}
