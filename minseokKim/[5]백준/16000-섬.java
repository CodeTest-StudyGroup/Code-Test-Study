import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	static boolean isOutside = true;
	static char[][] result;
	static char[][] map;
	static int[][] number_map;
	static int island_num = 1;
	static int[][] visited;
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int top = 0;
		int left = 0;
		int bottom = n-1;
		int right = m-1;
		map = new char[n][m];
		number_map = new int[n][m];
		result = new char[n][m];
		visited = new int[n][m];
		for(int i = 0 ; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			map[i] = st.nextToken().toCharArray();
		}
		int before_n = 0;
		before_n = find(n,m,top,bottom,left,right,before_n);
	}
	public static int find(int n, int m, int t,int b, int l, int r,int before) throws IOException
	{
		int[] dis = new int[2];
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter (System.out));
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				if(map[i][j] == '#' && number_map[i][j] == 0)
				{
					int skip = update_map(i,j,n,m,island_num); //Âß ¿¬°áµÈ ¼¶À» Ã£À½
					island_num++;
//					j+=skip;
				}
			}
		}
		visited = new int[n+1][m+1];
		int[] check = new int[island_num];
		check_island(n,m,check,0,0);					

		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				if(number_map[i][j] != 0)
				{
					visited[i][j] = 2;
					if(check[number_map[i][j]] != 0)
						map[i][j] = 'O';
					else
						map[i][j] = 'X';
				}
				else if(visited[i][j] == 0)
				{
				}
			}
			bw.write(map[i]);
			if(i < n-1)
				bw.write('\n');
		}
		bw.close();
		return 0;
	}
	public static void check_island(int n, int m,int[] check, int start_y, int start_x)
	{
		LinkedList<Integer[]> queue = new LinkedList();
		Integer[] temp = new Integer[2];
		temp[0] = start_y;
		temp[1] = start_x;
		queue.add(temp);
		HashSet<Integer> set = new HashSet();
		while(!queue.isEmpty())
		{
			Integer[] cur = queue.poll();
			int count = 0;
			int y = cur[0];
			int x = cur[1];
			visited[y][x] = 2;
			if(y < n-1  && visited[y+1][x] == 0)
			{
				if(number_map[y+1][x] == 0)
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y+1;
					new_node[1] = x;
					queue.add(new_node);
					visited[y+1][x] = 1;
				}
				else
				{
					check[number_map[y+1][x]] = 1;
				}
			}
			if(y > 0 && visited[y-1][x] == 0)
			{
				if(number_map[y-1][x] == 0)
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y-1;
					new_node[1] = x;					
					queue.add(new_node);
					visited[y-1][x] = 1;				
				}
				else
				{
					check[number_map[y-1][x]] = 1;
				}
			}
			if(x < m-1 && visited[y][x+1] == 0)
			{
				if(number_map[y][x+1] == 0)
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y;
					new_node[1] = x+1;					
					queue.add(new_node);
					visited[y][x+1] = 1;
				}
				else
				{
					check[number_map[y][x+1]] = 1;
				}

			}
			if(x > 0 && visited[y][x-1] == 0)
			{
				if(number_map[y][x-1] == 0)
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y;
					new_node[1] = x-1;	
					queue.add(new_node);
					visited[y][x-1] = 1;
				}
				else
				{
					check[number_map[y][x-1]] = 1;
				}
			}
			if(x < m-1 && y < n-1 && visited[y+1][x+1] == 0)
			{
				if(number_map[y+1][x+1]==0 && number_map[y+1][x] != number_map[y][x+1])
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y+1;
					new_node[1] = x+1;	
					queue.add(new_node);
					visited[y+1][x+1] = 1;
				}
			}
			if(x < m-1 && y > 0 && visited[y-1][x+1] == 0)
			{
				if(number_map[y-1][x+1]==0 && number_map[y-1][x] != number_map[y][x+1])
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y-1;
					new_node[1] = x+1;	
					queue.add(new_node);
					visited[y-1][x+1] = 1;				
				}
			}
			if(x >0 && y < n-1 && visited[y+1][x-1] == 0 )
			{
				if(number_map[y+1][x-1]==0 &&  number_map[y+1][x] != number_map[y][x-1])
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y+1;
					new_node[1] = x-1;	
					queue.add(new_node);
					visited[y+1][x-1] = 1;
				}
			}
			if(x > 0 && y > 0 && visited[y-1][x-1] == 0)
			{
				if(number_map[y-1][x-1]==0 && number_map[y-1][x] != number_map[y][x-1])
				{
					Integer[] new_node = new Integer[2];
					new_node[0] = y-1;
					new_node[1] = x-1;	
					queue.add(new_node);
					visited[y-1][x-1] = 1;
				}
			}
		}
	}
	public static int update_map(int y, int x,int n, int m,int id)
	{
		LinkedList<node> queue =new LinkedList();
		int dx = 0;
		node no = new node(y,x);
		queue.add(no);
		number_map[y][x] = id;
		while(!queue.isEmpty())
		{
			node temp = queue.poll();
			visited[temp.y][temp.x] =2;
			number_map[temp.y][temp.x] = id;
			// &&number_map[temp.y+1][temp.x] == 0
			if(temp.y < n-1 && visited[temp.y+1][temp.x] == 0 && map[temp.y+1][temp.x] == '#')
			{
				node new_node = new node(temp.y+1,temp.x);
				queue.add(new_node);
				visited[temp.y+1][temp.x] = 1;
			}
			//&& number_map[temp.y-1][temp.x] == 0
			if(temp.y > 0 && visited[temp.y-1][temp.x] == 0 && map[temp.y-1][temp.x] == '#')
			{
				node new_node = new node(temp.y-1,temp.x);
				queue.add(new_node);				
				visited[temp.y-1][temp.x] = 1;
			}
			// && number_map[temp.y][temp.x+1] == 0
			if(temp.x < m-1 && visited[temp.y][temp.x+1] == 0 && map[temp.y][temp.x+1] == '#')
			{
				if(temp.y == y)
					dx++;
				node new_node = new node(temp.y,temp.x+1);
				queue.add(new_node);
				visited[temp.y][temp.x+1] = 1;
			}
			//&& number_map[temp.y][temp.x-1] == 0
			if(	temp.x > 0 &&visited[temp.y][temp.x-1] == 0 && map[temp.y][temp.x-1] == '#')
			{
				if(temp.y == y)
					dx++;
				node new_node = new node(temp.y,temp.x-1);
				queue.add(new_node);
				visited[temp.y][temp.x-1] = 1;
			}
		}
		return dx;
	}
}

class node
{
	int y;
	int x;
	node(int i, int j)
	{
		y = i;
		x = j;
	}
}