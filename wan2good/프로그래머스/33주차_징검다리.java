import java.io.*;
import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        Arrays.sort(rocks);
        
        int left=0,right=distance;
        while(left<=right) {
        	int mid = (left+right)/2;
        	int remove=0;
        	int pre=0;
        	for(int i=0; i<rocks.length; i++) {
        		if(rocks[i]-pre<mid)
        			remove++;
        		else
        			pre = rocks[i];
        	}
        	
        	if(distance-pre < mid) 
        		remove++;
        	if(remove>n) {
        		right = mid-1;
        	}
        	else {
        		answer = Math.max(answer, mid);
        		left = mid+1;
        	}
        }
        return answer;
    }
}

class Main {
	public static void main(String[] args) throws IOException{
		int distance = 25;
		int[] rocks = {2,14,11,21,17};
		int n = 2;
		System.out.println(new Solution().solution(distance,rocks,n));
	}
}