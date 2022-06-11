/*
a : 1~ 1000000
x = ai + aj 쌍의 수를 구하는 프로그램
input :
        1. 수열의 크기
        2. 수열의 숫자 쭉
        3. x를 준다.
출력 : 만족하는 쌍 갯수*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        ios :: sync_with_stdio;
        cin.tie(0);
        int arr_size;
        cin >> arr_size;
//      vector <int> arr(arr_size);
        int *arr = new int [arr_size];
        //cout << arr.capacity();
        //cout << arr.size();
        for (int i=0 ;i < arr_size; i++)
        {
                cin >> arr[i];
        }
        int x;
        cin >> x;
        sort (arr, arr + arr_size);
        int cnt = 0;
        int start = 0;
        for (int i = 0; i < arr_size; i++)
        {
                if (arr[i] + arr[arr_size -1] <= x)
                        start = i;
                else
                        break;

        }
        for (int i =start; i + 1 < arr_size; i++)
        {
                if (arr[i] + arr[i+ 1] > x)
                        break;
                for (int j = i +1; j < arr_size; j++)
                {
                        if (arr[i] + arr[j] == x)
                        {
                                cnt++;
                                break;
                        }
                        else if (arr[i] + arr[j] > x)
                                break;

                }

        }
        cout << cnt << "\n";
        //for (int i=0; i < arr_size; i++)
        //      cout << arr[i]<< "\n";

}