import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> ans = new ArrayList<Integer>();
        int i = 0;
        while(i<progresses.length){
            int left = 100 - progresses[i];
            int day = left / speeds[i];
            if (left% speeds[i] != 0)
                day++;
            progresses[i] = 100;
            for(int j=i+1;j<progresses.length;j++){
                progresses[j] = progresses[j] + day* speeds[j];
            }
            int cnt =0;
            for(int j = i;j < progresses.length;j++){
                if (progresses[j] >= 100)
                    cnt++;
                else
                     break;
            }
            ans.add(cnt);
            i = i+cnt;
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}