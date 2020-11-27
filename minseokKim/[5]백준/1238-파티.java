import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args)throws Exception
	{
		int INF = Integer.MAX_VALUE/2;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		int[][] map = new int[n+1][n+1];
		for(int i = 0; i < m; i++)
		{	
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int len = Integer.parseInt(st.nextToken());
			map[start][end] = len;
//			map[end][start] = len;
		}
		int[] go = new int[n+1];
		int[] away = new int[n+1];
	for(int start = 1; start<= n; start++)
	{
		LinkedList<Integer> list = new LinkedList();
		list.add(start);
		boolean[] visited = new boolean[n+1];
		int[] dijk_a = new int[n+1];
		Arrays.fill(dijk_a, INF);
		dijk_a[start] = 0;
		int next = INF;
		int next_idx = start;
		
		for(int c = 1; c <= n; c++)
		{
		int cur = 0;
		cur = list.poll();
		if(visited[cur])
			continue;
		for(int i = 1; i <= n; i++)
		{
			if(map[cur][i] == 0)
				continue;
			else
			{
				dijk_a[i] = Math.min(dijk_a[i],dijk_a[cur]+map[cur][i]);					
			}
		}
			

		int max = INF;
		int before_idx = next_idx;
		visited[before_idx] = true;
		for(int i = 1; i <= n; i++)
		{
			if(visited[i])
				continue;
			if(max > dijk_a[i])
			{
				max = dijk_a[i];
				next_idx = i;
			}
		}
		list.add(next_idx);
		}
		if(start == x)
		{
			for(int i = 1; i <= n; i++)
			{
				away[i] = dijk_a[i];
			}
		}
		else
		{
			go[start] = dijk_a[x];
		}
	}

	int answer = 0;
	for(int i = 1; i<=n; i++)
	{
		if(go[i]+away[i] < INF)
		answer = Math.max(go[i]+away[i], answer);
	}
		System.out.println(answer);
	}
}
