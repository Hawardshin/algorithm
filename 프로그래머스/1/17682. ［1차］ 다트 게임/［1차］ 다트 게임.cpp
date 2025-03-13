#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int ret[3] = {0};
    int ret_idx=0;
    for(int i=0;i<dartResult.length();i++){
        char c = dartResult[i];
        if ('0'<=c && c <= '9'){
            if (c == '1'&& i != dartResult.length() -1 && dartResult[i + 1] == '0'){
                ret[ret_idx] = 10;
                i++;
            }else{
                ret[ret_idx] = c - '0';
            }
        }else if (c == 'S' || c == 'D' || c == 'T'){
            if (c == 'D'){
                ret[ret_idx] = ret[ret_idx] * ret[ret_idx];
            }else if (c =='T'){
                ret[ret_idx] = ret[ret_idx] * ret[ret_idx] * ret[ret_idx];
            }
            ret_idx++;
        }else {//*,#
            if (c == '*'){
                if (ret_idx == 1){//1번째 경우에 * 이 나온경우
                    ret[ret_idx - 1] *= 2;
                }else {
                    ret[ret_idx-1] *=2;
                    ret[ret_idx-2] *=2;
                }
            }else if (c ==  '#'){
                ret[ret_idx -1] *= -1;
            }
        }
    }
    for(int i=0;i<3;i++){
        answer+= ret[i];
    }
    return answer;
}