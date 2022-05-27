#include<deque>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        int command_num;
        string command;
        cin >> command_num;
        deque <int> a;
        int tmp;
        for (int i =0; i < command_num; i++)
        {
                cin >> command;
                if (command == "push_back")
                {
                        cin>>tmp;
                        a.push_back(tmp);
                }
                else if (command == "push_front")
                {
                        cin>> tmp;
                        a.push_front(tmp);
                }
                else if (command == "pop_front")
                {
                        if (a.size() == 0 )
                                cout << "-1"<< "\n";
                        else
                        {
                                cout << a.front()<<"\n";
                                a.pop_front();
                        }
                }
                else if (command == "pop_back")
                {

                        if (a.size() == 0 )
                                cout << "-1"<< "\n";
                        else
                        if (a.size() == 0 )
                                cout << "-1"<< "\n";
                        else
                        {
                                cout << a.back() << "\n";
                                a.pop_back();
                        }
                }
                else if (command == "size")
                {
                        cout << a.size()<<"\n";
                }
                else if (command == "empty")
                {
                        cout << a.empty()<<"\n";
                }
                else if (command == "front")
                {
                        if (a.size() == 0 )
                                cout << "-1"<< "\n";
                        else
                                cout << a.front() << "\n";
                }
                else if (command == "back")
                {
                        if (a.size() == 0 )
                                cout << "-1"<< "\n";
                        else
                                cout << a.back() << "\n";
                }
        }
}