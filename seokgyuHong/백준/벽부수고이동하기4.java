package 분류전;

import java.io.*;
import java.util.*;

public class 벽부수고이동하기4 {
	static int n;
	static int m;
	static int[][] arr;
	static int[][] answer;
	static boolean[][] visited;
	static int[][] dp;
	static int[]dx = {-1,0,1,0};
	static int[]dy = {0,1,0,-1};
	static int count=0;
	static Node[][] parent;
	static class Node{
		int x;
		int y;
		int idx;
		public Node(int x,int y)
		{
			this.x = x;
			this.y = y;
		}
		public Node(int x, int y, int idx)
		{
			this.x = x;
			this.y =y;
			this.idx = idx;
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		answer = new int[n][m];
		dp = new int[n][m];
		visited = new boolean[n][m];
		 parent = new Node[n][m];
		ArrayList<Node> nodeList = new ArrayList<>();
		ArrayList<Node> zeroList = new ArrayList<>();
		int group_num=0;
		for(int i=0; i<n; i++)
		{
			
			String temp =br.readLine();
			for(int j=0; j<m; j++)
			{
				arr[i][j] =(temp.charAt(j)-'0');
				if(arr[i][j]==1)
				{
					nodeList.add(new Node(i,j));
					dp[i][j] =1;
				}
				else
					zeroList.add(new Node(i,j));
				group_num++;
				parent[i][j] = new Node(i,j,group_num);
			}
		}
		for(int i=0; i<zeroList.size(); i++)
		{
			Node temp = zeroList.get(i);
			if(visited[temp.x][temp.y]==false)
			{
				visited[temp.x][temp.y]=true;
				count=1;
				group_num++;
				dfs(temp.x,temp.y,temp.x,temp.y);
				dp[temp.x][temp.y]=count;
			}
			
		}
			
		for(int i=0; i<nodeList.size(); i++)
		{
			Node temp = nodeList.get(i);
			count=1;
			find(temp.x,temp.y);
			answer[temp.x][temp.y] = (count%10);
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				bw.append(answer[i][j]+"");
			}
			bw.append("\n");
		}
		bw.flush();
		bw.close();
		
	}

	static void find(int x, int y)
	{
		Map<Integer,Integer> map = new HashMap<>();
		for(int i=0; i<dx.length; i++)
		{
			int dir_x = x+dx[i];
			int dir_y = y+dy[i];
			if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<m)
			{
				if(arr[dir_x][dir_y]==0)
				{
				Node temp = parent[dir_x][dir_y];
					if(map.isEmpty())
					{
					map.put(temp.idx,dp[temp.x][temp.y]);
					count+=dp[temp.x][temp.y];
					}
					else
					{
						if(!map.containsKey(temp.idx))
						{
							map.put(temp.idx,dp[temp.x][temp.y]);
							count+=dp[temp.x][temp.y];
						}
					}
				}
			}

		}

	}
	
	static void dfs(int x, int y, int start_x, int start_y)
	{
		for(int i=0; i<dx.length; i++)
		{
			int dir_x = x+dx[i];
			int dir_y = y+dy[i];
			if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<m)
			{
				if(arr[dir_x][dir_y]==0 && visited[dir_x][dir_y]==false)
				{
					visited[dir_x][dir_y]=true;
					count+=1;
					parent[dir_x][dir_y] = new Node(start_x,start_y,parent[start_x][start_y].idx);
					dfs(dir_x,dir_y,start_x,start_y);
				}
			}
		}
		
	}
}
