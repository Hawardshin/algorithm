#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int input_num;
        int arr[1000001];
        cin>>input_num;
        for (int i = 0; i < input_num; i++)
                cin >> arr[i];
        sort(arr,arr+input_num);
        for (int i = 0; i< input_num; i++)
                cout << arr[i]<<"\n";
}