//공 별로 방문 여부 저장
//두개의 공 중 하나라도 방문한 적이 없는 경우 이동해서 방문 처리
//둘 다 방문 했거나, 둘 다 떨어지는 경우 이동 불가
//그렇게 bfs를 시도
//큐가 비어버리면 실패. 이동 중 하나만 떨어지는 경우 해당 횟수를 출력하고 종료.
// 방문 처리에 대한 고민 : 각 이동별로 방문의 가능성이 다를 것. 따라서 이동할 때마다 vis를 다 가지고 다닌다면?
//리미트 : 최대 이동 횟수 : 20*20 번 이동 가능 즉 400번 이동이 최대일 것
//단, 경우의 수가 400인 건 아님. 상하좌우 10이니까 4^10 이라고 생각. 방문 처리에 대한 고민을 할 필요가 없다. 10면이 되기 때문. 그냥 bfs하면 됨.

import java.util.*;

public class Main{
    static int [] dx = {1,0,-1,0};
    static int [] dy = {0,1,0,-1};
    static int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    static int n,m;
    public static void p(String s) {
        System.out.println(s);
    }
    public static void p(int s) {
        System.out.println(s);
    }
    static class Node {
        int x1;int y1;int x2;int y2;int cnt;
        Node(int x1,int y1,int x2,int y2,int cnt){
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.cnt = cnt;
        }
    }
    public static boolean isOut(int x,int y){
        if (x < 0 || y < 0 || x >= m || y >= n)
            return true;
        return false;
    }
    public static void main(String args[]){
        char [][]table =  new char[21][21];
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine(); //개행문자 처리
        for(int i=0;i<n;i++){
            String tmp = sc.nextLine();
            for (int j=0;j<tmp.length();j++){
                if (tmp.charAt(j) == 'o'){
                    if (x1 == -1) {
                        x1 = j;
                        y1 = i;
                    } else {
                        x2 = j;
                        y2 = i;
                    }
                    table[i][j] = '.';
                }
                else 
                    table[i][j] = tmp.charAt(j);
            }
        }
        Queue<Node> Q = new LinkedList();
        Q.add(new Node(x1,y1,x2,y2,1));
        
        while (!Q.isEmpty()){
            Node n= Q.poll();
            for(int i=0;i<4;i++){
                int xx1 = n.x1 + dx[i];
                int xx2 = n.x2 + dx[i];
                int yy1 = n.y1 + dy[i];
                int yy2 = n.y2 + dy[i];
                
                if (!isOut(xx1,yy1) && table[yy1][xx1] == '#'){
                    yy1=n.y1;
                    xx1=n.x1;
                }
               
                if (!isOut(xx2,yy2) && table[yy2][xx2] == '#'){
                    yy2 = n.y2;
                    xx2 = n.x2;
                }
        
                if (isOut(xx1,yy1) && isOut(xx2,yy2))//둘 다 나간 경우
                    continue;
                if (isOut(xx1,yy1) != isOut(xx2,yy2)){
                    p(n.cnt);
                    return ;
                }
            
                if (n.cnt > 10){
                    p(-1);
                    return ;
                }
                if (table[yy1][xx1] == '.'){//이동 가능 위치일 때
                    if (table[yy2][xx2] == '.'){//두번째도 이동가능할 때
                        Q.add(new Node(xx1,yy1,xx2,yy2,n.cnt+1));
                    }
                    else {//두번째가 벽인 경우
                        Q.add(new Node(xx1,yy1,n.x2,n.y2,n.cnt+1));
                    }
                }else {//첫번째가 벽인 경우
                    Q.add(new Node(n.x1,n.y1,xx2,yy2,n.cnt+1));
                }
            }
        }
        p(-1);
    }
}