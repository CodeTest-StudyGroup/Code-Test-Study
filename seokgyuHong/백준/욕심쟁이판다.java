package 분류전;
import java.io.*;
import java.util.*;
public class 욕심쟁이판다 {

	static int[][] map;
	static int n;
	static int[][] bamboo;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static boolean[][] visited;
	static int[][] dp;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		bamboo = new int[n][n];
		visited = new boolean[n][n];
		dp = new int[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				map[i][j]=1;
				dp[i][j]=1;
			}
				
		for(int i=0; i<n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++)
				bamboo[i][j] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(!visited[i][j])
				{
					visited[i][j]=true;
					dfs(i,j);
				}
			}

		}
		int answer=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				if(dp[i][j]>answer)
					answer=dp[i][j];
		}
		System.out.println(answer);

	}
	static void dfs(int x, int y)
	{
		for(int k=0; k<dx.length; k++)
		{
			int dir_x = x+dx[k];
			int dir_y = y+dy[k];
			if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<n)
			{
				if(bamboo[dir_x][dir_y]>bamboo[x][y])
				{
					if(!visited[dir_x][dir_y])
					{
						visited[dir_x][dir_y]=true;
						dfs(dir_x,dir_y);
						if(dp[dir_x][dir_y]+1>dp[x][y])
							dp[x][y]=dp[dir_x][dir_y]+1;
					}
					else
					{
						if(dp[dir_x][dir_y]+1>dp[x][y])
							dp[x][y] = dp[dir_x][dir_y]+1;
					}
					
				}
			}
			
		}
	}
//	static void start(int x, int y)
//	{
//		for(int k=0; k<dx.length; k++)
//		{
//			int dir_x = x+dx[k];
//			int dir_y = y+dy[k]; //4방향 
//			if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<n) //4방향이 제대로들어있을경우
//			{
////				if(bamboo[dir_x][dir_y]>bamboo[x][y] && map[x][y]+1>map[dir_x][dir_y]) //나무가더많으면
////				{
////					map[dir_x][dir_y]=map[x][y]+1;
////					dfs(dir_x,dir_y);
////				}
//				if(bamboo[dir_x][dir_y]>bamboo[x][y]) //갈곳이 더 대나무가 많으
//				{
//					if(dp[dir_x][dir_y]>=dp[x][y])
//						dp[x][y]=dp[dir_x][dir_y];
//					else
//					{
//						int temp =dfs(dir_x,dir_y,0);
//						if(dp[x][y]<temp)
//							dp[x][y]=temp;
//					}
//				}
//					
//				
//			}
//			dp[x][y]+=1;
//
//		}
//		
//	}
//	static int dfs(int x, int y, int cnt)
//	{
//		for(int i=0; i<dx.length;i++)
//		{
//			int dir_x = x+dx[i];
//			int dir_y = y+dy[i];
////			if(dir_x<0 && dir_x>=n && dir_y<0 && dir_y>=n)
////				return;
////			else
////			{
////				if(bamboo[dir_x][dir_y]>bamboo[x][y])
////				{
////					dfs(dir_x,dir_y,cnt+1);
////					
////					
////				}
////			}
//			if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<n) 
//					
//
//		}
//
//		
//		
//	}

}
