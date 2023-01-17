#include <bits/stdc++.h>

using namespace std;

int n,m;
int ret[8];
int vis[8];

void	func(int s,int nu)
{
	if (nu == m)
	{
		for(int i=0;i < m;i++) cout << ret[i]<< " ";
		cout << "\n";
		return ;
	}
	for (int i = s+1;i <= n;i++)
	{
		ret[nu] = i;
		func(i,nu+1);
	}
}


int main()
{
	cin >> n >> m;
	func(0,0);
}
