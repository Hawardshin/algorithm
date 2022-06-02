#include<iostream>
#include<algorithm>
using namespace std;

int check(long long mid , int*tree,long long  tree_num,long long tree_length)
{
        int count =0;
        int check = 0;
        for (int i = tree_num -1; i >=0; i--)
        {
                if (tree[i] - mid < 0)
                        break;
                count += (tree[i] - mid);
                if (count >= tree_length)
                {
                        check = 1;
                        break;
                }
        }
        if (check != 1)
                return (-1);
        mid = mid -1;
        count =0;
        for (int i = tree_num-1; i >= 0 ; i --)
        {
                if (tree[i] - mid < 0)
                {
                        break;
                }
                count +=(tree[i] -mid);
                if(count >tree_length)
                {
                        return (0);
                }
        }
        return (1);
}
int main()
{
        int tree_num,tree_length;
        cin >> tree_num >> tree_length;
        int *tree = new int[tree_num];
        for (int i =0; i < tree_num;i++)
        {
                cin >> tree[i];
        }
        sort(tree,tree+tree_num);
        long long start = 0;
        long long end = 1000000000;
        long long mid;
        int tmp = 0;
        while (start <= end)
        {
                mid = (start +end) / 2;
                if (check(mid,tree,tree_num,tree_length)== 1)
                {
                        cout << mid;
                        return (0);
                }
                else if (check(mid,tree,tree_num,tree_length) == -1)
                {
                        tmp = 1;
                //      cout <<"이거보다는 덜 자를수 있어::"<< mid<<"\n";
                        end = mid - 1;
                }
                else
                {
                        tmp =0;
                //      cout << "이거보다는 더 잘라야돼." << mid <<"\n";
//                      if (mid == 0)
//                      {
//                              cout <<"0" << "\n";
//                              return (0);
//                      }

                        start = mid + 1;
                }
        }
        if (tmp == 1)
                mid = mid -1;
        cout << mid <<"\n";

}
