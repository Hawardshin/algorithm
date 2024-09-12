import java.util.*;
public class Main{
    static int []vis = new int[1001];
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int st = sc.nextInt();
        int div = sc.nextInt();
       
        // int now = (st*st) % div;
        int now = st;
        int ret = 0;
        while (vis[now] <= 2){
            vis[now]++;
            if (vis[now] == 2)
                ret++;
            now = (now * st ) %div;
        }
        System.out.println(ret);
    }
}