import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] arr = new int[1001];
        int [] cnt = new int[1001];
        arr[0] = 0;
        cnt[0] = 0;
        int max_n = 1;
        for(int i=1;i <= n;i++){
            int a = sc.nextInt();
            arr[i] = a;
            cnt[i] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if (arr[i] < arr[j]){
                    if (cnt[j] < cnt[i] + 1){
                        cnt[j] = cnt[i] + 1;
                        if (cnt[j] > max_n)
                            max_n = cnt[j];
                    }
                }
            }
        }
        if (max_n < cnt[n])
            max_n = cnt[n];
        System.out.println(max_n);
    }
}