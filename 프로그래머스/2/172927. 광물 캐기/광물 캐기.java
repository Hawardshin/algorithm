//연속 5개를 부신다 -> 0,4,9,14,19,24,29,34
//빈칸 10개
//3*3*3*3*3*3*3*3*3*3
//3^10

class Solution {
    static int min_cost=1000000;
    int getCost(int pick, String mineral){
        switch(pick){
            case 0 :
                return 1;
            case 1 :
                if (mineral.equals("diamond"))
                    return 5;
                else 
                    return  1;
            case 2 :
                if (mineral.equals("diamond"))
                    return 25;
                else if (mineral.equals("iron"))
                    return 5;
                else
                    return 1;
        }
        return 100100101;
    }
    
    void dfs(int []picks,int cost,int idx,String[] minerals){
        if ((picks[0] ==0 && picks[1] ==0 && picks[2] == 0) 
            || idx >= minerals.length){
            min_cost = (min_cost > cost) ? cost : min_cost;
        }
        if (picks[0] >0){
            picks[0]--;
            int dep_cost =0;
            for(int i=idx; (i<idx+5 &&i<minerals.length); i++){
                dep_cost+=getCost(0,minerals[i]); 
            }
            dfs(picks,cost + dep_cost,idx+5, minerals);
            picks[0]++;
        }
        if (picks[1]>0){
            picks[1]--;
            int dep_cost =0;
            for(int i=idx; (i<idx+5 &&i<minerals.length); i++){
                dep_cost+=getCost(1,minerals[i]);   
            }
            dfs(picks,cost + dep_cost,idx+5, minerals);
            picks[1]++;
        }
        
        if (picks[2]>0){
            picks[2]--;
            int dep_cost =0;
            for(int i=idx; (i<idx+5 &&i<minerals.length); i++){
                dep_cost+=getCost(2,minerals[i]);  
            }
            dfs(picks,cost + dep_cost,idx+5, minerals);
            picks[2]++;
        }
    }
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        dfs(picks,0,0,minerals);
        answer = min_cost;
        return answer;
    }
    
    
    
}