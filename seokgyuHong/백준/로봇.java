package bfs;

import java.util.*;


import java.io.*;
public class 로봇 {
	static int[][] arr;
	static int m;
	static int n;
	static int[] dx = {0,0,0,1,-1};
	static int[] dy = {0,1,-1,0,0};
	static Node[][] parent;
	static int end_x;
	static int end_y;
	static int end_dir;
	static int start_x;
	static int start_y;
	static int start_dir;
	static int cnt=0;
	static int answer=0;
	static class Node{
		int x;
		int y;
		int dir;
		int weight;
		Node(int x,int y, int dir,int weight)
		{
			this.x =x;
			this.y = y;
			this.dir = dir;
			this.weight =weight;
		}


	}
	public static void main(String[] args)throws IOException {
		// TODO Auto-generated method stub	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		PriorityQueue<Node> pq = new PriorityQueue<>();
		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr= new int[m+1][n+1];
		boolean[][] check = new boolean[m+1][n+1];
		boolean[][] turn_check = new boolean[m+1][n+1];
		for(int i=1; i<=m; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=n; j++)
			{
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		start_x= Integer.parseInt(st.nextToken());
		start_y = Integer.parseInt(st.nextToken());
		start_dir = Integer.parseInt(st.nextToken());
		Queue<Node> queue = new LinkedList<>();
		st = new StringTokenizer(br.readLine());
		end_x = Integer.parseInt(st.nextToken());
		end_y = Integer.parseInt(st.nextToken());
		end_dir = Integer.parseInt(st.nextToken());
		//queue.offer(new Node(start_x,start_y,start_dir));
		queue.offer(new Node(start_x,start_y,start_dir,0));
		check[start_x][start_y]=true;
		int dir_x;
		int dir_y;

		while(!queue.isEmpty())
		{
			Node temp = queue.poll();
//			if(turn_check[temp.x][temp.y]==false)
//			{
//				if(temp.dir==1)
//				{
//					queue.offer(new Node(temp.x,temp.y,2,temp.weight+2));
//					queue.offer(new Node(temp.x,temp.y,3,temp.weight+1));
//					queue.offer(new Node(temp.x,temp.y,4,temp.weight+1));
//				}
//				if(temp.dir==2)
//				{
//					queue.offer(new Node(temp.x,temp.y,1,temp.weight+2));
//					queue.offer(new Node(temp.x,temp.y,3,temp.weight+1));
//					queue.offer(new Node(temp.x,temp.y,4,temp.weight+1));
//				}
//				if(temp.dir==3)
//				{
//					queue.offer(new Node(temp.x,temp.y,4,temp.weight+2));
//					queue.offer(new Node(temp.x,temp.y,1,temp.weight+1));
//					queue.offer(new Node(temp.x,temp.y,2,temp.weight+1));
//				}
//				if(temp.dir==4)
//				{
//					queue.offer(new Node(temp.x,temp.y,3,temp.weight+2));
//					queue.offer(new Node(temp.x,temp.y,1,temp.weight+1));
//					queue.offer(new Node(temp.x,temp.y,2,temp.weight+1));
//				}
//				turn_check[temp.x][temp.y]=true;
//			}
			if(temp.x==end_x && temp.y==end_y)
			{
				answer = temp.weight;
				if(temp.dir==end_dir)
					continue;
				else if((temp.dir==1 && end_dir==2)||(temp.dir==2 && end_dir==1))
					answer+=2;
				else if((temp.dir==3 && end_dir==4)||(temp.dir==4&&end_dir==3))
					answer+=2;
				else
					answer+=1;
				break;
			}
			for(int i=1; i<=4; i++)
			{
				if(temp.dir==i)
				{
					dir_x = temp.x;
					dir_y = temp.y;
					for(int j=0; j<3; j++)
					{
						boolean flag = false;
						dir_x = dir_x+dx[i];
						dir_y = dir_y+dy[i];
						if(1<=dir_x&& dir_x<=m && 1<=dir_y&&dir_y<=n)
						{
							if(arr[dir_x][dir_y]==0)
							{
								if(check[dir_x][dir_y]==false)
								{
									check[dir_x][dir_y]=true;
									queue.offer(new Node(dir_x,dir_y,temp.dir,temp.weight+1));
								}
							}
							else
								flag=true;
							
						}
						else
							flag=true;
						if(flag==true)
							break;
						
					}
					
				}


			}
			if(turn_check[temp.x][temp.y]==false)
			{
				if(temp.dir==1)
				{
					queue.offer(new Node(temp.x,temp.y,2,temp.weight+2));
					queue.offer(new Node(temp.x,temp.y,3,temp.weight+1));
					queue.offer(new Node(temp.x,temp.y,4,temp.weight+1));
				}
				if(temp.dir==2)
				{
					queue.offer(new Node(temp.x,temp.y,1,temp.weight+2));
					queue.offer(new Node(temp.x,temp.y,3,temp.weight+1));
					queue.offer(new Node(temp.x,temp.y,4,temp.weight+1));
				}
				if(temp.dir==3)
				{
					queue.offer(new Node(temp.x,temp.y,4,temp.weight+2));
					queue.offer(new Node(temp.x,temp.y,1,temp.weight+1));
					queue.offer(new Node(temp.x,temp.y,2,temp.weight+1));
				}
				if(temp.dir==4)
				{
					queue.offer(new Node(temp.x,temp.y,3,temp.weight+2));
					queue.offer(new Node(temp.x,temp.y,1,temp.weight+1));
					queue.offer(new Node(temp.x,temp.y,2,temp.weight+1));
				}
				turn_check[temp.x][temp.y]=true;
				
			}

			
		}

		System.out.println(answer);
		
	
		
		
		
		
	}


}
