#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	map<string, string> site2password;
	for (int i = 0; i < N; i++)
	{
		string site, password;
		cin >> site >> password;
		site2password[site] = password;
	}

	for (int i = 0; i < M; i++)
	{
		string site;
		cin >> site;

		cout << site2password[site] << "\n";
	}

	return 0;
}