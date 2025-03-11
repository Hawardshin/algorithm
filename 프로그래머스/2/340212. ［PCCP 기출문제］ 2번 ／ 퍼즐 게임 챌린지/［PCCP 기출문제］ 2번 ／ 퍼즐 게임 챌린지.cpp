#include <string>
#include <vector>

using namespace std;

// 레벨과 난이도를 넣으면 소요 시간을 계산
long long calcTime(int lv, int diff, int prev_time, int work_time){
    long long t = work_time;
    if (diff > lv)
        t += (diff - lv) * (prev_time + work_time);
    return t;
}

// 레벨을 넣으면 전체 소요시간을 반환
long long calcAll(int lv, vector<int> &diffs, vector<int>& times){
    long long sum = 0;
    for(int i=0; i < diffs.size(); i++){
        if (i == 0)
            sum += calcTime(lv,diffs[i],0,times[i]);
        else
            sum += calcTime(lv,diffs[i], times[i-1],times[i]);
    }
    return sum;
}

// 모든 배열 순회하면서 레벨 넣는 연산 (복잡도 100000 * 1000)
int binSearch(int min_lv, int max_lv, 
              vector<int> &diffs, vector<int>& times, long long limit){
    int mid_lv = (min_lv + max_lv) / 2;
    long long sum = calcAll(mid_lv, diffs, times);
    if (sum == limit)
        return mid_lv;
    if (max_lv - min_lv <= 1){
        if (calcAll(min_lv, diffs, times) <= limit)
            return min_lv;
        return max_lv; 
    }
    if (sum < limit)
        return binSearch(min_lv, mid_lv, diffs,times,limit);
    else
        return binSearch(mid_lv + 1,max_lv,diffs,times,limit);
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = binSearch(1,1000000,diffs,times,limit);
    return answer;
}