package bfs;
import java.util.*;



import java.io.*;
public class 다리만들기 {
	static class Node{
		int x;
		int y;
		Node(int x,int y)
		{
			this.x =x;
			this.y =y;
		}
		
		public String toString()
		{
			return x+","+y;
		}
		
	}
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};

	public static void main(String[] args)throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		int[][] graph = new int[n][n];
		boolean[][] check = new boolean[n][n];
		ArrayList<Node> arr = new ArrayList<>();
		int[][] island = new int[n][n];
		int answer=987654321;
		for(int i=0; i<n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++)
			{
				graph[i][j]=Integer.parseInt(st.nextToken());
				
			}
		}
		Queue<Node> queue = new LinkedList<>();
		int cnt=1;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(graph[i][j]==1)
				{
					if(check[i][j]==false)
					{
						check[i][j]=true;
						queue.offer(new Node(i,j));
						arr.add(new Node(i,j));
						island[i][j]=cnt;
						while(!queue.isEmpty())
						{
							Node node = queue.poll();
							for(int k=0; k<dx.length; k++)
							{
								int dir_x = node.x+dx[k];
								int dir_y = node.y+dy[k];
								if(0<=dir_x && dir_x<n && 0<=dir_y && dir_y<n)
								{
									if(graph[dir_x][dir_y]==1)
									{
										if(check[dir_x][dir_y]==false)
										{
											check[dir_x][dir_y]=true;
											island[dir_x][dir_y]=cnt;
											queue.offer(new Node(dir_x,dir_y));
											arr.add(new Node(dir_x,dir_y));
										}
									}
								}
								
							}
						}
						cnt+=1;
					}
				}
				
			}
		}

		for(int i=0; i<arr.size(); i++)
		{
			Node node = arr.get(i);
			if(island[node.x][node.y]!=0)
			{
				for(int j=0; j<arr.size(); j++)
				{
					Node node2 = arr.get(j);
					if(island[node2.x][node2.y]!=island[node.x][node.y])
					{
						if(island[node2.x][node2.y]!=0)
						{
							int temp = Math.abs(node2.x-node.x)+Math.abs(node2.y-node.y)-1;
							if(temp<answer)
								answer=temp;
						}
					}
				
				}
				
			}

		}
		System.out.println(answer);
		
		
	}

}
