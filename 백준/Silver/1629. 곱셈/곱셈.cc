#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
int A,B,C;

ll p(ll x)
{
	if (x == 1)
		return (A%C);
	ll k = p(x/2)%C;
	if (x%2 == 0)
		return (k * k % C);
	else
		return(k*k %C* A % C);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> A>> B>> C;
	long long ret  = p(B);
	cout << ret;
}
