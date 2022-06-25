/* 10,000,000,000//100억번

        L : 커서를 왼쪽으로 한칸 옮김
        D : 커서를 오른쪽으로 한칸 옮김
        B : 커서왼쪽의 문자를 삭제
        P $ : $ 라는 문자 커서 왼쪽에 추가.

 */
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
        //ios :: sync_with_stdio(0);
        //cin.tie();
        list<char> str;
        list<char> :: iterator cursor;
        string input;
        char command;
        int input_n;
        cin >> input;
        for (char a : input)
                str.push_back(a);
        cursor = str.end();
        //if (!str.empty())
        //      cursor--;
        //cout << *cursor;
        cin >> input_n;
        for (int i = 0; i < input_n; i++)
        {
                cin >> command;
                if (command =='L')
                {
                        //cout << "1\n";
                        if (cursor != str.begin())
                                cursor--;
                }
                else if(command == 'D')
                {
                        //cout << "2\n";
                        if (cursor != str.end())
                                cursor++;
                        //if (cursor == str.end())
                        //      cursor--;
                }
                else if(command == 'B')
                {

                                //cout << "3\n";
                                if (cursor != str.begin())
                                {
                                        //cursor--;
                                        cursor--;
                                        cursor = str.erase(cursor);
                                }

                }
                else if (command == 'P')
                {
                        //cout << "4\n";
                        char ins;
                        cin>> ins;
                //      if(cursor != str.begin())
                        //      cursor--;
                        str.insert(cursor,ins);
                //      if(cursor != str.begin())
                //              cursor++;
                }
        }
        for (list<char> :: iterator it = str.begin(); it != str.end(); it++)
                cout << *it;
}