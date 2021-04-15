import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m,k;
	static int[] candy;
	static int[][] dp;
	static boolean[] visited;
	static ArrayList<Integer>[] friends;
	static ArrayList<Data> group = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		candy = new int[n+1];
		visited = new boolean[n+1];
		friends = new ArrayList[n+1];
		for(int i=1; i<=n; i++)
			friends[i] = new ArrayList<>();
		
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
			candy[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			friends[a].add(b);
			friends[b].add(a);
		}
		
		for(int i=1; i<=n; i++) {
			if(!visited[i])
				bfs(i);
		}
		
		dp = new int[group.size()+1][k+1];
		for(int i=1; i<=group.size(); i++) {
			Data cur = group.get(i-1);
			int cnt = cur.cnt;
			int candy = cur.candy;
			for(int j=1; j<=k; j++) {
				if(j>=cnt) {
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-cnt]+candy);
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		System.out.println(dp[group.size()][k-1]);
	}
	
	private static void bfs(int start) {
		visited[start]=true;
		Queue<Integer> q = new LinkedList<>();
		q.offer(start);
		
		int cnt=1;
		int candy_sum=candy[start];
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int next : friends[cur]) {
				if(!visited[next]) {
					visited[next]=true;
					q.offer(next);
					cnt++;
					candy_sum+=candy[next];
				}
			}
		}
		group.add(new Data(cnt,candy_sum));
	}
	
	static class Data{
		int cnt;
		int candy;
		Data(int cnt, int candy){
			this.cnt = cnt;
			this.candy = candy;
		}
	}
	
}