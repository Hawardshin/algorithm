#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;
bool 	vis[10000002];
int 	dis[10000002];
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int f,s,g,u,d;
	cin >> f>>s>>g>>u>>d;
	queue <int> Q;
	vis[s] =1;
	Q.push(s);
	if (s==g)
	{
		cout << 0;
		return (0);
	}
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		if (a + u > f && a - d < 1)
			continue ;
		if (a+u == g || a-d == g)
		{
			cout << dis[a] + 1;
			return (0);
		}
		if(a +u <= f && vis[a+u] == 0)
		{
			dis[a+u] = dis[a]+1;
			vis[a+u] =1;
			Q.push(a+u);
		}
		if (a-d > 0 &&vis[a -d] == 0)
		{
			dis[a - d] = dis[a] +1;
			vis [a- d] = 1;
			Q.push(a-d);
		}
	}
	cout << "use the stairs";
}
