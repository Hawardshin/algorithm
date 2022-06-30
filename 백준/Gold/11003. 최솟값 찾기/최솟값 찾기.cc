#include<deque>
#include<iostream>
#include<utility>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  deque<pair<int, int>> dq;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    while (!dq.empty() && dq.back().second >= num) { //계속 작은값이 앞에 올 수 있도록 하는 와일문
      dq.pop_back();
    }
    
    // 새로운 숫자는 항상 삽입
    dq.push_back({i, num});

    // 주어진 구간을 벗어나는 숫자 제거해줍니다.
    if (dq.front().first <= i - m) {
      dq.pop_front();
    }

    cout << dq.front().second << " ";
  }

  return 0;
}