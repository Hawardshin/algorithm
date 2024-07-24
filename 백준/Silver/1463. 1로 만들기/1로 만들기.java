import java.util.*;

public class Main{
    static int[] num = new int[1000001];
    public static void main(String args[]){
        num[0]=0;       
        for(int i=2;i<=1000000;i++){
            num[i] = num[i-1] +1;
            if (i % 2==0)
                num[i] = num[i/2] + 1 <  num[i] ? num[i/2] + 1: num[i];
            if (i% 3 ==0)
                num[i] = num[i/3] + 1 < num[i] ? num[i/3] + 1 : num[i];
        }
        num[1] = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println(num[sc.nextInt()]);
    }
}
