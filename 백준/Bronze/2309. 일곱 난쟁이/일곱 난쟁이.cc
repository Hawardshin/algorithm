#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int arr[9];
        int sum =0;;
        for (int i= 0; i < 9; i++)
        {
                cin >> arr[i];
                sum+=arr[i];
        }
        int ri ;
        int rj;
        sort(arr, arr+9);
        for (int i=0; i < 9; i++)
        {
                for (int j =i+1; j < 9; j++)
                {
                        if (sum - arr[i] - arr[j] == 100)
                        {
                                ri = i;
                                rj = j;
                        }
                }
        }
        for (int i= 0 ; i < 9; i++)
        {
                if (i != ri && i != rj)
                        cout << arr[i] <<"\n";

        }
}