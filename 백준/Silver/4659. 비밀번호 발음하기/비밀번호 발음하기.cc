#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int is_have_small(char a)
{
	if (a == 'a' || a=='e' || a =='i' || a== 'o' || a=='u')
		return (1);
	// cout << "1";
	return (0);
}

int check_opt2(char a1,char a2,char a3)
{
	if (is_have_small(a1) && is_have_small(a2) && is_have_small(a3))
		return (1);
	else if (!is_have_small(a1) && !is_have_small(a2) && !is_have_small(a3))
		return (1);
	return (0);
}
int check_opt3(char a1 ,char a2)
{
	if (a1 == a2)
	{
		if (a1 != 'e' && a1 != 'o')
			return (1);
	}

	return (0);
}

int	check(string s)
{
	int size = s.size();
	int opt1 = 0;
	char first ,second , third;
	for(int i =0;i < size;i++)
	{
		if (opt1 == 0 && is_have_small(s[i]))
				opt1 = 1;
		if (i == 0)
			first = s[i];
		else if (i == 1)
		{
			second = s[i];
			if (check_opt3(first,second))
				return (1);
		}
		else if (i == 2)
		{
			third = s[i];
			if (check_opt2(first,second,third) ||check_opt3(first,second) || check_opt3(second,third))
				return (1);
		}
	 	else
		{
			first = second;
			second = third;
			third = s[i];
			if (check_opt2(first,second,third) ||check_opt3(first,second) || check_opt3(second,third))
				return(1);
		}
	}
	if (opt1 == 0)
		return (1);
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	// cin.tie(0);

	string s;
	// cout <<"abc";
	while (1)
	{
		cin >>s;
		// cout <<s;
		if (s == "end")
			return(0);
		if (!check(s))
			cout << '<' << s <<'>' << " is acceptable.\n";
		else
			cout << '<' << s <<'>' << " is not acceptable.\n";
	}
}
