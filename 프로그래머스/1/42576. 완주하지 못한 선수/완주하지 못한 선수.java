import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> m = new HashMap<String, Integer>();
        for(String c :completion){
            var n = m.get(c);
            if (n == null)
                m.put(c,1);
            else
                m.put(c,n+1);
            
        }
        for(String p : participant){
            var n = m.get(p);
            if (n==null || n == 0)
                return p;
            else{
                m.replace(p,n -1);
            }
        }
        return "";
    }
}