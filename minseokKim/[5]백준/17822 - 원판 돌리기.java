import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		int[][] board = new int[n+1][m+1];
		for(int i = 1; i <= n; i++)
		{
			st = new StringTokenizer(br.readLine());			
			for(int j = 1; j <=m; j++)
			{
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int sum = 0;
		for(int c = 0; c < t; c++)
		{
			st = new StringTokenizer(br.readLine());
			int mul = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			int rot = Integer.parseInt(st.nextToken());
			for(int d = mul; d<= n; d+=mul) //배수 회전
			{
				int temp = 0;
				if(dir == 0)
				{
					for(int r = 0; r < rot; r++)
					{
						temp = board[d][m];
						for(int j = m-1; j>= 1; j--)
						{
							board[d][j+1] = board[d][j]; 
						}
						board[d][1] = temp;
					}
				}
				else
				{
					for(int r = 0; r < rot; r++)
					{
						temp = board[d][1];
						for(int j = 2; j<= m; j++)
						{
							board[d][j-1] = board[d][j]; 
						}
						board[d][m] = temp;
					}					
				}
			}
			//다 돌고 왔으면 이중 for문 돌면서
			//y+1 y-1 x+1 x-1 뒤져보면서 제거할거는 제거해줘야함 
			boolean[][] visited = new boolean[n+1][m+1];
			boolean flag = false;
			double avg = 0;
			int avg_cnt = 0;
			for(int i = 1 ; i <=n; i++)
			{
				for(int j = 1; j <=m; j++)
				{
					Queue<node> queue = new LinkedList();
					if(visited[i][j] || board[i][j] == 0)
						continue;
					avg+=board[i][j];
					avg_cnt++;
					node no = new node(i,j,board[i][j]);
					queue.add(no);
					while(!queue.isEmpty())
					{
						node cur = queue.poll();
						visited[cur.y][cur.x] = true;
						if(cur.y > 1 &&  cur.v == board[cur.y-1][cur.x])
						{
							flag = true;
							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y-1][cur.x] = 0; //다음 위치도 0으로
							node next = new node(cur.y-1,cur.x,cur.v);
							queue.add(next);
						}
						if(cur.y < n && cur.v == board[cur.y+1][cur.x])
						{
							flag = true;

							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y+1][cur.x] = 0; //다음 위치도 0으로
							node next = new node(cur.y+1,cur.x,cur.v);							
							queue.add(next);
						}
						if(cur.x > 1 && cur.v == board[cur.y][cur.x-1])
						{
							flag = true;
							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y][cur.x-1] = 0; //다음 위치도 0으로
							node next = new node(cur.y,cur.x-1,cur.v);														
							queue.add(next);
						}
						if(cur.x < m && cur.v == board[cur.y][cur.x+1])
						{
							flag = true;
							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y][cur.x+1] = 0; //다음 위치도 0으로
							node next = new node(cur.y,cur.x+1,cur.v);														
							queue.add(next);
						}
						if(cur.x == m && cur.v == board[cur.y][1])
						{
							flag = true;
							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y][1] = 0; //다음 위치도 0으로
							node next = new node(cur.y,1,cur.v);														
							queue.add(next);							
						}
						if(cur.x == 1 && cur.v == board[cur.y][m])
						{
							flag = true;
							board[cur.y][cur.x] = 0; //현위지치를 0으로
							board[cur.y][m] = 0; //다음 위치도 0으로
							node next = new node(cur.y,m,cur.v);														
							queue.add(next);														
						}
					}
				}
			}
			avg/=(double)avg_cnt;
			sum = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <=m; j++)
				{
					if(!flag) //지운게 없으면 
					{
						if(board[i][j] == 0)
							continue;
						if(board[i][j] > avg)
						{
							board[i][j]--;
						}
						else if(board[i][j] < avg)
						{
							board[i][j]++;
						}
					}
					sum+=board[i][j];
				}
			}
		}
		System.out.println(sum);
	}
}
class node
{
	int y;
	int x;
	int v;
	node(int i, int j, int k)
	{
		y = i;
		x = j;
		v = k;
	}
}
