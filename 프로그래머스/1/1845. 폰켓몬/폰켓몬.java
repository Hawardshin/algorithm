import java.util.*;
class Solution {
    public int solution(int[] nums) {
        Set<Integer> s = new HashSet<Integer>();
        for(Integer n : nums){
            s.add(n);
        }
        if (s.size() < nums.length/2){
            return s.size();
        }else {
            return nums.length/2;
        }
    }
}