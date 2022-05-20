#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        int arr[26] = {0};
        char input[101];
        cin >> input;
        for (int i=0; i < strlen(input); i++)
        {
                //cout << input[i];
                arr[(int)input[i] - 97]++;
        }
        for (int i = 0 ; i < 26; i++)
                cout << arr[i] << " ";
}