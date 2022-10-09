		#include<iostream>
		#include<algorithm>
		#include<string>
		#include<vector>
		#include<stack>
		#include<queue>
		#include<utility>

		using namespace std;


		// int input[500001][2];
		int myarr[100001];
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
			cin >> n;
			for (int k=0; k < n;k++)
			{
			cin >> m;
			int arr [100001];
			for (int i=0;i < m ;i++)
			{
				cin >>arr[i];
				// cin >> myarr[i];
				// if (myarr[i] == n)
				// {
				// 	if (flag == 1)
				// 		break;
				// 	flag = 1;
				// }
				// a++;
			}
		// cout <<a;
		long long all_sum =0;;
			sort(arr,arr+m, cmp);
			for (int i =0; i < m; i++)
			{
				// arr[i]--;
				if (arr[i] <=0)
					break ;
				all_sum += arr[i];
				arr[i+1] -= i+1;
			}
			// all_sum++;
			cout << all_sum <<"\n";
			// for (int i=0; i <n;i++)
			// {
			// 	cout << arr[i] << " ";
			// }
			}
		}
