#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
/*
첫째줄 input /2인 값까지 공백 출력 후 * 출력 후 다시 input까지 공백
2째줄 직전의 출력값에서 1개 줄여서 첫행 출력 후 공백 후 다시 출력
3 - 직전의 값에서 1개 줄여서 출력 후 5개출력 후 공백 출력
1, 2,3 끝나면 다시 직전 처음 출력 값에 열 증가 따라 하나씩 늘어가면서
다시 처음으로 돌아가서 그 값을 출력해준다.
*/
using namespace std;

// void	print_star()
// {
// 	cout << "  *  \n"
// 		 << " * * \n"
// 		 << "***** \n";
// }
/*
dep0 :
dep * 3 +1행 input /2열 - (행 -1) 출력
dep * 3 +2행 input /2 -(행-1),(행+1) 열
dep * 3 +3행 input/2 -(행 -1) 부터 5게
dep 1 :
dep * 3 +1행 input /2 - (행 -1) , input +(행 + 1)
dep * 3 +2행 input/2 -(행 - 1), (행 +1), input + (행 -1), (행 + 1)
dep * 3 +3행 input/2 - (행-1)부터 5개 (행+1)
dep 2 :
dep * 3 + 1행
dep * 3 + 2행
dep * 3 + 3행
dep 3 :

dep 4 :
dep 5 :

너무 돌아갔다.
*/
/*
진짜 풀이
1. 배열을 선언해서 그 안에 공백들을 미리 넣어주고 끝날 때 그 배열을 다 출력한다.
2. 가장 큰 삼각형의 꼭짓점을 넣어주면서 재귀를 시작한다.
3. 재귀적으로 들어가면서 각 점의 절반지점을 찍으면서 꼭짓점을 지정해준다.
4. 계속해서 재귀적으로 들어가서 결국 길이가 3이 된 경우 각 꼭짓점을 시작으로 해서 그림을 넣어준다.
5. 각 재귀들이 모든 꼭짓점이 있기 때문에 알아서 그려준다.
*/
char arr[6145][6145];
void	draw(int row,int col)
{
	arr[row][col] = '*';
	arr[row+1][col-1] = '*';
	arr[row+1][col+1] = '*';
	for (int i=0; i<5;i++)
		arr[row+2][col-2 + i] = '*';
}
void	recur(int row,int col ,int len) // 각 삼각형의 col은 가로 시작점
//row는 세로 시작점이다.
{
	if (len == 3)
	{
		draw(row,col);
		return;
	}
	else
	{
		recur(row,col, len/2);
		recur(row + len /2, col-len/2 ,len/2);
		recur(row + len/2, col+len/2 ,len/2);
	}
}

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int input;
	cin >> input;
	for (int i=0; i< input; i++)
	{
		for (int j=0; j < 2*input;j++)
			arr[i][j] = ' ';
	}
	recur(0,input-1,input);
	for (int i=0; i< input; i++)
	{
		for (int j=0; j < 2*input;j++)
			cout << arr[i][j];
		cout << "\n";
	}
}