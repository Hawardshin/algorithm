	#include<iostream>
	#include<algorithm>
	#include <vector>
	#include <string>
	using namespace std;
	int main()
	{
		cin.tie(0);
		ios::sync_with_stdio(0);
		int n;
		vector<int> arr ,tmp;

		cin >>n;
		int num;
		for (int i=0; i< n; i++)
		{
			cin >> num;
			arr.push_back(num);
		}
		tmp.assign(arr.begin(), arr.end());
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	string answer;
	for(int i = 0 ; i < n ; i++){
		auto it = lower_bound(tmp.begin(), tmp.end(),arr[i]);
		answer += (to_string(it -tmp.begin()) + " ");
	}
	cout<<answer;
	}
