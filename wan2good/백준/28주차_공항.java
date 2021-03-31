import java.io.*;
import java.util.*;

public class Main {
	
	static int g,p;
	static int[] airPlane;
	static int[] parent;
	
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	g = Integer.parseInt(br.readLine());
    	p = Integer.parseInt(br.readLine());
    	
    	parent = new int[g+1];
    	for(int i=1; i<=g; i++)
    		parent[i] = i;
    	
    	int ans=0;
    	for(int i=0; i<p; i++) {
    		int gi = Integer.parseInt(br.readLine());
    		
    		int res = find(gi);
    		if(res!=0) {
    			ans++;
    			union(res,res-1);
    		}
    		else
    			break;
    	}
    	
    	System.out.println(ans);
	}
	
	private static int find(int x) {
		if(x!=parent[x])
			parent[x] = find(parent[x]);
		return parent[x];
	}
	
	private static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		
		if(x<y) parent[y]=x;
		else parent[x] = y;
	}
}