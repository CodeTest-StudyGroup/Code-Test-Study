import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		int[][] cnt_map = new int[n][m];
		boolean[][] visited = new boolean[n][m];
		int cheese_cnt = 0;
		for(int i = 0 ; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++)
			{
				int input = Integer.parseInt(st.nextToken());
				map[i][j] = input;
				if(input == 1)
					cheese_cnt++;
			}
		}
		int answer = 0;
		while(cheese_cnt > 0)
		{
		answer++;
		visited = new boolean[n][m];
		LinkedList<node> erase =new LinkedList();
		cnt_map = new int[n][m];
		visited[0][0] = true;

		Queue<node> queue = new LinkedList();
		node n_node = new node(0,0);
		queue.add(n_node);

		while(!queue.isEmpty())
		{
			node cur = (node)queue.poll();
			if(cur.y > 0)
			{
				if(map[cur.y-1][cur.x] == 0 && !visited[cur.y-1][cur.x])
				{	
				node next = new node(cur.y-1,cur.x);
				queue.add(next);
				visited[cur.y-1][cur.x] = true;

				}
				else if(map[cur.y-1][cur.x] == 1)
				{
					if(cnt_map[cur.y-1][cur.x] == 1)
					{
						node er = new node(cur.y-1,cur.x);
						erase.add(er);
						cnt_map[cur.y-1][cur.x]++; //2로 만들어 더이상 안들어오게
					}
					else
					{
						cnt_map[cur.y-1][cur.x]++; 
					}
				}
					
			}
			if(cur.y < n-1)
			{
				if(map[cur.y+1][cur.x] == 0  && !visited[cur.y+1][cur.x])
				{
				node next = new node(cur.y+1, cur.x);
				queue.add(next);
				visited[cur.y+1][cur.x] = true;
				}
				else  if(map[cur.y+1][cur.x] == 1)
				{
					if(cnt_map[cur.y+1][cur.x] == 1)
					{
						node er = new node(cur.y+1,cur.x);
						erase.add(er);
						cnt_map[cur.y+1][cur.x]++; 
					}
					else
					{
						cnt_map[cur.y+1][cur.x]++; 
					}					
				}
			}
			if(cur.x > 0)
			{
				if(map[cur.y][cur.x-1] == 0 && !visited[cur.y][cur.x-1])
				{
				node next = new node(cur.y,cur.x-1);
				queue.add(next);
				visited[cur.y][cur.x-1] = true;
				}
				else if(map[cur.y][cur.x-1] == 1)
				{
					if(cnt_map[cur.y][cur.x-1] == 1)
					{						
						node er = new node(cur.y,cur.x-1);
						erase.add(er);
						cnt_map[cur.y][cur.x-1]++; 
					}
					else
					{
						cnt_map[cur.y][cur.x-1]++; 
					}										
				}
			}
			if(cur.x < m-1)
			{
				if(map[cur.y][cur.x+1] == 0 && !visited[cur.y][cur.x+1])
				{
				node next = new node(cur.y, cur.x+1);
				queue.add(next);
				visited[cur.y][cur.x+1] = true;
				}
				else if(map[cur.y][cur.x+1] == 1)
				{
					if(cnt_map[cur.y][cur.x+1] == 1)
					{
						node er = new node(cur.y,cur.x+1);
						erase.add(er);
						cnt_map[cur.y][cur.x+1]++; 
					}
					else
					{
						cnt_map[cur.y][cur.x+1]++; 
					}															
				}
			}
		}
		Iterator it = erase.iterator();
		while(it.hasNext())
		{
			node cur_er = (node)it.next();
			map[cur_er.y][cur_er.x] = 0;
			cheese_cnt--;
		}
		}
		System.out.println(answer);
	}
}
class node
{
	int y;
	int x;
	node(int i,int j)
	{
		y = i;
		x = j;
	}
}
