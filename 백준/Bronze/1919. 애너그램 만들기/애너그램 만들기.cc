/*
   두 영어 단어 철자의 순서를 바꿔서 같아질 수 있다면 두 단어를 애너그램관계에 있다고 한다.
   두 단어를 받아서 에너그램 관계에 있게 만들려면 얼마나 제거를 해야하는가? 최소 숫자를 출력하자.
 */

#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int alpha1[26],alpha2[26];
int main()
{
        cin.tie(0);
        ios :: sync_with_stdio(0);
        string a,b;
        int count =0;
        cin >> a >>b;
        int alen = a.length();
        int blen= b.length();
        for (int i=0; i < alen; i++)
                alpha1[a[i] -97]++;
        for (int i=0; i < blen; i++)
                alpha2[b[i] -97]++;
        for (int i =0;  i < 26; i++)
        {
                        count += abs(alpha1[i]- alpha2[i]);
        }
        cout << count << "\n";
}