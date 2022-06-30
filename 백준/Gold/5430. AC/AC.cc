#include<iostream>
#include<string>
using namespace std;

int arr[500000];
int head, tail;

int stoi(int i, int k, string& s)
{
        int result = 0;
        for (int j= i; j <i+k; j++)
        {
                result = result *10 + (s[j] -'0');
        }
        //cout << result<< "result\n";
        return (result);
}

void stoar(string& s)
{
        int s_size = s.size();

        int ari = 100000;
        for (int i =0;  i< s_size; i++)
        {
                int k = 0;
                while (s[i+k] >='0' && s[i+k] <='9')
                {
                        k++;
                }
                if (k!=0)
                {
                        arr[ari] = stoi(i,k,s);
                        i+=k -1;
                        ari++;
                }
        }
}
int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);
        int tcase_n;
        int error= 0;
        string command,arr_in;
        int arr_n,c_size;
        cin >> tcase_n;
        for (int i= 0;  i<tcase_n; i++)
        {
                int error= 0;
                cin >> command >> arr_n>> arr_in;
                head = 100000;
                tail = 100000+arr_n;
                if (arr_n != 0)
                        stoar(arr_in);
                c_size = command.size();
                for (int j = 0; j < c_size; j++)
                {
                        if (command[j] == 'R')
                        {
                                int tmp;
                                if (head == tail)
                                {
                                }
                                else if (head < tail)
                                {
                                        tmp = head;
                                        head = tail - 1;
                                        tail = tmp  - 1;
                                }
                                else
                                {
                                        tmp = head;
                                        head = tail + 1;
                                        tail = tmp + 1;
                                }
                        }
                        else//command ==D
                        {
                                if (head == tail)
                                {
                                        error = 1;
                                        cout << "error\n";
                                        break;
                                }
                                else if (head > tail)
                                        head--;
                                else//head < tail
                                        head++;
                        }
                }
                if (error==1)
                {
                }
                else if (head < tail)
                {
                        cout << '[';
                        for (int j = head; j < tail; j++)
                        {
                                cout << arr[j];
                                if (j != tail-1)
                                        cout <<',';
                        }
                        cout << "]\n";
                }
                else
                {
                        cout << '[';
                        for (int j = head; j > tail; j--)
                        {
                                cout << arr[j];
                                if (j != tail + 1)
                                        cout <<',';
                        }
                        cout << "]\n";
                }
        }
}