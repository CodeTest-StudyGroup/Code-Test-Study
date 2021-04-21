import java.io.*;
import java.util.*;

public class Main {
	
	static int n,d,k,c;
	static int[] belt;
	static int[] visited;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		
		n = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		belt = new int[n];
		visited = new int[d+1];
		for(int i=0; i<n; i++) {
			belt[i] = Integer.parseInt(br.readLine());
		}
		
		int kind=0;
		for(int i=0; i<k; i++) {
			if(visited[belt[i]]==0)
				kind++;
			visited[belt[i]]++;
		}
		
		int total = kind;
		for(int i=1; i<n; i++) {
			visited[belt[i-1]]--;
			if(visited[belt[i-1]]==0)
				kind--;
			
			if(visited[belt[(i+k-1)%n]]==0)
				kind++;
			visited[belt[(i+k-1)%n]]++;
			if(total <= kind) {
				if(visited[c]==0)
					total = kind+1;
				else
					total = kind;
			}
		}
		
		System.out.println(total);
	}
}