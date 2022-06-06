#include<iostream>
/*

 0<t<30<t<60 <t <90 < t <
1.  10  20 30
2.  15  15 30
 */
using namespace std;
int main()
{
        int input;
        int Y =0;
        int M=0;
        int num;
        cin >> num;
        for (int i=0;i < num; i++)
        {
                cin >> input;
                Y += ((input/30) + 1) * 10;
                M += ((input/60) + 1) *15;
        }
        if (Y == M)
        {
                cout << "Y "<<"M " <<Y;
        }
        else if (Y> M)
                cout << "M " << M;
        else
                cout << "Y " << Y;
        return (0);
}