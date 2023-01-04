#include <iostream>

using namespace std;

int main()
{
	int N,M,j;
	cin >> N>> M >> j;
	int L = 1;
	int aloc;
	int cnt =0;
	M--;
	for (int i=0;i < j;i++)
	{
		cin >> aloc;
		if (L <= aloc && aloc <= L + M)
			continue;
		else
		{
			if (aloc - (L + M) > 0)
			{
				cnt += (aloc - (L + M));
				L = aloc- M; // L + aloc - L - M ;
			}
			else
			{
				cnt += L-aloc;
				L = aloc; //L-L+aloc;
			}
		}
		// cout  << "L : "<<L << "\n";
		// cout  << "aloc : "<<aloc << "\n";
		// cout  << "cnt : "<< cnt << "\n";
	}
	cout << cnt ;
}