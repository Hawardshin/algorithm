import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        // int [] ans = new int[commands.length];
        // Vector<Integer> vec = new Vector<Integer>();
        List<Integer> ans = new ArrayList<Integer>();
        for(int i=0;i<commands.length;i++){
            int[] ar= Arrays.copyOfRange(array,commands[i][0]-1,commands[i][1]);
            Arrays.sort(ar);
//             for(int a : ar){
//                 System.out.print(a);
//             }
            
            // System.out.println( "|"+ (commands[i][2] -1) + "|");
            ans.add(ar[commands[i][2]-1]);
            // ans[i] = ar[commands[i][2] -1];
            // vec.add(ar[commands[i][2] -1]);
        }
        // int [] ans = vec.toArray(int[].class);
        // List<Integer> vec = new ArrayList<Integer>();
        return ans.stream().mapToInt(i->i).toArray();
        // return ans;
        
    }
}