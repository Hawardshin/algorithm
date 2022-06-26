#include<iostream>
#include<list>
using namespace std;

int main()
{
        int n,k;
        list<int> yo;
        list<int> :: iterator it;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
                yo.push_back(i);
        }
        it = yo.begin();
        cout << '<';
        while(!yo.empty())
        {
                for (int i = 1 ; i < k; i++)
                {
                        it++;
                        if (it ==yo.end())
                                it = yo.begin();
                }
                cout << *it;
                it = yo.erase(it);
                if (!yo.empty())
                        cout << ", ";
                if (it == yo.end())
                        it = yo.begin();
        }
        cout << '>';
}