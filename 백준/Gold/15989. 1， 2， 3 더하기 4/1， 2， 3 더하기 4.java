import java.util.*;
import java.io.*;
public class Main{
    public static void main(String args[])throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int []dp = new int [10001];
        int t = Integer.parseInt(br.readLine());
        // String [] input = br.readLine().split(" "); 
       
        for(int i=0;i<=10000;i++) dp[i] = 1;
        for(int i=2;i<=10000;i++) dp[i] += dp[i-2];
        for(int i=3;i<=10000;i++) dp[i] += dp[i-3];
        for(int i=0;i<t;i++){
            int n = Integer.parseInt(br.readLine());
            bw.write(dp[n]+"\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}

//1,2,3,5,6,8

//1의 갯수 + 나머지 갯수 
//1
//(1,1) (2)
//(1,1,1) (1,2) (3)
//(1,1,1,1) (1,1,2) (2,2) (1,3)
//(1,1,1,1,1)(1,1,1,2) (1,1,3) (1,2,2)