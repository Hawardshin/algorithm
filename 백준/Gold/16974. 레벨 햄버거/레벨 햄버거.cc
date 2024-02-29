/*

*/
#include <iostream>
using namespace std;
int N; //버거의 갯수
long long X; //먹은 높이
long long burger[51]; //레벨 당 버거의 크기
long long patty[51]; // 레벨 당 패티의 갯수

void init(){
	burger[0] = 1;
	patty[0] = 1;
	for(int i=1; i<=N;i++){
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1;
		patty[i] = patty[i - 1] + 1 + patty[i - 1];
 	}
}

//버거의 크기 레벨, 먹은 높이
long long ate(int n, long long x){
	if (n == 0)
		return x;
	if (x == 1)
		return 0;
	if (x <= 1 +  burger[n-1]){ // 현재 높이가 구간 1또는 2에 해당, 하나 낮은 레벨의 버거의 크기 +1 
		return ate(n-1, x-1); // 버거의 레벨을 하나 줄이고, 먹은 높이를 하나 낮춘다.
	}

	if (x == 1 + burger[n-1] +1) // 버거가 다먹은 위치에 해당하는 경우
		return patty[n-1]+1;
	if (x <= 1+ burger[n-1] +1 + burger[n-1] )
		return patty[n-1] + 1 + ate(n-1, x - (1 + burger[n-1]+1));
	
	return patty[n-1] + 1 + patty[n-1];
}

int main(){
	cin >> N >> X;
	init();
	cout << ate(N,X) << "\n";
}