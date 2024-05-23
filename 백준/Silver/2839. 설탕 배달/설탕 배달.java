import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
       int n = Integer.parseInt(br.readLine());
       int small = 0;
       int big = n/5;
        while(big>=0)
        {
            if ((n-big*5) % 3 == 0 ){
                //정답
                int ret = big+ (n-big*5)/3;
                System.out.println(ret);
                return ;
            }
            big--;
       }
        System.out.println(-1);
    }
}
//3,6,9,12
//5,10