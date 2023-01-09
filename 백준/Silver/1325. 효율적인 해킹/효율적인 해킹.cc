#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>


using namespace std;

int compu_num,n;
vector<int> compu[10001];
int result[10001];
int vis[10001];
int maxi;

int dfs(int a)
{
	vis[a] = 1;
	int ret = 1;
	for (int k : compu[a])
	{
		if (vis[k])
			continue;
		ret +=dfs(k);
	}
	return (ret);
}
int main()
{
	ios:: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> compu_num >> n;

	for (int i=0;i < n;i++)
	{
		int down,up;
		cin >> down>> up;
		compu[up].push_back(down);
	}

	for (int i=1;i <= compu_num;i++)
	{
		memset(vis, 0, sizeof(vis));
		result[i]= dfs(i);
		maxi = max(result[i],maxi);
	}

	for (int i = 0; i<=compu_num;i++)
	{
		if (maxi == result[i])
			cout << i << " ";
	}
}
