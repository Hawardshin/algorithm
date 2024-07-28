//맞을 수 있는 벽의 위치 상하좌우 
//(x,0) (a,x) (m,x) (x,n)
//각 위치에서 거리가 최소인 벽의 위치를 찾고. 그 거리를 리턴.



class Solution {
    int calcDist(int x1,int y1,int x2,int y2){
        return (int)Math.pow(y1-y2,2) + (int)Math.pow(x1-x2,2);
    }
    
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int []answer = new int[balls.length];
        for(int i=0; i<balls.length; i++){
            int bx = balls[i][0];
            int by = balls[i][1];
            answer[i]=1000000000;
            if (!(startY == by && startX > bx))
                answer[i] = calcDist(startX,startY,-bx,by);
            if (!(startX == bx && startY > by))
                answer[i] = Math.min(calcDist(startX,startY,bx,-by),answer[i]);
            if (!(startX == bx && startY < by))
            answer[i] = Math.min(calcDist(startX,startY,bx,2*n-by),answer[i]);
            if (!(startY == by && startX < bx))
                answer[i] = Math.min(calcDist(startX,startY,2*m-bx,by),answer[i]);
        }
        return answer;
    }
}