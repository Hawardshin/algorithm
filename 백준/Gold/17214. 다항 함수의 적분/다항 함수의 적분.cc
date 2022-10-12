#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
//상수만 있는 경우
//식과 상수가 있는 경우
//식만 있는 경우
//식과 상수가 다 있는 경우
// 상수가 0인경우
// 부호, 숫자, 문자 순
int ft_ctoi(char a)
{
	if ('0'<=a && a<= '9')
		return (a-'0');
	else
		return (-1);
}

int ft_stoi(string &s, int start, int end)
{
	int flag = 1;
	if (s.at(start) == '-')//+++이런 경우 안 하긴 했음
	{
		flag = -1;
		start++;
	}
	else if (s.at(start) == '+')
		start++;
	int ret = 0;
	while (start < end)
	{
		ret *=10;
		ret += s.at(start) -'0';
		start++;
	}
	return (flag *ret);
}
int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	if (input.at(0) == '0')
	{
		cout << "W\n";
		return 0;
	}
	int idx = 0;
	int flag =0;
	int minus = 1;
	if (input.at(0)== '-' || input.at(0) == '+')//+인 경우도 해야 맞는듯..
		idx++;
	while (idx <input.length())
	{
		if (ft_ctoi(input.at(idx)) == -1)
		{
			flag =1;
			break;
		}
		// cout << input.at(idx);
		idx++;
	}
	if (flag == 0)//상수만 있는 경우 처리 상수 0인경우, 음수까지 처리 완.
	{
		// if (minus == -1)
		// 	cout << '-';
		int inin=ft_stoi(input,0,input.length());
		if (inin == 1)
			cout << "x+W";
		else if (inin == -1)
			cout << "-x+W";
		else
			cout << inin << "x+W";
		return 0;
	}
	int Xnum = 0;
	if (idx < input.length())//1차 항의 경우만.
	{
		int inin = ft_stoi(input, 0,idx);
		inin /=2;
		if (inin == 1)
			cout << "xx";
		else if (inin == -1)
			cout << "-xx";
		else
			cout << inin << "xx";
	}
	idx++;
	if (idx < input.length() &&(input.at(idx) == '-' || input.at(idx) == '+'))
	{
		int inin = ft_stoi(input, idx,input.length());
		if (inin == 0)
			cout << "+W";
		else if (inin == -1)
			cout << "-x+W";
		else if (inin < 0)
			cout << inin << "x+W";
		else if (inin != 1)
			cout <<"+" <<inin<< "x+W";
		else
			cout << "+x+W";
	}
	else
		cout << "+W";

}
