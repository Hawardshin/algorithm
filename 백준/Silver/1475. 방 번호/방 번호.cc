#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main()
{
        int num[10];
        string inum;
        fill(num,num+10,0);
        cin >> inum;
        //cout << inum;
        //cout << inum[1];
        for (int i = 0; '0' <= inum[i] && inum[i] <= '9'; i++)
        {
                num[inum[i] - '0']++;
                //cout << inum[i] - '0'<< "aaa\n";
        }
        int max = -1;
        int sn = num[6] + num[9];
        for (int i=0; i < 10; i ++)
        {
                if (i != 6 && i !=9 && (num[i] > max))
                {
                        max = num[i];
                //      cout << max<< "max \n";
                }
        }
        if (sn % 2 == 0)
                sn= sn/2;
        else
                sn = sn /2 + 1;
        if (sn > max)
                max = sn;
        cout << max << "\n";
}