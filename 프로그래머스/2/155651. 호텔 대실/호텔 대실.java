//끝나는 시간 순으로 정렬.
//끝나는 시간이 뒷쪽부터 채우기
//["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]
//	[18:20, 21:20]
//	[14:10, 19:20]
//	[16:40, 18:20]
//	[15:00, 17:00]
//	[14:20, 15:20]
// 1  : 1810 ->1450
// 2 : 1400 
// 3 : 1630 -> 1410
//못 채우면 갯수 늘리는 방향.
import java.util.*;
class Solution {
    
  
    public int solution(String[][] book_time) {
        int answer = 0;
        Arrays.sort(book_time, new Comparator<String[]>(){ // 뒷 숫자로 오름차순 정렬.
            @Override
            public int compare(String[] time1, String[] time2){
                return convertToMinutes(time2[1])- convertToMinutes(time1[1]);
            }
        });
        List<Integer> arr = new ArrayList<Integer>(); //다시 시작할 수 있는 시간 적는 배열.
                                            // 이 길이가 정답
        // for(String[] times : book_time){
        //     System.out.println(Arrays.toString(times));
        // }
        for(int i=0;i<book_time.length;i++){
            boolean flag = false;
            for(int j=0;j < arr.size();j++){
                if (convertToMinutes(book_time[i][1]) <= arr.get(j)) {
                    arr.set(j, convertToMinutes(book_time[i][0]) - 10);
                    flag = true;
                    break;
                }
            }
            if (flag == false){
                arr.add(convertToMinutes(book_time[i][0]) - 10);
            }
        }
        answer = arr.size();
        return answer;
    }
    
    private int convertToMinutes(String time) {
            String[] parts = time.split(":");
            int hours = Integer.parseInt(parts[0]);
            int minutes = Integer.parseInt(parts[1]);
            return hours * 60 + minutes;
    }
}