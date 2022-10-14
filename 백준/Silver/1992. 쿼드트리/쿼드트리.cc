#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

int arr[65][65];

bool chk_all_same(int x,int y, int size)
{
	int t =arr[y][x];
	for (int i=0;i < size;i++)
	{
		for (int j=0; j<size;j++)
		{
			if (t != arr[i+y][j+x])
				return(0);
		}
	}
	return (1);
}

// void	print_arr(int x, int y, int size)
// {
// 	for (int i=0; i <size;i++)
// 	{
// 		for (int j=0; j<size;j++)
// 		{
// 			cout << arr[y+i][x+j];
// 		}
// 	}
// }


void	recur(int x,int y, int size)
{
	if (size == 1)
	{
		cout << arr[y][x];
		return ;
	}
	if (chk_all_same(x,y,size))
	{
		cout << arr[y][x];
		return ;
	}
	else
	{
		cout << "(";
		for (int i=0; i<2;i++)
		{
			for (int j=0; j<2;j++)
			{
				recur(x+j*(size/2),y+i*(size/2),size/2);
			}
		}
		cout <<")";
	}
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int input;
	cin >> input;
	string s;

	for (int i=1; i <=input; i++)
	{
		cin >> s;
		for (int j=1; j<=input;j++)
		{
			arr[i][j] = s[j-1] - '0';
		}
	}
	// cout << "(";
	recur(1,1,input);
	// cout << ")";
}
