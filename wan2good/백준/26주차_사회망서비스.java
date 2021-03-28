import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static ArrayList<Integer>[] tree;
	static int[][] dp;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		visited = new boolean[n+1];
		dp = new int[2][n+1];
		tree = new ArrayList[n+1];
		for(int i=1; i<=n; i++) {
			tree[i] = new ArrayList<>();
		}
		
		for(int i=0; i<n-1; i++) {
			int a,b;
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			tree[a].add(b);
			tree[b].add(a);
		}
		dfs(1);
		System.out.println(Math.min(dp[0][1], dp[1][1]));
	}
	//0 내가 얼리아님 1 내가 얼리
	private static void dfs(int cur) {
		visited[cur]=true;
		dp[0][cur]=0;
		dp[1][cur]=1;
		for(int next : tree[cur]) {
			if(!visited[next]) {
				dfs(next);
				dp[0][cur]+=dp[1][next];
				dp[1][cur]+=Math.min(dp[0][next], dp[1][next]);
			}
		}
	}
}