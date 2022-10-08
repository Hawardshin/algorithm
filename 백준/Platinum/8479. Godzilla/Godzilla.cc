#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

int arr [100001];
int input[500001][2];

bool cmp(int a,int b)
{
	return (a > b);
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >>m;
	for (int i=0; i < n;i++)
	{
		cin >>arr[i];
	}

	for (int i =0; i< m; i++)
	{
		cin >> input[i][0];
		cin >> input[i][1];
	}
long long all_sum =0;;
	sort(arr,arr+n, cmp);
	for (int i =0; i < n; i++)
	{
		if (arr[i] <=0)
			break ;
		all_sum += arr[i];
		arr[i+1] -= i+1;
	}
	cout << all_sum <<"\n";
	// for (int i=0; i <n;i++)
	// {
	// 	cout << arr[i] << " ";
	// }

}
