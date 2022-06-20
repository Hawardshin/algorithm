/*
    문제 :strfry 함수는 입력된 문자열을 무작위로 재배열하여 새로운 문자열을 만듬.
        두번째 문자열에 대해 두번째 문자열이 1번째 문자열을 이용해 만들어질수 있는지 확인하는 문제
        입력 : 테스트케이스 숫자 N(1~1000)
        두개의 문자열이 한개의 공백으로 주어진다. 각가의 문자열의 길이는 최대 1000이다.
        출력 : 가능하면 Possible 불가능하면 Impossible
 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void check(string a, string b)
{
        int alpha1[26];
        int alpha2[26];
        fill(alpha1,alpha1+26,0);
        fill(alpha2,alpha2+26,0);
        int len1 = a.length();
        int len2 = b.length();

        if (len1 != len2)
        {
                //cout <<"1";
                cout << "Impossible\n";
                return ;
        }
        for (int i = 0; i < len1 ; i++)
        {
                int n = a[i] - 97;
                if (n < 0 || n > 25)
                {
                //      cout << "2";
                        cout << "Impossible\n";
                        return ;
                }
                alpha1[n]++;
        }
        for (int i = 0 ; i < len2; i++)
        {
                int n = b[i] - 97;
                if (n < 0 || n > 25)
                {
                //      cout << "3";
                        cout << "Impossible\n";
                        return;
                }
                alpha2[n]++;
        }
        for (int i = 0;  i < 26 ; i ++)
        {
                if (alpha1[i] != alpha2[i])
                {
                //      cout << "4";
                        cout << "Impossible\n";
                        return;
                }
        }
        cout << "Possible\n";
}

int main()
{
        cin.tie(0);
        ios :: sync_with_stdio(0);
        int test_n;
        cin >> test_n;
        string input,output;
        for (int i =0; i < test_n; i++)
        {
                cin >> input >> output;
                check(input,output);
        }

}