#include<iostream>
#include<stack>
using namespace std;
char result[10000000];
int main()
{
        stack <int> stack;
        int input_num;
        cin >> input_num;
        int *sequence = new int [input_num];

        for (int i = 0; i < input_num; i++)
        {
                cin >> sequence[i];
        }
        int i = 0;
        int rindex = 0;
        for (int j = 1; j <= input_num; j++)
        {
                stack.push(j);
                result[rindex] ='+';
                rindex++;
                while(!stack.empty() &&sequence[i] == stack.top())
                {
                        stack.pop();
                        result[rindex] = '-';
                        rindex++;
                        i++;
                }
        }
        if (!stack.empty())
        {
                cout << "NO\n";
        }
        else
        {
                for (int k = 0; k < rindex;k++)
                {
                        cout << result[k]<< "\n";
                }
        }
        return (0);
}