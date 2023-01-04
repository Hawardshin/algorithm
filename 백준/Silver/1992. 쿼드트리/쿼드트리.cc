#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int check_all_same(int x,int y,int size,vector<vector<int>> &bmap)
{
	int start = bmap[y][x];
	for (int i=y; i < y + size;i++)
	{
		for (int j=x; j <x+ size;j++)
		{
			if (bmap[i][j] != start)
				return (0);
		}
	}
	return (1);
}

void	recur(int x,int y,int size,vector<vector<int>> &bmap)
{
	if (size == 1|| check_all_same(x,y,size, bmap))
	{
		cout << bmap[y][x];
	}
	else
	{
		cout << "(";
		recur(x,y,size/2,bmap);
		recur(x + size/2,y,size/2,bmap);
		recur(x,y+ size/2,size/2,bmap);
		recur(x+ size/2,y+ size/2,size/2,bmap);
		cout << ")";
	}
}

int main()
{
	int n;
	cin >> n;

	vector <vector<int>> bmap(n+1,vector<int>(n+1, 0));
	string s;
	for (int i=1;i <= n;i++)
	{
		cin >>s;
		for (int j=1;j <= n;j++)
		{
			bmap[i][j] = (int)(s[j - 1]-'0');
		}
	}
	// if (check_all_same(1,1,n,bmap) ==1)
	// {
	// 	cout << "(";
	// 	cout << bmap[1][1];
	// 	cout << ")";
	// }
	// else
		recur(1,1,n,bmap);
}
