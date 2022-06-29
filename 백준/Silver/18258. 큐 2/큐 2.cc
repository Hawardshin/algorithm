#include<iostream>
using namespace std;

int queue[2000000];
int head, tail;
int main()
{
        cin.tie(0);
        ios ::sync_with_stdio(0);
        int command_num;
        string command;
        cin >> command_num;
        for(int i =0; i < command_num; i++)
        {
                cin >> command;
                if (command == "push")
                {
                        int in;
                        cin >> in;
                        queue[tail] = in;
                        tail++;
                }
                else if (command =="pop")
                {
                        if (head != tail)
                        {
                                cout << queue[head] <<'\n';
                                head++;
                        }
                        else
                                cout << "-1\n";

                }
                else if (command == "size")
                {
                        cout << tail -head << '\n';
                }
                else if (command == "empty")
                {
                        if (tail == head)
                                cout << "1\n";
                        else
                                cout <<"0\n";
                }
                else if (command == "front")
                {
                        if (head == tail)
                                cout << "-1\n";
                        else
                                cout << queue[head] << '\n';
                }
                else if (command == "back")
                {
                        if (head == tail)
                                cout << "-1\n";
                        else
                                cout << queue[tail-1] << '\n';
                }

        }
}