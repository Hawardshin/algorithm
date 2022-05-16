#include<iostream>

using namespace std;

int sum_digit(int n)
{
        if (n < 10)
                return (n);
        else
                return ((n % 10) + sum_digit(n / 10));
}
int main()
{
        int input;
        cin >> input;
        int tmp = 0;
        for (int i =0; i < input; i++)
        {
                if (i + sum_digit(i) ==input)
                {
                        cout << i;
                        return 0;
                }
        }
        cout << "0";
}