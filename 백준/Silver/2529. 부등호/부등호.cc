#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
bool vis[10];
char num_ar[10] = {0,1,2,3,4,5,6,7,8,9};
char cal[10];//부등호 배열
int in_len;
char min_ret[10];
char max_ret[10];

bool make_minret(int now_size){//지금 몇개의 숫자를 채웠는지 리턴은 숫자가 해당하는 갯수만큼 찾았을때만 true가 되서 모든 재귀를 탈출한다.
	// cout << now_size << "\n";
	if (now_size == in_len + 1)
	{
		if (cal[now_size - 1] == '<' && min_ret[now_size - 2] > min_ret[now_size -1])
			return false;
		else if (cal[now_size - 1] == '>' && min_ret[now_size - 2] < min_ret[now_size -1])
			return false;
		for(int i=0;i < in_len + 1;i++){
			cout << (int)min_ret[i];
		}
		cout << "\n";
		return true;
	}else {
		for(int i=0; i<10;i++){
			min_ret[now_size] = num_ar[i];
			if (vis[i] != true){
				if (now_size != 0){
					if (cal[now_size - 1] == '<' &&  min_ret[now_size - 1]> min_ret[now_size])
						continue;
					else if (cal[now_size - 1] == '>' && min_ret[now_size - 1] < min_ret[now_size])
						continue;
				}
				vis[i] = true;
				if (make_minret(now_size+1))
					return (true);
				vis[i] = false;
			}
		}
	}
	return false;
}


bool make_maxret(int now_size){
	if (now_size == in_len + 1)
	{
		if (cal[now_size - 1] == '<' && max_ret[now_size - 2] > max_ret[now_size -1])
			return false;
		else if (cal[now_size - 1] == '>' && max_ret[now_size - 2] < max_ret[now_size -1])
			return false;
		for(int i=0;i < in_len + 1;i++){
			cout << (int)max_ret[i];
		}
		cout << "\n";
		return true;
	}else {
		for(int i=9; i >=0 ;i--){
			max_ret[now_size] = num_ar[i];
			if (vis[i] != true){
				if (now_size != 0){
					if (cal[now_size - 1] == '<' &&  max_ret[now_size - 1]> max_ret[now_size])
						continue;
					else if (cal[now_size - 1] == '>' && max_ret[now_size - 1] < max_ret[now_size])
						continue;
				}
				vis[i] = true;
				if (make_maxret(now_size+1))
					return (true);
				vis[i] = false;
			}
		}
	}
	return false;
}

int main(){
	cin >> in_len;
	char tmp;
	for(int i=0;i < in_len;i++){
		cin>> cal[i];
	}
	make_maxret(0);
	memset(vis,0,sizeof(vis));
	make_minret(0);
}