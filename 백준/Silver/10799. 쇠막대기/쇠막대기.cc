#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main()
{
        int o_count =0;
        int result =0;;
        ios:: sync_with_stdio(0);
        cin.tie(0);
        stack<char> pipe;
        string s;
        cin >> s;
        int s_size = s.size();
        for (int i =0; i < s_size; i++)
        {
                if (s[i] == '(')
                {
                        o_count++;
                        result++;
                        pipe.push('(');
                }
                else
                {
                        if (pipe.top() == '(')
                        {
                                pipe.pop();
                                o_count--;
                                result--;
                                result+= o_count;
                                pipe.push(')');
                        }
                        else
                        {
                                pipe.pop();
                                pipe.pop();
                                o_count--;
                                pipe.push(')');
                        }
                }
        }
        cout << result;
}