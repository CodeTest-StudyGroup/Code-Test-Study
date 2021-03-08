package bfs;
import java.io.*;
import java.util.*;

public class 일요일아침의데이트 {
	static class Node implements Comparable<Node>{
		int x;
		int y;
		int g_count;
		int near_count;
		public Node(int x,int y,int g_count,int near_count)
		{
			this.x = x;
			this.y =y;
			this.g_count =g_count;
			this.near_count = near_count;
		}
		@Override
		public int compareTo(Node o) {
			if(this.g_count<o.g_count)
			{
				return -1;
				
			}
			else if(this.g_count==o.g_count)
			{
				return this.near_count-o.near_count;
			}
			else
				return 1;

		}
		
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int[]dx = {-1,0,1,0};
		int[] dy = {0,1,0,-1};
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int start_x=0;
		int start_y=0;
		int end_x =0;
		int end_y =0;
		int answer1=987654321;
		int answer2 = 987654321;

//		int[][] g_arr = new int[n][m];
//		int[][] near_arr =new int[n][m];
//		int[][] distance = new int[n][m];
		char [][] arr = new char[n][m];
		boolean[][] visited =new boolean[n][m];
		for(int i=0; i<n; i++)
		{
			String temp = br.readLine();
			for(int j=0; j<m; j++)
			{
				arr[i][j] =temp.charAt(j);
				if(arr[i][j]=='S')
				{
					start_x = i;
					start_y =j;
				}
				if(arr[i][j]=='F')
				{
					end_x =i;
					end_y=j;
				}
//				g_arr[i][j]=50000;
//				near_arr[i][j]=50000;
//				distance[i][j]=50000;
					
			}
		}
		PriorityQueue<Node> queue = new PriorityQueue<>();


		int start_near=0;

		visited[start_x][start_y]=true;
		queue.offer(new Node(start_x,start_y,0,0));

		while(!queue.isEmpty())
		{
			Node cur = queue.poll();
			
			int cur_x = cur.x;
			int cur_y = cur.y;
			int cur_count = cur.g_count;
			int cur_near = cur.near_count;
			if(cur_x==end_x && cur_y==end_y)
			{
				boolean flag = true;
				for(int i=0; i<dx.length; i++)
				{
					int check_x = cur_x+dx[i];
					int check_y = cur_y +dy[i];
					if(arr[check_x][check_y]=='g')
					{
						flag=false;
						break;
					}
				}
				if(flag==false)
					cur_near--;
				answer1 = cur_count;
				answer2 = cur_near;
				break;
			}
			for(int i=0; i<dx.length; i++)
			{
				int dir_x = cur_x+dx[i];
				int dir_y = cur_y+dy[i];
				int temp_g_count = cur_count; //쓰레기밭인
				int temp_near_count = cur_near; //ㅅ주변에 쓰레기가있는지
				
				
				if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<m)
				{
					if(visited[dir_x][dir_y]==false)
					{


						if(arr[dir_x][dir_y]=='g')
							temp_g_count++;
						else
						{
						for(int j=0; j<dx.length; j++)
						{
							int near_x = dir_x+dx[j];
							int near_y = dir_y+dy[j];
							if(0<=near_x && near_x<n && 0<=near_y && near_y<m)
							{
								if(arr[near_x][near_y]=='g')
								{
									temp_near_count++;
									break;
								}
							}
						}
						}
					
						visited[dir_x][dir_y]=true;
						queue.offer(new Node(dir_x,dir_y,temp_g_count,temp_near_count));
						
					}

				}
				
			}
					
				
				
		}
		System.out.println(answer1+" "+answer2);

	}

}
