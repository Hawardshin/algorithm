//2배가 되거나 하나를 지우거나 a-1, 2*a
import java.util.*;
public class Main{
    static int ret =0;
    static boolean[][] vis = new boolean[1001][1001];//[clip][total]
    
   public static class Node {
        int clip;
        int total;
        int time;
        
        public Node(int clip, int total, int time) {
            this.clip = clip;
            this.total = total;
            this.time = time;
        }
    }
    
    static int bfs(int togo){
        Queue<Node> Q = new LinkedList();

        Q.add(new Node(0,1,0));
        vis[0][1] = true;
        while(!Q.isEmpty()){
            Node cur = Q.poll();
            
            if(cur.total == togo) {
              return cur.time;
            }
            // 1. 화면에 있는 이모티콘 클립보드에 저장
            Q.offer(new Node(cur.total, cur.total, cur.time + 1)); 

            // 2. 클립보드에 있는 이모티콘 붙여넣기. 
            if(cur.clip != 0 && cur.total + cur.clip <= togo && !vis[cur.clip][cur.total + cur.clip]) {
                Q.offer(new Node(cur.clip, cur.total + cur.clip, cur.time + 1));
                vis[cur.clip][cur.total + cur.clip] = true;
            }
            // 3. 화면에 있는 이모티콘 중 하나 삭제.
            if(cur.total >= 1 && !vis[cur.clip][cur.total - 1]) {
                Q.offer(new Node(cur.clip, cur.total - 1, cur.time + 1));
                vis[cur.clip][cur.total - 1] = true;
            }
        }
        return -1;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int togo = sc.nextInt();
    
        System.out.println(bfs(togo));
    }
}