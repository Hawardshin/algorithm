import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        Map <String,Integer> map = new HashMap<String,Integer>();
        for(String[] c : clothes){
            map.put(c[1],map.getOrDefault(c[1],0)+1);
        }
        for(String s :map.keySet()){
            if (answer == 0)
                answer+= map.get(s) +1;
            else
                answer *= (map.get(s)+1);
        }
        answer -= 1;
        return answer;
    }
}