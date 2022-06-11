/*
   조건 : 남녀분리, 같은학년 한방 최대 k명
   문제 : 방의 최소 갯수 구하기
   입력 : 참가학생수 N (1~1000) , 방 최대 인원 k (1~1000),
         N개 줄에 성별 (0~1) , 학년 (1~6)
 */
#include<iostream>

using namespace std;

int school[6][2];

int main()
{
        cin.tie(0);
        ios :: sync_with_stdio(0);
        int student_num,room_max,sex,grade;
        cin >> student_num >> room_max;
        for (int i =0 ;i < student_num; i++)
        {
                cin >> sex >> grade;
                school[grade-1][sex]++;
        }
        int need_room = 0;
        for (int i =0; i < 6; i++)
        {
                if(school[i][0] !=0 && school[i][0] % room_max == 0)
                        need_room += (school[i][0] / room_max);
                else if (school[i][0] !=0)
                        need_room+= (school[i][0] /room_max) + 1;
                if(school[i][1] !=0 && school[i][1] % room_max == 0)
                        need_room += (school[i][1] / room_max);
                else if (school[i][1] !=0)
                        need_room+= (school[i][1] /room_max) + 1;
        }
        cout << need_room << "\n";
}