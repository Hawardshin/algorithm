#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
/*
auto it = std::find_if( sortList.begin(), sortList.end(),
    [&User](const std::pair<std::string, int>& element){ return element.first == User.name;} );
*/

bool my_sort(pair<int,int> a,pair<int,int> b)
{
	return (a.second > b.second);
}

// bool isEqual(pair<int, int>& e)
// {
//     return e.first ==  num;
// }

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int n,c;
	cin >> n >> c;
	// unordered_map <int,int> arr;
	vector<pair<int ,int >>arr;
	int num;
	for (int i=0;i < n;i++)
	{
		cin >> num;
		// if (i != 0)
		auto a = find_if(arr.begin(),arr.end(), [&num](const pair<int, int>& elem){ return elem.first == num;});
		// auto a = find(arr.begin(),arr.end(),num);
		if (i == 0 || a == arr.end())
		{
			arr.push_back({num,1});
		}
		else
			a->second++;
	}
	// vector<pair<int,int>> v(arr.begin(),arr.end());
	stable_sort(arr.begin(),arr.end(),my_sort);
	for (auto it : arr)
	{
		for (int i=0; i < it.second;i++)
		{
			cout << it.first<< " ";
		}
	}
}
//unordered map은 자동으로 정렬이 되지 않지만 그렇다고 입력된 순으로 값을 저장하고 있지 않다는 성질이 있어서 위의 코드가 틀렸었습니다
