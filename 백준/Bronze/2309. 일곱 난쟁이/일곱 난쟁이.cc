#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr1(9,0);
vector <int> arr2(9,0);

void	result(int a1,int a2)
{
	for (int i=0; i<9; i++)
	{
		if (i != a1 && i != a2)
			cout << arr1[i] << '\n';
	}

}

int main()
{
	ios:: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i=0; i < 9; i++)
	{
		cin >> arr1[i];
		if (i != 0)
			arr2[i] = arr1[i] + arr2[i-1];
		else
			arr2[i] = arr1[i];
	}
	sort(arr1.begin(), arr1.end());
	for (int i =0 ; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (arr2[8] - (arr1[i] + arr1[j]) == 100)
			{
				result(i,j);
				return (0);
			}
		}
	}
	return (0);
}
