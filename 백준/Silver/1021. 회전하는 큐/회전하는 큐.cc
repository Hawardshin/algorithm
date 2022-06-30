#include<deque>
#include<iostream>
//left : pop_back -push_front
//right : pop_front _push_back
using namespace std;
int arr[200];
int head = 50;
int tail = 50;


int count_left(int to_find,deque<int>dq)
{
        int count =0;
        while (to_find != dq.front())
        {
                dq.push_front(dq.back());
                dq.pop_back();
                count ++;
        }
        return (count);
}

int count_right(int to_find,deque<int>dq)
{
        int count = 0;
        while (to_find != dq.front())
        {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
        }
        return (count);
}

void go_right(int to_find,deque<int>& dq)
{
        while (to_find != dq.front())
        {
                dq.push_back(dq.front());
                dq.pop_front();
        }
        dq.pop_front();
}

void go_left(int to_find,deque<int>& dq)
{
        while (to_find != dq.front())
        {
                dq.push_front(dq.back());
                dq.pop_back();
        }
        dq.pop_front();
}
int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);
        int size,how_many,to_find,l_count,r_count;
        int move =0;
        cin >> size >> how_many;
        deque<int> dq;
        for (int i =1 ; i <= size; i++)
        {
                dq.push_back(i);
        }
        for (int i = 0; i < how_many; i++)
        {
                cin >> to_find;
                l_count =count_left(to_find,dq);
                r_count = count_right(to_find,dq);
                if (l_count > r_count)
                {
                        go_right(to_find,dq);
                        move+=r_count;
                }
                else
                {
                        go_left(to_find,dq);
                        move+=l_count;
                }
        }
        cout << move;
}