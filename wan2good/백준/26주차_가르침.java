import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
    static int k;
    static boolean[] visited;
    static String[] data;
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        data = new String[n];
        for(int i=0; i<n; i++) {
        	data[i] = br.readLine();
        }
        
        visited = new boolean[26];
        visited['a'-'a']=true;
        visited['n'-'a']=true;
        visited['t'-'a']=true;
        visited['i'-'a']=true;
        visited['c'-'a']=true;
        
        solve(0,0);
        System.out.println(answer);
    }
    
    private static void solve(int cur, int count) {
    	if(count==k-5) {
    		int tmp=0;
        	for(int i=0; i<n; i++) {
        		boolean flag=true;
        		for(int j=4; j<data[i].length()-4; j++) {
        			if(!visited[data[i].charAt(j)-'a']) {
        				flag=false;
        				break;
        			}
        		}
        		if(flag)
        			tmp++;
        	}
        	answer = Math.max(tmp, answer);
        }
    	
    	for(int i=cur; i<26; i++) {
    		if(!visited[i]) {
    			visited[i]=true;
    			solve(i,count+1);
    			visited[i]=false;
    		}
    	}
    }
}