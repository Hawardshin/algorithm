/*
	( (()) ((()))
	최대 길이, 현재 길이 몇인지 가지고 있기
	현재 몇개 열렸는지 갯수
	여는거 갯수 저장, 만약 닫는게 나오면 그때부터는 닫기 갯수로 갯수 판별.
	열->닫 : 갯수 갱신
	닫->닫 : 이전에 연게 있으면 갯수 추가, 없으면 삭제
	닫->열 : 
	단 다시 여는게 나오는 순간
*/

#include <iostream>
#include <stack>
#include <algorithm>
#define CHR first
#define IDX second
using namespace std;
int n, tmp = 1, cnt = 0, ret = -987654321;
string str;

stack<pair<char,int>> st;
bool rightStr[200001];

int main(){
	cin >> n;
	string s;
	cin >> s;

	for(int i=0;i<n;i++){
		char a = s[i];
		if (a == '('){
			st.push({'(',i});
		}
		else if (a == ')'){
			if (!st.empty() && st.top().CHR == '('){
				rightStr[st.top().IDX] = true;
				rightStr[i] = true;
				st.pop();
			}else 
				st.push({')',i});
		}
		else
			cout << "crazy\n";
	}
	int max_len = 0;
	int now_len = 0;
	for(int i=0;i<s.size();i++){
		if (rightStr[i] == true && rightStr[i+1] == true){
			now_len+=2;
			i++;
		}else {
			max_len = max(max_len,now_len);
			now_len = 0;
		}
	}
	max_len = max(max_len,now_len);
	cout << max_len << "\n";
}