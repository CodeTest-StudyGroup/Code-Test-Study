package bfs;
import java.io.*;
import java.util.*;

public class 확장게임 {
	static int n;
	static int m;
	static int people;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st =new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		people = Integer.parseInt(st.nextToken());
		int[][] board= new int[n][m];
		int[][] arr = new int[n][m];
		int[] turn = new int[people+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=people; i++)
			turn[i] = Integer.parseInt(st.nextToken());
		PriorityQueue<Node> pq = new PriorityQueue<>((a1,a2)->{return a1.weight-a2.weight;});

		int[] check = new int[people+1];
		for(int i=0; i<n; i++)
		{
			String temp = br.readLine();
			for(int j=0; j<m; j++)
			{
				if(temp.charAt(j)=='.')
				{
					board[i][j]=0;
				}
				else if(temp.charAt(j)=='#')
					board[i][j]=-1;
				else
				{
					board[i][j]=(temp.charAt(j)-'0');
					pq.offer(new Node(i,j,board[i][j],board[i][j]));
					check[board[i][j]]+=1;
				}
				
			}
		}
		int weight = people;
		boolean[][] visited = new boolean[n][m];
		while(!pq.isEmpty())
		{
			
			Node temp = pq.peek();
			int end = check[temp.idx];
			check[temp.idx]=0;
			weight+=1;
			int count = turn[temp.idx]; //해당 횟수만큼 돌아야한다는뜻
			Queue<Node> queue = new LinkedList<>();
			int cnt = 1;
			for(int k=0; k<end; k++)
			{
				Node tmp = pq.poll();
				for(int i=0; i<dx.length; i++)
				{
					int dir_x = tmp.x+dx[i];
					int dir_y = tmp.y+dy[i];
					if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<m)
					{
						if(board[dir_x][dir_y]==0 )
						{
							board[dir_x][dir_y] = temp.idx;
		
							if(cnt==count)
							{
								pq.offer(new Node(dir_x,dir_y,temp.idx,weight));
								check[temp.idx]+=1;

							}
							else
								queue.offer(new Node(dir_x,dir_y,temp.idx,temp.weight,cnt));
		
						//queue2.offer(new Node(dir_x,dir_y,temp.idx,weight));
						}
					}
				
				}
			

			}
				while(!queue.isEmpty())
				{
					Node temp2 = queue.poll();
					for(int i=0; i<dx.length; i++)
					{
						int dir_x = temp2.x+dx[i];
						int dir_y = temp2.y+dy[i];
						if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<m)
						{
							if(board[dir_x][dir_y]==0)
							{
								board[dir_x][dir_y] = temp2.idx;
								if(temp2.count+1==count)
								{
									
									pq.offer(new Node(dir_x,dir_y,temp.idx,weight));
									check[temp.idx]+=1;
									
								}
								else
									queue.offer(new Node(dir_x,dir_y,temp.idx,temp2.weight,temp2.count+1));
								
								//queue2.offer(new Node(dir_x,dir_y,temp.idx,weight));
									
							}
						}
						
					}
				}
	
			
			
		}
		int[] answer = new int[people+1];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				if(board[i][j]!=-1)
						answer[board[i][j]]+=1;
		}
		for(int i=1; i<=people; i++)
			bw.append(answer[i]+""+" ");
		
		bw.flush();
		bw.close();

		
	}

}

class Node{
	int x;
	int y;
	int idx;
	int weight;
	int count;
	public Node(int x, int y,int idx, int weight)
	{
		this.x = x;
		this.y = y;
		this.idx = idx;
		this.weight = weight;
		
	}
	public Node(int x, int y, int idx, int weight,int count)
	{
		this.x = x;
		this.y =y;
		this.idx = idx;
		this.count = count;
	}
}
