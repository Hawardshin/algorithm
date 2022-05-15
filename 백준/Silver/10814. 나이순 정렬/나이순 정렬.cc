#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class baekjun
{
        private :
                string name;
                int age;
                int comin;

        public :
                void init(string name_,int age_,int i);
                int print_age() {return (age);}
                int print_comin() { return (comin);}
                string print_name(){return (name);}
};

void baekjun :: init(string name_, int age_,int i)
{
        name = name_;
        age = age_;
        comin = i;
}

int my_cmp(baekjun a, baekjun b)
{
        if (a.print_age() >b.print_age())
                return (0);
        else if (a.print_age() < b.print_age())
                return (1);
        else if (a.print_comin() > b.print_comin())
                return (0);
        else
                return (1);
}

int main()
{
        int input;
        string iname;
        int iage;
        baekjun bak[100000];
        cin >> input;
        for(int i = 0; i < input; i++)
        {
                cin >> iage >> iname;
                bak[i].init(iname, iage,i);
        }
        sort(bak, bak+input, my_cmp);
        for (int i = 0; i < input; i++)
        {
                cout << bak[i].print_age() <<" "<<bak[i].print_name() <<"\n";
        }
}