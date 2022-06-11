#include<iostream>

int arr[201];
using namespace std;
int main()
{
        int num;
        cin >> num;
        int input;
        for (int i = 0; i < num; i++)
        {
                cin >> input;
                if (input < 0)
                        arr[input * -1 + 201]++;
                else
                        arr[input]++;
        }
        cin >> input;
        if (input < 0)
                cout << arr[input * -1 + 201];
        else
                cout << arr[input];
}