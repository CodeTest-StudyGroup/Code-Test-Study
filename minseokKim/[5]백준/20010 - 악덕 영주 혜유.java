import java.io.*;
import java.util.*;
public class Main
{
	static int far_v = 0;
	static int far = 0;
	public static void main(String[] args) throws Exception
	{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st= new StringTokenizer(br.readLine());
	int n = Integer.parseInt(st.nextToken());
	int m = Integer.parseInt(st.nextToken());
	int[][] map = new int[n][n];
	int[] parent = new int[n];
		LinkedList<node> list = new LinkedList();	
		
		for(int i = 0 ; i < n; i++)
		Arrays.fill(map[i], -1);
		Arrays.fill(parent, -1);
		
		for(int i = 0 ; i < m ; i++)
		{
			st= new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y =Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
//			map[x][y] = v;
			node no = new node( x, y,  v);
			list.add(no);
		}	
		Collections.sort(list,new mycomp());
		int best = kruskal(list,parent,n,map);

		int worst = 0;
		boolean[] visited = new boolean[n];
		visited[0] = true;
		dfs(map,0,visited,n,0);
		visited[0] = false;
		dfs(map,far,visited,n,0);
		System.out.println(best);
		System.out.println(far_v);
	}
	public static void dfs(int[][] map, int start, boolean[] v,int n,int cur)
	{
		int j = 0;
		int total = 0;
		for(int i = 0; i < n; i++)
		{
			int temp = 0;
			if(v[i] == true)
				continue;
			else if(map[start][i] > 0)
			{
				v[i] = true;
				dfs(map,i,v,n,cur+map[start][i]);
				v[i] = false;
			}
		}
		if(cur > far_v)
		{
			far_v = cur;
			far = start;
		}
	}
	public static int kruskal(LinkedList<node> list,int[] p,int n,int[][] map)
	{
		Iterator it = list.iterator();
		int total = 0;
		int count = 0;
		while(it.hasNext())
		{
			if(count == n)
				break;
			node temp = (node)it.next();
			int parent_sum = Math.abs(p[temp.to]) +Math.abs(p[temp.from]);
			int r1, r2;
			boolean flag = false;
			if((r1 = findroot(temp.to,p)) == (r2 =findroot(temp.from,p)))
				flag = false;
			else
				flag = true;

			if(flag)
			{
				total+= temp.v;
				count++;
				if(p[r1] <= p[r2])
				{
					p[r2] = r1;
					p[r1] = (-1)*parent_sum;
				}
				else
				{
					p[r1]= r2;
					p[r2] = (-1)*parent_sum;
				}
				map[temp.to][temp.from] = temp.v;
				map[temp.from][temp.to] = temp.v;				
			}
		}
		return total;
	}
	public static int findroot(int x,int[] p)
	{
		int r = x;
		int c = x;
		for(; p[r] > 0; r = p[r]);
		while(c != r)
		{
			int parent = p[c];
			p[c] = r;
			c = parent;
		}
		return r;
	}
}
class node
{
	int from;
	int to;
	int v;
	node(int i,int j,int k)
	{
		from = i;
		to = j;
		v = k;
	}
}
class mycomp implements Comparator<node>
{
	@Override
	public int compare(node o1, node o2) {
		if(o1.v < o2.v)
			return -1;
		else if(o1.v > o2.v)
			return 1;
		else 	
			return 0;
	}	
}

//class mycomp2 implements Comparator<node>
//{
//	@Override
//	public int compare(node o1, node o2) {
//		if(o1.v > o2.v)
//			return -1;
//		else if(o1.v < o2.v)
//			return 1;
//		else 	
//			return 0;
//	}	
//}
