#include<iostream>
#include<algorithm>
using namespace std;

int check_max(char (*arr)[51],int n)
{
        int count = 0;
        int high = 0;
        for (int i =0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        count = 0;
                        for (int x = j; x < n ; x++)
                        {
                                if (arr[i][x] == arr[i][j])
                                        count ++;
                                else
                                        break;
                        }
                        if (high < count)
                                high = count;
                        count = 0;
                        for (int y = i ; y < n; y++)
                        {
                                if (arr[y][j] == arr[i][j])
                                        count++;
                                else
                                        break;
                        }
                        if (high < count)
                                high = count;
                }
        }
        return (high);
}

int main()
{
        int N;
        char arr[51][51];
        int max = 0;
        int tmp;
        cin >> N;
        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        cin >> arr[i][j];
        for (int i =0; i < N; i ++)
                for (int j = 0; j < N ;j++)
                {
                        // up
                        tmp = 0;
                        if (i !=0 && arr[i][j]!=arr[i-1][j])
                        {
                                swap(arr[i][j] , arr[i - 1][j]);
                                tmp = check_max(arr,N);
                                if (tmp > max)
                                        max = tmp;
                                swap(arr[i][j] , arr[i - 1][j]);
                        }
                        tmp = 0;
                        //down
                        if (i < N-1&& arr[i][j] != arr[i+1][j])
                        {
                                swap(arr[i][j] , arr[i + 1][j]);
                                tmp = check_max(arr,N);
                                if (tmp > max)
                                        max = tmp;
                                swap(arr[i][j] , arr[i + 1][j]);

                        }
                        //left
                        tmp = 0;
                        if (j > 0 && arr[i][j] != arr[i][j-1])
                        {
                                swap(arr[i][j] , arr[i][j-1]);
                                tmp = check_max(arr,N);
                                if (tmp > max)
                                        max = tmp;
                                swap(arr[i][j] , arr[i][j-1]);
                        }
                        //right
                        tmp = 0;
                        if (j < N -1 && arr[i][j] != arr[i][j+1])
                        {
                                swap(arr[i][j] , arr[i][j+1]);
                                tmp = check_max(arr,N);
                                if (tmp > max)
                                        max = tmp;
                                swap(arr[i][j] , arr[i][j+1]);
                        }
                }
                cout<<max<<"\n";
}