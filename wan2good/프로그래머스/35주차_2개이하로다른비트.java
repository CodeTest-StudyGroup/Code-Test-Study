import java.io.*;
import java.util.*;

class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        int idx=0;


        for(long number : numbers) {
            
            StringBuilder sb = new StringBuilder();
            long now = number;
            if(now==0) {
            	answer[idx++]=1;
            	continue;
            }
            int cnt=0;
            boolean flag=false;
            while(now>0) {
            	if(!flag){
            		if(now%2==0)
            		{
            			flag=true;
            			sb.append(1);
            			if(sb.length()>1)
            				sb.setCharAt(cnt-1, '0');
            		}
            		else
            			sb.append(1);
            	}
            	else {
            		sb.append(now%2);
            	}
            	now/=2;
            	cnt++;
            }
            
            long result=0;
            if(!flag) {
            	sb.setCharAt(sb.length()-1, '0');
            	sb.append(1);
            }
            
            String strResult = sb.toString();
            long k=1;
            for(int i=0; i<strResult.length(); i++) {
            	result+=(k*(strResult.charAt(i)-'0'));
            	k*=2;
            }
            answer[idx++]=result;
        }
        return answer;
    }
}

class Main {
	public static void main(String[] args) throws IOException{
		long[] numbers = {2,7};
		System.out.println(new Solution().solution(numbers));
	}
}