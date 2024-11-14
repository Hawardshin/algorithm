#include <string>
#include <vector>

using namespace std;
//prev 

int convertTimeToSecond(string time){
    string m = time.substr(0,time.find(':'));
    string s = time.substr(time.find(':')+1,time.length());
    int im = atoi(m.c_str());
    int is = atoi(s.c_str());
    return (im *60) + is;
}

bool isOpening(int pos,int op_start, int op_end){
    if (op_start<=pos && pos<= op_end){
        return true;
    }
    return false;
}

string convertSecondToMin(int sec){
    int m = sec / 60;
    int s = sec % 60;
    string ret = "";
    if (m < 10)
        ret = "0";
    if (s > 10)
        return ret+to_string(m)+":"+to_string(s);
    else if (s < 10)
        return ret + to_string(m) + ":0"+ to_string(s);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int i_v_len = convertTimeToSecond(video_len);
    int i_pos = convertTimeToSecond(pos);
    int i_op_start = convertTimeToSecond(op_start);
    int i_op_end = convertTimeToSecond(op_end);
    
    if (isOpening(i_pos,i_op_start, i_op_end)){
        i_pos = i_op_end;
    }
    for(string cmd: commands){
        if (cmd == "prev"){
            i_pos -= 10;
            if (i_pos < 0) i_pos = 0;
        }else if (cmd == "next"){
            i_pos += 10;
            if (i_pos > i_v_len) i_pos = i_v_len;
        }
        if (isOpening(i_pos,i_op_start, i_op_end)){
            i_pos = i_op_end;
        }
    }
 
    return convertSecondToMin(i_pos);
}