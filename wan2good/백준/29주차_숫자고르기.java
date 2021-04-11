import java.util.*;
import java.io.*;

public class Main
{	
	static int n;
	static int[] data;
	static boolean[] visited;
	static ArrayList<Integer> result = new ArrayList<>();
	
	public static void main(String args[]) throws IOException
    {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		
		data = new int[n+1];
		for(int i=1; i<=n; i++) {
			data[i] = Integer.parseInt(br.readLine());
		}
		
		visited = new boolean[n+1];
		for(int i=1; i<=n; i++) {
			solve(i,i);
		}
		
		for(int i=1; i<=n; i++) {
			if(visited[i])
				result.add(i);
		}
		
		Collections.sort(result);
		System.out.println(result.size());
		for(int num : result) {
			System.out.println(num);
		}
    }

	private static boolean solve(int start, int end) {
		if(data[start]==end) {
			visited[start]=true;
			return true;
		}
		else {
			if(!visited[start]) {
				visited[start]=true;
				if(solve(data[start],end)) {
					return true;
				}
				else {
					visited[start]=false;
					return false;
				}
			}
			else
				return false;
		}
	}
}