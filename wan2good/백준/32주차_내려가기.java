import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static int[] max,min,next;
	static PriorityQueue<Integer> pq = new PriorityQueue<>();
	
    public static void main(String[] args) throws IOException{
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st;
    	
    	n = Integer.parseInt(br.readLine());
    	max = new int[3];
    	min = new int[3];
    	next = new int[3];
    	
    	st = new StringTokenizer(br.readLine());
    	for(int i=0; i<3; i++) {
    		int num = Integer.parseInt(st.nextToken()); 
    		max[i] = num;
    		min[i] = num;
    	}
    	
    	int maxpre0,maxpre1,maxpre2;
    	int minpre0,minpre1,minpre2;
    	for(int i=1; i<n; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=0; j<3; j++) {
    			next[j] = Integer.parseInt(st.nextToken());
    		}
    		maxpre0=max[0]; maxpre1=max[1];maxpre2=max[2];
    		minpre0=min[0]; minpre1=min[1];minpre2=min[2];
    		max[0] = Math.max(maxpre0, maxpre1) + next[0];
    		min[0] = Math.min(minpre0, minpre1) + next[0];
    		
    		max[1] = Math.max(Math.max(maxpre0, maxpre1), maxpre2) + next[1];
    		min[1] = Math.min(Math.min(minpre0, minpre1), minpre2) + next[1];
    		
    		max[2] = Math.max(maxpre1, maxpre2) + next[2];
    		min[2] = Math.min(minpre1, minpre2) + next[2];
    	}
    	
    	
    	System.out.println(Math.max(Math.max(max[0], max[1]), max[2]) + " " + 
    			Math.min(Math.min(min[0], min[1]), min[2]));
    	
    }
}