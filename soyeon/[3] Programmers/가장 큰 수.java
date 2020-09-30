import java.util.*;
class Solution {
    public String solution(int[] numbers) {
    	String str[]=new String[numbers.length];
    	for(int i=0;i<numbers.length;i++) {
    		str[i]=String.valueOf(numbers[i]);
    	}
    	//두개를 이어붙일 때 더 큰쪽으로 정렬되도록
    	Arrays.sort(str, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return (s2+s1).compareTo(s1+s2);
            }
        });
    	
    	//이부분 주의, 0으로만 구성되어있으면 0 return
    	if (str[0].equals("0")) return "0";
    	
        String answer = "";
        for(int i=0;i<numbers.length;i++) {
        	answer+=str[i];
        }
        return answer;
    }
}
