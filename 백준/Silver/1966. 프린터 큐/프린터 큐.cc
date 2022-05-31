#include<iostream>
#include<queue>
/*첫 줄에 테스트케이스의 수가 주어진다. 각 테스트케이스는 두 줄로 이루어져 있다.

테스트케이스의 첫 번째 줄에는 문서의 개수 N(1 ≤ N ≤ 100)과, 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지를 나타내는 정수 M(0 ≤ M < N)이 주어진다. 이때 맨 왼쪽은 0번째라고 하자. 두 번째 줄에는 N개 문서의 중요도가 차례대로 주어진다. 중요도는 1 이상 9 이하의 정수이고, 중요도가 같은 문서가 여러 개 있을 수도 있다.*/
using namespace std;

bool check_it(queue<int> mqueue)
{
        int r = mqueue.front();
        int k;
        mqueue.pop();
        while (!mqueue.empty())
        {
                if (r < mqueue.front())
                        return false;
                mqueue.pop();
        }
        return (true);

}

void find_result(queue<int>& mqueue, int dnum,int dnow)
{
        int count = 1;

        while (!mqueue.empty())
        {
                if (check_it(mqueue))
                {

                        if (dnow == 0)
                        {
                                cout << count<< "\n";
                                return ;
                        }
                        //cout << mqueue.front() << "::::pop\n";
                        mqueue.pop();
                        count++;
                        dnow --;
                        dnum--;
                        if (dnow == -1)
                                dnow = dnum -1;
                }
                else
                {
                        dnow--;
                        mqueue.push(mqueue.front());
                        mqueue.pop();
                        if (dnow == -1)
                                dnow = dnum -1;
                }
        }



}

int main()
{
        int all_num;
        int dnum, dnow,dimportant;
        queue <int> mqueue;
        cin >> all_num;
        for (int i = 0; i < all_num; i++)
        {
                cin >> dnum >> dnow;
                for (int j = 0; j < dnum; j++)
                {
                        cin >> dimportant;
                        mqueue.push(dimportant);
                }
                find_result(mqueue,dnum,dnow);
                while (!mqueue.empty())
                        mqueue.pop();
        }
}