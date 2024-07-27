import java.util.*;
import java.io.*;
public class Main{

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> stack = new Stack<>();

        String input = br.readLine();
        String word = br.readLine();

        for(int i=0;i<input.length();i++){
            stack.push(input.charAt(i));
            if (stack.size() >= word.length() && input.charAt(i) == word.charAt(word.length()-1)){
                boolean flag = false;
                for(int j=0;j<word.length();j++){
                    if (stack.get(stack.size() - word.length() + j) != word.charAt(j)) {//스택이 같다면
                        flag = true;
                        break;
                    }
                }
                if (flag == false){
                     for (int j = 0; j < word.length(); j++) stack.pop();
                }
            }
        }
        if (stack.isEmpty()){
             bw.write("FRULA");
        }else{
            StringBuilder answer = new StringBuilder();
        for(Character c : stack){
            answer.append(c);
        }
        bw.write(answer.toString());
        }
        
        bw.flush();		//결과 출력
        bw.close();
        br.close();

    }
}

//1212ab12abab12ab
//12ab