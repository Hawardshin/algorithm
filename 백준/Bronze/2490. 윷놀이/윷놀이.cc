#include<iostream>

using namespace std;
int main()
{
        int input[4];
        int count =0;
        char result[5] = {'E','A','B','C','D'};
        for (int j = 0; j < 3; j++)
        {
                count =0;
                for (int i=0;i <4; i++)
                {
                        cin >> input[i];
                        if (input[i] == 0)
                                count++;
                }
                cout<< result[count]<<"\n";
        }
        return (0);
}