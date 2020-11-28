import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] map = new int[n][n];
		PriorityQueue<node> pq= new PriorityQueue();
		for(int i = 0 ; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j <n; j++)
			{
				int value = Integer.parseInt(st.nextToken());
				map[i][j] = value;
				if(i== n-1)
				{
					node n_node = new node(i,j,value);
					pq.add(n_node);
				}
			}
		}
		int answer = 0;
		for(int i = 0; i < n; i++)
		{
			node cur = pq.poll();
			answer = cur.v;
			if(cur.y > 0)
			{
				node next_node = new node(cur.y-1,cur.x,map[cur.y-1][cur.x]);
				pq.add(next_node);
			}			
		}
		System.out.println(answer);
	}
}
class node implements Comparable<node>
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
	@Override
	public int compareTo(node o) {
		if(this.v > o.v)
			return -1;
		else if(this.v < o.v)
			return 1;		
		return 0;
	}
}