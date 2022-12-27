#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A,B,C;
	cin >> A >> B>> C;
	int come[3];
	int out[3];
	for (int i = 0; i < 3; i++)
	{cin >> come[i] >> out[i];}
	sort (come, come+3);
	sort(out, out+3);
	int level = 0;
	int cost = 0;
	for (int i=0; i < out[2];i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (come[j] == i)
				level++;
			if (out[j] == i)
				level--;
		}
		if (level == 1)
			cost +=(level *A);
		else if (level == 2)
			cost += (level * B);
		else if (level == 3)
			cost += (level *C);
	}
	cout << cost <<"\n";
}
