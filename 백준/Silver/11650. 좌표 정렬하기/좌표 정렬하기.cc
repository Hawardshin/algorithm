#include<iostream>
#include<algorithm>

using namespace std;
typedef struct p_map
{
        int x;
        int y;
}my_map;

int ft_cmp(my_map a1,my_map a2)
{
        if (a1.x > a2.x)
                return (0);
        else if (a1.x<a2.x)
                return (1);
        else if (a1.y>a2.y)
                return (0);
        else
                return (1);
}
int main()
{
        int point_num;
        cin >> point_num;
        my_map mmap[100000];
        for (int i =0; i < point_num; i++)
                cin >>mmap[i].x >> mmap[i].y;
        sort(mmap,mmap+point_num,ft_cmp);
        for (int i = 0; i < point_num; i++)
                cout<<mmap[i].x<<" " << mmap[i].y<<"\n";
}