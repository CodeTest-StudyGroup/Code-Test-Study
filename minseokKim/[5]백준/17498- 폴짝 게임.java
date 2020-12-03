import java.util.*;
import java.io.*;
public class Main {
	static int[][] map;
	static int[][] dp;
	static int n;
	static int m;
	static int d;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		dp = new int[n][m];
//		LinkedList<node>list = new LinkedList();
		for(int i = 0 ; i < n ; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++)
			{
				map[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = Integer.MIN_VALUE;
			}
		}
		int answer = Integer.MIN_VALUE;
		for(int j = 0 ; j < m; j++)
		{
			answer = Math.max(answer, dfs(0,j));
		}
//		while(!list.isEmpty())
//		{
//			node cur = list.poll();
//			if(cur.y == n-1)
//			{
//				answer = Math.max(answer,cur.sum);
//				continue;
//			}
//			for(int i = cur.y+1; i<= ((cur.y+d>=n)?n-1:cur.y+d); i++)
//			{
//				for(int j = 0; j< m; j++)
//				{
//					if(Math.abs(i-cur.y)+Math.abs(j-cur.x) <= d)
//					{
//						node next = new node(i,j,cur.sum+map[cur.y][cur.x]*map[i][j]);
//						list.add(next);
//					}
//				}
//			}
//		}
		System.out.println(answer);
	}
	public static int dfs(int y, int x)
	{
		if(dp[y][x] != Integer.MIN_VALUE)
			return dp[y][x];
		if(y == n-1)
			return 0;
		int temp_max = Integer.MIN_VALUE;
		for(int i = y+1; i<= ((y+d>=n)?n-1:y+d); i++)
		{
			for(int j = ((x-d)<0?0:x-d); j< x; j++)
			{
				if(Math.abs(i-y)+Math.abs(j-x) <= d)
				{
					temp_max = Math.max(temp_max,dfs(i,j)+map[i][j]*map[y][x]);
				}
			}
			
			for(int j = x; j<=((x+d)>=m?m-1:x+d); j++)
			{
				if(Math.abs(i-y)+Math.abs(j-x) <= d)
				{
					temp_max = Math.max(temp_max,dfs(i,j)+map[i][j]*map[y][x]);
				}
			}
		}
		return dp[y][x] = temp_max;
	}
}
class node
{
	int y;
	int x;
	int sum;
	node(int i ,int j , int k)
	{
		y= i;
		x = j;
		sum = k;
	}
}