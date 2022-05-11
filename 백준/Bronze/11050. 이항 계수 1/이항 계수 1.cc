#include<iostream>

using namespace std;

int main()
{
        int a,b;
        int result = 1;
        scanf("%d%d",&a,&b);
        for(int i = 1; i <= a; i++)
                result *=i;
        int k=1;
        for(int i = 1; i <=b; i++)
                k*=i;
        for (int i =1; i<= a-b; i++)
                k*=i;
        cout <<result/k << endl;
}