import java.util.*;
import java.io.*;
public class Main {
	public static int far_node = 0;
	public static int max = -1;
	public static LinkedList[] list;
	public static boolean[] visited;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int v = Integer.parseInt(br.readLine());
		list = new LinkedList[100001];
		visited = new boolean[100001];
		for(int i = 1; i <= 100000; i++)
		{
			list[i] = new LinkedList<node>();
		}
		for(int i = 1 ; i <= v; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int row = Integer.parseInt(st.nextToken());
			while(true)
			{
				int dest = Integer.parseInt(st.nextToken());
				if(dest == -1)
					break;
				int len = Integer.parseInt(st.nextToken());
				node no = new node(dest,len);
				list[row].add(no);
			}
		}
		visited[1] = true;
		dfs(1,0);
		visited[1] = false;
		visited = new boolean[100001];
		visited[far_node] = true;
		dfs(far_node,0);
		visited[far_node] = false;
		System.out.println(max);
	}
	public static void dfs(int cur, int sum)
	{
		Iterator it = list[cur].iterator();
		while(it.hasNext())
		{
			node next = (node)it.next();
			if(visited[next.dest])
				continue;
			visited[cur] = true;
			dfs(next.dest, sum+next.len);
			visited[cur] = false;
		}
		if(max < sum)
		{
			max = sum;
			far_node = cur;
		}
	}
}
class node
{
	int dest;
	int len;
	node(int i,int j)
	{
		dest = i;
		len = j;
	}
	
}
