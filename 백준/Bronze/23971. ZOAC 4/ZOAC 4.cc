#include<iostream>
#include <algorithm>

using namespace std;
//w개씩 h행
//가로 W, 세로 H
//가로 한변 : M, 세로 한변 : N

//세로 X + N*(X-1) <= H
//가로 Y + M*(Y-1) <= W
//답 :  X*Y
//(N+1)X - N < H -> X <= (N+H)/(N+1)
//(M+1)Y - M < W -> Y <= (W+M)/(M+1)
int main(){
    int w,h,n,m;
    cin >> w>>h>>n>>m;
    
    int x = (m+h)/(m+1);
    int y =(w+n)/(n+1);
    cout << x*y;
}