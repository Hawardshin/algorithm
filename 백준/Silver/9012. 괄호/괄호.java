import java.util.Stack;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    private static String solve(String s){
        Stack<Character> st = new Stack<>();

        for (int i=0; i < s.length();i++){
            if (s.charAt(i) == ')'){
                if (st.isEmpty())
                    return "NO";
                else 
                    st.pop();
            }
            else 
                st.push(s.charAt(i));
        }
        if (st.isEmpty() == true)
            return "YES";
        return "NO";
    }

    public static void main(String args[])throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i=0;i<n;i++){
            String line = bf.readLine();
            System.out.println(solve(line)); 
        }
     }
}