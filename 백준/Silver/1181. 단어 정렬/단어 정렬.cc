#include<iostream>
#include<algorithm>
using namespace std;

int ft_strcmp(string str1, string str2)
{
        if (str1.length() == str2.length())
        {
                return (str1 < str2);
        }
        else
                return (str1.length() < str2.length());
}
string str[20000];
int main()
{
        int inputnum;
        cin >> inputnum;

        for (int i = 0; i < inputnum; i++)
        {
                cin >> str[i];
        }
        sort(str, str+inputnum , ft_strcmp);//1일때 정렬을 한다는 의미로 받아드리자. 참일때 0 거짓일떄 1
        for(int i = 0; i <inputnum;i++)
        {
                if (str[i-1] != str[i])
                        cout << str[i]<<endl;
        }
        return (0);

}