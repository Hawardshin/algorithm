#include<iostream>
#include<algorithm>

using namespace std;

int check_result(int *input, int mid,int n,int k)
{
        int count =0;
        for (int i = 0; i <k; i++)
        {
                count += input[i] / mid;
        }
        if (count < n)
                return -1;
        count =0;
        for (int i =0; i < k; i++)
        {
                count += input[i]/(mid +1);
        }
        if (count <n)
                return 1;
        else
                return 0;
}
int main()
{
        long long  k,n,mid;
        cin >> k >> n;
        int *input = new int[k];
        for (int i =0; i < k; i++)
        {
                cin >> input[i];
        }
        sort(input ,input +k);
        long long start = 1;
        long long end = input [k -1];
        while (start <= end)
        {
                mid = (start + end) / 2;
                if (check_result(input,mid,n,k) == 1)
                {
                        cout << mid <<"\n";
                        delete[] input;
                        return (0);
                }
                else if (check_result(input, mid, n, k) == -1)
                {
                        end = mid - 1;
                }
                else
                        start = mid + 1;
        }
        cout << mid << "\n";
        delete[] input;
}