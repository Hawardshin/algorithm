import java.util.*;
// 0,1,2, 3,    4,    5,   6,   7,   8,9
// 1,1,1, 2,    2,    3,   4,   5,   7,9
// 0,1,2,(0+1),(1+2),(2+3),(3+4)(4+5)



public class Main{
   
    public static void main(String[] args){
        Long [] dp = new Long[101];
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        dp[0] = 1L;
        dp[1] = 1L;
        dp[2] = 1L;
        for(int i=3;i<101;i++){
            dp[i] = dp[i-3] + dp[i-2];
        }
        for(int i=0;i<t;i++){
            int x = sc.nextInt();
            System.out.println(dp[x-1]);
        }
    }
}