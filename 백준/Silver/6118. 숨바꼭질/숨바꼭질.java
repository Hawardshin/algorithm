import java.util.*;

//1에서 N까지 이동
//1부터 연결된 길을 모두 bfs.
//bfs가 끝나면, 가장 긴 거리가 정답.

public class Main{
    static List<Integer>[] way = (List<Integer>[]) new ArrayList[20001];
    static boolean [] vis = new boolean[20001];
    static int n,m;

    static class Pair {
        int point,dist;
        Pair(int point,int dist){
            this.point = point;
            this.dist = dist;
        }
    }

    static void input(){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt();
        for(int i=0; i < way.length;i++){
            way[i] = new ArrayList<>();
        }
        for(int i = 0; i < m;i++){
            int a,b;
            a=sc.nextInt(); b= sc.nextInt();
            way[a].add(b);
            way[b].add(a);
        }
    }


    static void bfs(){
        Queue Q = new LinkedList<Pair>();

        Q.offer(new Pair(1,1));
        vis[1] = true;
        int max_depth = 0;
        int max_now =0;
        int max_cnt = 0;

        while (!Q.isEmpty()){
            Pair p = (Pair)Q.poll();
            int now = p.point;
            boolean flag=false;
            for(int i : way[now]){
                if (vis[i] == true)
                    continue;
                vis[i] = true;
                Q.add(new Pair(i,p.dist+1));
                if (max_depth < p.dist){ //정답을 위해 추가한 코드 처음 해당 깊이에 온 경우
                    max_depth = p.dist;
                    max_now = i;
                    max_cnt =1;
                }else{
                    max_now = max_now > i ? i: max_now;
                    max_cnt++;
                }
            }
        }
        System.out.println(max_now + " " + max_depth + " " + max_cnt);
    }
    public static void main(String[] args){
        input();
        bfs();
    }
}
