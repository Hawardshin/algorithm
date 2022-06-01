#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[8002];
int main()
{
        int num;
        cin >>num;
        int *input =new int [num];
        for (int i = 0; i <num; i++)
        {
                cin >> input[i];
                if (input[i] < 0)
                        arr[abs(input[i]) + 4000]++;
                else
                        arr[input[i]]++;
        }
        int count = 1;
        int result;
        int max = -1;
        for (int i = 8000; i > 4000; i--)
        {
                if (max < arr[i])
                {

                        max = arr[i];
                        result = (i - 4000) * -1;
                        count = 1;
                //      cout << " i::: " << i << "\nresult :::: "<<  result<< "\n";//
                }
                else if (max == arr[i])
                {
                        if (count < 2)
                        {
                                result = (i - 4000) * -1;
                //              cout << " i::: " << i << "\nresult :::: "<<  result<< "\n";//
                                count++;
                        }
                }
        }
        for (int i = 0 ; i <= 4000; i++)
        {
                if (max < arr[i])
                {
                        max = arr[i];
                        result = i;
                        count =1;
                //      cout << " i::: " << i << "\nresult :::: "<<  result<< "\n";//
                }
                else if (max == arr[i])
                {
                        if (count < 2)
                        {
                //      cout << " i::: " << i << "\nresult :::: "<<  result<< "\n";//
                                result = i;
                                count++;
                        }
                }
        }
        sort (input, input +num);

        int sum = 0;
        for (int i = 0 ; i < num; i++)
                sum +=input[i];
        int first = round((double)sum / num);
        if (first == -0)
                first = 0;
        cout << first << "\n"<<input[num/2] << "\n" << result << "\n" << input[num -1]-input[0] <<"\n";
}