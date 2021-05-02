import java.util.*;
import java.util.regex.Pattern;
import java.io.*;

class Solution {
	
    public int solution(int[][] jobs) {
        int answer = 0;
        ArrayList<Data> list = new ArrayList<>();
        int len = jobs.length;
        
        for(int[] job : jobs) {
        	list.add(new Data(job[0],job[1]));
        }
        Collections.sort(list);
        
        int time=0,total=0;
        while(list.size()>0) {
        	for(int i=0; i<list.size(); i++) {
        		if(time>=list.get(i).start) {
        			time+=list.get(i).cost;
        			total+=time-list.get(i).start;
        			list.remove(i);
        			break;
        		}
        		
        		if(i==list.size()-1) 
        			time++;
        	}
        }
        return total/len;
    }
    
    static class Data implements Comparable<Data>{
    	int start,cost;
    	Data(int start, int cost){
    		this.start = start;
    		this.cost = cost;
    	}
    	
    	@Override
    	public int compareTo(Solution.Data o) {
    		if(this.cost==o.cost) {
    			return this.start-o.start;
    		}
    		return this.cost-o.cost;
    	}
    }
}

public class Main {
	public static void main(String[] args) throws IOException{
    	int[][] jobs = {{0,3},{1,9},{2,6}};
    	System.out.println(new Solution().solution(jobs));
    }
}