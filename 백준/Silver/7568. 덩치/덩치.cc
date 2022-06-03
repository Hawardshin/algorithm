#include<iostream>
#include<stdlib.h>
using namespace std;
class human
{
        private:
                int kg;
                int len;

        public :
                human(int kg, int len): kg(kg),len(len){}
                human() : kg(0), len(0) { }
                int is_he_big(human & he)//인자로 온 값이 더 크다면 리턴 0 본체가 더 크다면 리턴 1
                {
                        if (he.rlen() > len && he.rkg() > kg)
                                return (1);
                        return (0);
                }
                void insert(int ilen, int ikg)
                {
                        len = ilen;
                        kg = ikg;
                }
                int rlen(){ return (len);}
                int rkg(){ return (kg); }

};

int main()
{
        int people_num, tlen,tkg;
        cin >> people_num;
        human * hu =new human[people_num];
        for(int i = 0; i < people_num; i++)
        {
                cin >> tlen >> tkg;
                hu[i].insert(tlen,tkg);
        }
        int *rank = (int *)calloc(people_num , sizeof(int));
        for (int i = 0; i < people_num; i++)
        {
                for (int j =0; j < people_num; j++)
                {
                        if(hu[i].is_he_big(hu[j]))
                                rank[i]++;//자기보다 큰 사람 숫자를 적어놓는다.
                }
        }
        int *real_rank = (int *)calloc(people_num , sizeof(int));
        int count =1 ;
        for (int i = 0; i < people_num; i++)
        {
                for (int j = 0; j < people_num; j++)
                {
                        if (rank[j] == i)
                        {
                                real_rank[j] = count;
                        }
                }
                count++;
        }
        for (int i = 0; i < people_num; i++)
                cout << real_rank[i] << " ";
        delete []hu;
        free(rank);
        free(real_rank);
}