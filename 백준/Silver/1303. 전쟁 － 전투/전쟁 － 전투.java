import java.util.*;
import java.io.*;
public class Main{
    public static int[] dx = {1,0,-1,0};
    public static int[] dy = {0,1,0,-1};
    

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        boolean [][] vis = new boolean[m][n];
        char [][]map = new char[m][];
        for(int i=0;i<m;i++){
            String s = sc.nextLine();
            map[i] = s.toCharArray();
        }
        PriorityQueue<Pair> PQ = new PriorityQueue<Pair>();
        int W_result = 0;
        int B_result = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (vis[i][j] == true)
                    continue;
                else{
                    vis[i][j] = true;
                    PQ.add(new Pair(j,i));
                    int cnt = 0;
                    while (!PQ.isEmpty()){
                        cnt++;
                        Pair t = PQ.poll();
                        int tx = t.first;
                        int ty = t.second;
                        for(int k=0;k<4;k++){
                            int nx = tx+dx[k];
                            int ny = ty+dy[k];
                            if (nx <0 || ny < 0 || nx >= n || ny >= m)
                                continue;
                            if (vis[ny][nx])
                                continue;
                            if (map[ny][nx] != map[ty][tx])
                                continue;
                            vis[ny][nx] = true;
                            PQ.add(new Pair(nx,ny));
                        }
                    }
                    if (map[i][j] == 'W')
                        W_result += Math.pow(cnt,2);
                    else 
                        B_result += Math.pow(cnt,2);
                }
            }
        }
        System.out.println(W_result + " " + B_result);
    }
}
class Pair implements Comparable<Pair> {
        int first,second;
        Pair(int f,int s){
            this.first = f;
            this.second = s;
        }
        public int compareTo(Pair p){
            if (this.first < p.first)
                return -1;
            else if (this.first == p.first && this.second < p.second)
                return -1;
            return 1;
        }
}