import java.io.*;
import java.util.*;

public class Main {
	static int[][] map;
	static int[][] dp;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		dp = new int[n][m];
		for(int i = 0; i < n; i++)
		{
			st= new StringTokenizer(br.readLine());
			for(int j = 0; j < m ;j++)
			{
				map[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = -1;
			}
		}
		int answer = 0;
		answer = dfs(0,0,n,m);
		System.out.println(answer);
	}
	public static int dfs(int y,int x,int n,int m)
	{
		int value=0;
		if(dp[y][x] >= 0)
			return dp[y][x];
		
		if(y == n-1 && x == m-1)
			return 1;
		
		if(y+1 < n)
		{
			if(map[y+1][x] < map[y][x])
			{
				value+=dfs(y+1,x,n,m);
			}
		}
		if(y-1 > 0)
		{
			if(map[y-1][x] < map[y][x])
			{
				value+=dfs(y-1,x,n,m);
			}				
		}
		if(x+1 < m)
		{
			if(map[y][x+1] < map[y][x])
			{
				value+=dfs(y,x+1,n,m);
			}								
		}
		if(x-1 > 0)
		{
			if(map[y][x-1] < map[y][x])
			{
				value+=dfs(y,x-1,n,m);
			}								
		}
		return dp[y][x] = value;
	}
}