import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        Set<String>inputs1 = new HashSet<>();
        for(int i=0;i<n;i++){
            inputs1.add(sc.next());
        }
        List<String> inputs = new ArrayList<>(inputs1);
        inputs.sort((o1,o2)->{
            if (o1.length() == o2.length()){
                return o1.compareTo(o2);
            }else {
                return  o1.length() - o2.length();
            }
        });
        for(String s : inputs){
            bw.write(s);
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }
}