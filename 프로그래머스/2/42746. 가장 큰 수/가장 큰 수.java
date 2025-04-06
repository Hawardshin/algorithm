import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        Integer []nums = Arrays.stream(numbers).boxed().toArray(Integer[]::new);
        String answer = "";
        Arrays.sort(nums, (i1,i2) -> {
            String s1 = String.valueOf(i1);
            String s2 = String.valueOf(i2);
            return (s2+s1).compareTo(s1+s2);
            });
        if (nums[0] == 0) return "0";
        StringBuilder sb = new StringBuilder();
        for(int a : nums){
            sb.append(a);
        }
        return sb.toString();
    }
}