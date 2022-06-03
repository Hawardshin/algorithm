#include<iostream>
#include<algorithm>
using namespace std;
typedef struct point
{
        int x;
        int y;
} mpoint;

//bool xcompare(mpoint a, mpoint b)
//{
//      return(a.x < b.x);
//}


bool ycompare(mpoint a, mpoint b)
{
        if (a.y < b.y)
                return true;
        else if (a.y == b.y)
        {
                if (a.x < b.x)
                        return (true);
        }
        return false;
}

int main()
{
        int point_num;
        cin >> point_num;
        mpoint * position = new mpoint [point_num];
        for (int i = 0; i < point_num; i++)
        {
                cin >> position[i].x >> position[i].y;
        }
//      sort(position, position + point_num, xcompare);
//      for (int i = 0; i < point_num; i++)
//              cout<< position[i].x<<"??? " << position[i].y << "\n";
        sort(position, position+ point_num, ycompare);
        for (int i = 0; i < point_num; i++)
                cout<< position[i].x<<" " << position[i].y << "\n";
}