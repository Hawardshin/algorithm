import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for(int i=0;i<a; i++){
            for(int j=0;j<a*2-1;j++){
                if (j < a - i - 1)
                    System.out.print(" ");
                else if (j <= a+ i -1)
                    System.out.print("*");
            }
            System.out.println("");
        }
        for(int i=1;i<a;i++){
            for (int j=0;j<a*2 -1;j++){
                if (j < i ) 
                    System.out.print(" ");
                else if (j <= 2*a - 2 - i)
                    System.out.print("*"); 
            }
                System.out.println("");
        }
    }
}