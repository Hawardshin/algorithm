import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        Map<String,Integer> map = new HashMap<String,Integer>();
        for(String s : phone_book){
            map.put(s,1);
        }
        for(int i=0;i<phone_book.length;i++){
            for(int j=0;j<phone_book[i].length();j++){
                if (map.containsKey(phone_book[i].substring(0,j)))
                    return false;
            }
        }
        return true;        
    }
}