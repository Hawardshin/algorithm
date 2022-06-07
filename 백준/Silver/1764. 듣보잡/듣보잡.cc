/*
   문제 : 듣도 못한 명단과 보도 못한 명단이 주어질때 듣보잡을 구하라
   입력 : 듣도 못한 N명 보도 못한 사람 M명
   조건 : 중복 X 이름 20이하, N , M < 500000
   출력 : 사전순으로 정렬해서 문제 풀
 */
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
bool find_same(string *hear,int end ,string check)
{
        int start = 0;
        int mid;
        while (start <= end)
        {
                mid = (start +end) / 2 ;
                if (check == hear[mid])
                {
                        return (true);
                }
                else if (check > hear[mid])
                {
                        start = mid + 1;
                }
                else
                        end = mid - 1;
        }
        return (false);
}
int main()
{
        int hear,see;
        cin >> hear >> see;
        string *arr_hear = new string [hear];
        string *arr_see = new string [see];
        for (int i = 0; i < hear; i++)
        {
                cin >> arr_hear[i];
        }
        sort (arr_hear,arr_hear + hear);
        int j = 0;
        string check;
        for (int i = 0; i < see; i++)
        {
                cin >> check;
                if (find_same(arr_hear, hear -1 ,check))
                {
                        arr_see[j] = check;
                        j++;
                }
        }
        sort(arr_see, arr_see+j);
        cout << j << "\n";
        for (int i = 0; i < j ; i++)
                cout <<arr_see[i] << "\n";
        delete []arr_hear;
        delete []arr_see;
}