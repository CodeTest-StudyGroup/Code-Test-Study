import java.util.*;
import java.io.*;

public class Main {
	public static LinkedList[] list;
	public static int[] value;
	public static boolean[] visited;
	public static int[] dp_selected;
	public static int[] dp_nonselected;
	public static int n = 0;
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		n = Integer.parseInt(br.readLine());
		list = new LinkedList[n+1];
		value = new int[n+1];
		visited = new boolean[n+1];
		dp_selected = new int[n+1];
		dp_nonselected = new int[n+1];
		int[] input = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i<= n; i++)
		{
			list[i] = new LinkedList<Integer>();
			if(i>=2)
				input[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++)
		{
			dp_selected[i] = -1;
			dp_nonselected[i] = -1;
			value[i] = Integer.parseInt(st.nextToken());
			if(i>=2)
				list[input[i]].add(i);
		}
		visited[1] = true;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Iterator it = list[1].iterator();
		int sum = 0;
		while(it.hasNext())
		{
			int next = (int) it.next();			
			visited[1] = true;
			sum+=dfs_non(next);
			visited[1] = false;
		}

		it = list[1].iterator();
		int answer = sum;
		while(it.hasNext())
		{
			int next = (int) it.next();
			if(visited[next])
				continue;
			visited[1] = true;
			int temp = sum - dfs_non(next) + dfs_sel(next,value[1]);
			visited[1] = false;
			answer = Math.max(answer, temp);
		}
		bw.write(answer+"");
		bw.close();
	}
	public static int dfs_sel(int cur,int parent_v) //cur이 멘티로 선정되었다는거
	{
		//멘토 * 멘티 리턴, cur의 자식들은 다 non이어야함.
		if(list[cur].size() == 0)
			return dp_selected[cur] = parent_v*value[cur];
		if(dp_selected[cur] > 0)
			return dp_selected[cur];
		Iterator it = list[cur].iterator();
		int sum = 0;
		while(it.hasNext())
		{
			int next =(int) it.next();
			if(visited[next])
				continue;
			visited[cur] = true;
			sum+=dfs_non(next);
			visited[cur] = false;
		}
		return dp_selected[cur] = sum+parent_v*value[cur];
	}
	
	public static int dfs_non(int cur)
	{
		if(list[cur].size() == 0)
			return dp_nonselected[cur] = 0;
		if(dp_nonselected[cur] > 0)
			return dp_nonselected[cur];
		Iterator it = list[cur].iterator();
		int sum = 0;
		while(it.hasNext())
		{
			int next = (int) it.next();			
			visited[cur] = true;
			sum+=dfs_non(next);
			visited[cur] = false;			
		}		
		int v = sum;
		it = list[cur].iterator();
		while(it.hasNext())
		{
			int next = (int) it.next();			
			if(visited[next])
				continue;
			visited[cur] = true;
			int temp = sum - dp_nonselected[next] + dfs_sel(next,value[cur]);
			visited[cur] = false;
			v = Math.max(v, temp);
		}
		return dp_nonselected[cur] = v;
	}
}
