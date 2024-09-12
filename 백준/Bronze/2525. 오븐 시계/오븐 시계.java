import java.util.*;
import java.time.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int m = sc.nextInt();
        int n = sc.nextInt();
        LocalDateTime t = LocalDateTime.of(2000,1,1,h,m);
        t= t.plusMinutes(n);
        System.out.println(t.getHour()+ " "+ t.getMinute());   
    }
}