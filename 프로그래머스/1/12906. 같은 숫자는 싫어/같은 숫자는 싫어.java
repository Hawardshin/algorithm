import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> ar= new ArrayList<>();
        int ar_idx =0;
        for(int a: arr){
            if (ar.size() == 0||ar.get(ar_idx-1) != a){
                ar.add(a);
                ar_idx++;
            }
        }
        return ar.stream().mapToInt(Integer::intValue).toArray();
    }
}