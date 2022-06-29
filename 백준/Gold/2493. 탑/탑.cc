#include<iostream>
#include<stack>
#include<utility>
using namespace std;

stack<pair<int,int>> q;
int start =1;
//값, 순서
//왼쪽 값보다 더 큰값이 나오면 의미가 없어진다. pop
//그 경우 바로 터트리고, 그 값의 위치를 표시한다.
//즉 왼족 값보다 오른쪽이 더 작다면 push하면서 출력
//왼쪽 값보다 오른쪽 값이 더 크가면 pop하면서 출력
int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);
        int num;
        cin >> num;
        int array_num;
        while(start <=num)
        {
                cin >> array_num;
                if(q.empty())
                {
                        cout << "0 ";
                        q.push(make_pair(array_num,start));
                }
                else if(q.top().first > array_num)
                {
                        {
                                cout << q.top().second << ' ';
                                q.push(make_pair(array_num,start));
                        }
                }
                else
                {
                                while (!q.empty() && q.top().first < array_num)
                                {
                                        q.pop();
                                }
                                if (q.empty())
                                {
                                        cout << "0 ";
                                }
                                else
                                {
                                        cout <<q.top().second<< ' ';
                                }
                                q.push(make_pair(array_num,start));
                }
                start++;
        }
}