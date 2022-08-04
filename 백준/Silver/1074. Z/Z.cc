#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>
#include<cmath>
using namespace std;


int recur (int n,int r,int c)
{
	if (n == 0)
	return (0);
	int half = 1 << (n-1);
	if (r < half && c < half)
		return(recur(n-1,r,c));
	if (r < half && c >=half)
		return (half*half + recur(n-1,r,c-half));
	if (r >=half && c < half)
		return (2 * half *half + recur(n-1,r-half,c));
	return (3 * half * half + recur(n-1,r-half ,c-half));
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int n ,x,y;
	cin >> n >> x >>y;
	cout << recur(n,x,y);
}
