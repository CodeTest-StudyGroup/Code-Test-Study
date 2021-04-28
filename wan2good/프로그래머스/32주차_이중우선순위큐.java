import java.util.*;
import java.io.*;


class Solution {
	PriorityQueue<Integer> minh = new PriorityQueue<>();
	PriorityQueue<Integer> maxh = new PriorityQueue<>();
    public int[] solution(String[] operations) {
    	StringTokenizer st;
        int[] answer = {0,0};
        for(String operation : operations) {
        	st = new StringTokenizer(operation);
        	String order = st.nextToken();
        	int num = Integer.parseInt(st.nextToken());
        	
        	if(order.equals("I")) {
        		minh.offer(num);
        		maxh.offer(-num);
        		continue;
        	}
        	else {
        		if(num==1) {
        			if(maxh.size()==0) continue;
        			else {
        				minh.remove(-maxh.poll());
        				
        			}
        		}
        		else {
        			if(minh.size()==0) continue;
        			else {
        				maxh.remove(minh.poll());
        			}
        		}
        	}
        }
        if(minh.size()>0) {
        	return new int[] {-maxh.peek(),minh.peek()};
        }
        return answer; 
    }
}

public class Main {
    public static void main(String[] args){
    	String[] operations= {"I 16","D 1"};
        System.out.println(new Solution().solution(operations));
    }
}