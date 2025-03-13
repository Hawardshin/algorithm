#include <string>
#include <vector>

using namespace std;



vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i < arr1.size();i++){
        int l = arr1[i] | arr2[i];
        string line="";
        int j=0;
        while (j < arr1.size()){
            if (l %2 == 0)
                line = " "+ line;
            else 
                line = "#" + line;
            l /= 2;
            j++;
        }
        answer.push_back(line);
    }
    return answer;
}