package 다익스트라;
import java.io.*;
import java.util.*;

public class 네트워크복구 {
	static int n;
	static int m;
	static int[] distance;
	static class Node implements Comparable<Node>
	{
		int weight;
		int to;

		
		public Node(int to,int weight) {
			// TODO Auto-generated constructor stub
			this.weight = weight;
			this.to = to;
		}


		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			return this.weight-o.weight;
		}
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		st = new StringTokenizer(br.readLine());

		int INF = 987654321;

		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<Node>[] graph = new ArrayList[n+1];
		for(int i=0; i<=n; i++)
			graph[i] = new ArrayList<Node>();
		for(int i=0; i<m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			graph[a].add(new Node(b,weight));
			graph[b].add(new Node(a,weight));
		}
		
		distance = new int[n+1];
		for(int i=1; i<=n; i++)
			distance[i] = INF;
		
		distance[1] = 0;
		pq.offer(new Node(1,0));
		int[] arr = new int[n+1];
		for(int i=1; i<=n; i++)
			arr[i] = i;
		while(!pq.isEmpty())
		{
			Node temp = pq.poll();
			int weight=temp.weight;
			int idx = temp.to;
			
			for(int i=0; i<graph[idx].size(); i++)
			{
				if(distance[graph[idx].get(i).to]>weight+graph[idx].get(i).weight)
				{
					distance[graph[idx].get(i).to]=weight+graph[idx].get(i).weight;
					pq.offer(new Node(graph[idx].get(i).to,distance[graph[idx].get(i).to]));
					arr[graph[idx].get(i).to] = idx;
				}
				
			}
		}
		sb.append(n-1);
		sb.append("\n");
		for(int i=2; i<=n; i++)
		{
			sb.append(i);
			sb.append(" ");
			sb.append(arr[i]);
			sb.append("\n");
		}
		System.out.println(sb);
	
	}


	

}
