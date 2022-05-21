#include<iostream>

using namespace std;
int main()
{
        int arr[7];
        int min = 101;
        int sum = 0;
        for (int i=0; i < 7; i++)
        {
                cin >> arr[i];
                if (arr[i] % 2 == 1)
                {
                        sum+=arr[i];
                        if (arr[i] < min)
                                min = arr[i];
                }
        }
        if (min == 101)
        {
                cout << "-1"<<"\n";
        }
        else
        {
                cout << sum << "\n" << min<<"\n";
        }
}