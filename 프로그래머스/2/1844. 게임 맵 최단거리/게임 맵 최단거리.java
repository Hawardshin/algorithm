import java.util.*;
class Solution {
    static final int[] dy = {1,0,-1,0};
    static final int[] dx = {0,-1,0,1};
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        Queue<int[]> Q = new LinkedList<>();
        boolean vis[][] = new boolean[n][m];
        Q.add(new int[]{0,0,1});
        vis[0][0] = true;
        while(!Q.isEmpty()){
            int[] q = Q.poll();
            int x=q[0];
            int y=q[1];
            int cnt = q[2];
            for(int i=0;i<4;i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[ny][nx] == true || maps[ny][nx] == 0) continue;
                vis[ny][nx] = true;
                if (ny == n-1 && nx == m-1)
                    return cnt+1;
                Q.add(new int[]{nx,ny,cnt+1});
            }
        }
        return -1;
    }
}