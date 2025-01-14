#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while (true){
        int a[3];
        cin >>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if (!(a[0]||a[1]||a[2]))
            break;
        if (a[0] == a[1] && a[1] == a[2])
            cout<<"Equilateral\n";
        else if (a[0]+a[1] <= a[2])
            cout << "Invalid\n";
        else if (a[0] == a[1] ||a[1] == a[2])
            cout << "Isosceles\n";
        else 
            cout << "Scalene\n";
    }
}