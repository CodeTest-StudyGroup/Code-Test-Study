package 냅색디피;

import java.io.*;
import java.util.*;
public class 할로윈의양아치 {

	static int n;
	static int m;
	static int k;
	static boolean[] check;
	static int[] arr;
	static ArrayList<Integer>[] friend;
	static int size;
	static int candy;
	static class Node{
		int count;
		int total;
		public Node(int count, int total)
		{
			this.count = count;
			this.total = total;
		}
		@Override
		public String toString()
		{
			return this.count + " " + this.total;
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[n+1];
		check = new boolean[n+1];
		friend = new ArrayList[n+1];
		Queue<Node> queue = new LinkedList<Node>();
		int answer_temp=0;
		int cnt=0;
		ArrayList<Node> total_list = new ArrayList<>();
		for(int i=1; i<=n; i++)
		{
			friend[i] = new ArrayList<>();
		}
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++)
		{
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=1; i<=m; i++)
		{
			st= new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			friend[a].add(b);
			friend[b].add(a);
		}
		for(int i=1; i<=n; i++)
		{
			if(!check[i])
			{
				size=0;
				candy=0;
				check[i]=true;
				size++;
				candy+=arr[i];
				dfs(i);
				total_list.add(new Node(size,candy));

			}
		}
//
//		total_list.sort((a1,a2)->{if(a1.count<a2.count) return -1;
//		else if(a1.count==a2.count)
//			return a1.total-a2.total;
//		else
//			return 1;});

		int answer=0;
		int[][] dp = new int[total_list.size()+1][k];
		dp[0][0] = 0;
		for(int i=1; i<=total_list.size(); i++)
		{
			for(int j=1; j<k; j++)
			{
				if(j-total_list.get(i-1).count>=0)
				{
					dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-total_list.get(i-1).count]+total_list.get(i-1).total);
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		System.out.println(dp[total_list.size()][k-1]);
		for(int i=1; i<dp.length; i++)
		{
			for(int j=1; j<dp[i].length; j++)
				System.out.print(dp[i][j]+" ");
			System.out.println("\n");
		}
	}
	static void dfs(int cur)
	{
		for(int i=0; i<friend[cur].size(); i++)
		{
			if(!check[friend[cur].get(i)])
			{
				check[friend[cur].get(i)]=true;
				size++;
				candy+=arr[friend[cur].get(i)];
				dfs(friend[cur].get(i));
			}
		}
		
	}

}
