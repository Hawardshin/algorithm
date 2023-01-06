#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string bef_time;

string make_ret_time(string ret, string bef,string now)
{
	char arr[6];
	arr[0] = now[0] -bef[0] + '0';
	arr[1] = now[1] - bef[1] + '0';
	arr[2] = ':';
	arr[3] = now[3] - bef[3] + '0';
	arr[4] = now[4] -bef[4] + '0';
	if (arr[4] <'0')
	{
		arr[4] = arr[4] + 10;
		arr[3]--;
	}
	if (arr[3] < '0')
	{
		arr[3] = arr[3] + 6;
		arr[1]--;
	}
	if (arr[1] < '0')
	{
		arr[0]--;
		arr[1]= arr[1] + 10;
	}
	if ('9'< arr[4])
	{
		arr[4] = arr[4] - 10;
		arr[3]++;
	}
	if ('5'<arr[3])
	{
		arr[3] = arr[3] - 6;
		arr[1]++;
	}
	if ('9' < arr[1])
	{
		arr[1] = arr[1] - 10;
		arr[0]++;
	}
	arr[5] = '\0';
	arr[0] = arr[0]  + ret[0] - '0';
	arr[1] = arr[1] + ret[1] - '0';
	arr[2] = ':';
	arr[3] = arr[3] + ret[3] - '0';
	arr[4] = arr[4] + ret[4] - '0';
	if (arr[4] <'0')
	{
		arr[4] = arr[4] + 10;
		arr[3]--;
	}
	if (arr[3] < '0')
	{
		arr[3] = arr[3] + 6;
		arr[1]--;
	}
	if (arr[1] < '0')
	{
		arr[0]--;
		arr[1]= arr[1] + 10;
	}
	if ('9'< arr[4])
	{
		arr[4] = arr[4] - 10;
		arr[3]++;
	}
	if ('5'<arr[3])
	{
		arr[3] = arr[3] - 6;
		arr[1]++;
	}
	if ('9' < arr[1])
	{
		arr[1] = arr[1] - 10;
		arr[0]++;
	}
	return (arr);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int first_score =0;
	int second_score = 0;
	int now_win = -1;
	string ret1,ret2;
	ret1 = "00:00";
	ret2 ="00:00";
	for (int i=0;i < n;i++)
	{
		int input_num;
		string time;
		cin >> input_num >> time;
		if (input_num == 1)
			first_score++;
		else
			second_score++;
		if (first_score > second_score)
		{
			if (now_win == -1)
				bef_time = time;
			now_win = 1;
		}
		else if (first_score < second_score)
		{
			if (now_win == -1)
				bef_time = time;
			now_win = 2;
		}
		else //fist_score == second_score
		{
			if (now_win == 1)
				ret1 = make_ret_time(ret1,bef_time,time);
			else if (now_win == 2)
				ret2 = make_ret_time(ret2,bef_time,time);
			now_win = -1;
		}
		// cout <<"ret1 :" <<ret1 <<"ret2 : "<<ret2  << "bef: " << bef_time<< "\n";
	}
	if (now_win == 1)
		ret1 = make_ret_time(ret1,bef_time,"48:00");
	else if (now_win == 2)
		ret2 = make_ret_time(ret2,bef_time,"48:00");
	cout << ret1 << "\n" <<  ret2 << "\n";

}
