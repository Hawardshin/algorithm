#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;

bool visit[100001];

int result;
int main()
{

        ios :: sync_with_stdio(0);
        cin.tie(0);
        int me,bro;
        queue <pair<int,int> >Q;
        cin >> me >> bro;
        visit[me] = 1;
        Q.push(make_pair(me,0));
        while (1)
        {
                int tmp = Q.front().first;
                int ctmp = Q.front().second;
                if (tmp == bro)
                {
                        cout << Q.front().second;
                        return 0;
                }
                Q.pop();
                if (tmp + 1 > 100000 || visit[tmp + 1])
                        {}
                else
                {
                        Q.push(make_pair(tmp +1,ctmp +1));
                        visit[tmp +1] =1;
                }
                if (tmp - 1 < 0 || visit[tmp -1])
                        {}
                else
                {
                        Q.push(make_pair(tmp -1,ctmp +1));
                        visit[tmp - 1] =1;
                }
                if (2 * tmp > 100000||visit[2*tmp])
                        {}
                else
                {
                        Q.push(make_pair(tmp * 2, ctmp+1));
                        visit[tmp * 2] =1;
                }
        }
}