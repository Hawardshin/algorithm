#include<iostream>
#include<list>
using namespace std;


void print_note(string s)
{
                list<char> note;
                list<char>:: iterator cur;
                cur = note.end();
                for (char a: s)
                {
                        if (a == '<')
                        {
                                if (cur != note.begin())
                                        cur--;
                        }
                        else if( a== '>')
                        {
                                if (cur != note.end())
                                        cur++;
                        }
                        else if (a == '-')
                        {
                                if(cur != note.begin())
                                {
                                        cur--;
                                        cur = note.erase(cur);
                                }
                        }
                        else
                        {
                                note.insert(cur,a);
                        }
                }
                for (char a:note)
                {
                        cout << a;
                }
                cout<< "\n";
}
int main()
{

        int n;
        cin>> n;
        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                print_note(s);
        }

}