class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int[] bigAr = new int[sizes.length];
        int[] minAr = new int[sizes.length];
        int col = 0;
        int row = 0;
        for(int i=0;i<sizes.length;i++){
            bigAr[i] = sizes[i][0] >= sizes[i][1]? sizes[i][0] :sizes[i][1];
            if (row < bigAr[i])
                row = bigAr[i];
            minAr[i] = sizes[i][0] < sizes[i][1] ? sizes[i][0] :sizes[i][1];
            if (col < minAr[i])
                col = minAr[i];
        }
        return row * col;
    }
}