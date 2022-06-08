/*
   포켓몬 도감에서 포켓몬의 이름을 보면 포켓몬의 번호를 말하거나, 포켓몬의 번호를 보면 포켓몬의 이름을 말하는 연습
   입력 : 포켓몬의 개수 N ,맞춰야 하는 문제의 개수 M
          1 ~ N 포켓몬 이름, 문제 : M개 숫자는 문자로 문자는 숫자로!
   조건 :  1 <= N,M <= 100000,
   */

#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

typedef struct mmmm
{
        string name;
        int number;
}mons;

bool sort_fuc(mons a,mons b)
{
        return (a.name < b.name);
}

bool is_num(const string& i)
{
        if ('0'<= i[0] && i[0] <='9')
                return (true);
        return (false);
}

int s_to_num(string s)
{
        istringstream ss(s);
        int x;
        ss >> x;
        return (x);
}

void find_result(mons *monster,string target,int end)
{
        int start = 0;
        int mid;
        while (start <= end)
        {
                mid = (start + end) / 2;
                if (monster[mid].name == target)
                {
                        cout << monster[mid].number << "\n";
                        return;
                }
                else if (monster[mid].name > target)
                {
                        end = mid -1;
                }
                else
                        start = mid + 1;
        }
}


int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
        int mon_n,matter_n;
        cin >> mon_n >> matter_n;
        mons *monster = new mons [mon_n];
        mons *monster_name = new mons [mon_n];
        for (int i = 0; i < mon_n; i++)
        {
                cin >> monster[i].name;
                monster_name[i].name = monster[i].name;
                monster[i].number = i + 1;
                monster_name[i].number =i+1;
        }
        //cout << "\n-----------------------------------------------------------\n";
        sort(monster,monster + mon_n,sort_fuc);
        string input;
        for (int i =0 ;i < matter_n; i++)
        {
                cin >> input;
                if (is_num(input))
                        cout << monster_name[s_to_num(input) - 1].name<<"\n";
                else
                        find_result(monster,input,mon_n -1);
        }
}