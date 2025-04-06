class Solution {
    int dfs(int dep,int now,int[] numbers,int target){
        if (dep == numbers.length){
            if (now == target)
                return 1;
            else
                return 0;
        }else{
            return dfs(dep+1,now+numbers[dep],numbers,target)+dfs(dep+1,now-numbers[dep],numbers,target);
        }
    }
    
    public int solution(int[] numbers, int target) {
        int answer = dfs(0,0,numbers,target);
        return answer;
    }
}