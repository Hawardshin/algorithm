#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for (int a : arr) sum  += a;
    
    double answer = (double)sum / arr.size();
    return answer;
}