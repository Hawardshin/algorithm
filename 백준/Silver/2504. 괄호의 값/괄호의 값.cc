#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<utility>
#include<string.h>

using namespace std;

int check_p(const char &a)
{
	if (a == '(')
		return(2);
	else if (a == '[')
		return (3);
	else if (a == ')')
		return (-2);
	else if (a == ']')
		return (-3);
	else
		return (0);
}
//(()[[]])
//(2+3*3) *2
//1. empty -- 결과값과 별개로 덧셈 (얘는 곱셈안함)
//2. cal == 1 :
int depth[16];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	string par;
	cin >> par;
	int cal = 0; // 0 일때 더하기 1일때 곱하기
	int plen = par.length();
	stack <char> input;
	int cnt =0;
	for (int i = 0; i < plen; i++)
	{
		if (check_p(par[i]) > 0)
		{
			input.push(par[i]);
			cal = 0;
			cnt++;
		}
		else if (input.empty() && check_p (par[i])<=0)
		{
			cout << "0";
			return 0;
		}
		else if (!(check_p(input.top()) + check_p(par[i])))
		{
			int tmp = check_p(input.top());
			input.pop();
			if (cal == 1)
			{
				depth[cnt-1] += tmp * depth[cnt];
				depth[cnt] = 0;
				cnt--;
			}
			else
			{
				cnt--;
				depth[cnt]+=tmp;
			}
			cal = 1;
		}
		else
		{
			cout << "0";
			return 0;
		}
		//cout << depth[cnt] << "depth[cnt]" << cnt << "\n";
	}
	cout << depth[0];
}
