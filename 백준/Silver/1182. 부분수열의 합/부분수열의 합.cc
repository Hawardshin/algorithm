#include<bits/stdc++.h>
using namespace std;
int n,s;
int cnt;
int num[21];
int ret[21]; // 결과를 담을 배열
void	func(int k,int tot)
{
	if (k == n)
	{
		if (tot == s)
			cnt++;
		return ;
	}
	func(k+1,tot);
	func(k+1,tot+num[k]);
}

int main()
{
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>s;
	for (int i=0;i < n;i++) cin >> num[i];
	func(0,0);
	if ( s== 0 )
		cnt --;
	cout << cnt;
}
