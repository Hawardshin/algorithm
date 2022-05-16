#include<iostream>

using namespace std;

int check(char *arr1 ,char *arr2)
{
        int i =0;
        int k = 1;
        while (*arr1)
        {

                i = 0;
                k = 1;
                while (arr1[k*i]&&arr2[i] && arr2[i] == arr1[k*i])
                {
                        i++;
                        if(arr2[i] =='\0')
                                return 1;
                        if (arr1[k*i]&&arr2[i]&& arr2[i] != arr1[k*i])
                        {
                                i = 0;
                                k++;
                        }

                }
                arr1++;
        }
        return (0);
}


int main()
{
        int input;
        char sign[26];
        char str[101][101];
        cin >> input;
        cin >> sign;
        int count = 0;
        for (int i= 0; i <input; i++)
        {
                cin>>str[i];
                if (check(str[i],sign))
                        count++;
        }
        cout<<count <<endl;

}