package 트리dp;
import java.io.*;
import java.util.*;

public class 사회망서비스 {

	static int n;
	static int[][] dp;
	static boolean visited[];
	static ArrayList<Integer>[] graph;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		graph = new ArrayList[n+1];
		for(int i=1; i<=n; i++)
			graph[i] = new ArrayList<>();
		for(int i=1; i<n; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph[a].add(b);
			graph[b].add(a);
		}
		dp = new int[n+1][2];
		visited = new boolean[n+1];
		
		
		visited[1] =true;
		dfs(1);
		
		System.out.print(Math.min(dp[1][0], dp[1][1]));

	}
	
	static void dfs(int a)
	{
		for(int i=0; i<graph[a].size(); i++)
		{
			if(visited[graph[a].get(i)]==false)
			{
				visited[graph[a].get(i)]=true;
				dfs(graph[a].get(i));
				dp[a][0]+=dp[graph[a].get(i)][1]; //내가 아닌경우는 내자식들이 다 맞는경우
				dp[a][1]+=Math.min(dp[graph[a].get(i)][0], dp[graph[a].get(i)][1]);	
						}
		}
		dp[a][1]+=1;
		
		
	}

}
