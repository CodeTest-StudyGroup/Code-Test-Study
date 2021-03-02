import java.io.*;
import java.util.*;

public class Main {
    
	static int n,m;
	static ArrayList<Data>[] graph;
	static int[] result;
	static class Data{
		int next,cost;
		Data(int next,int cost){
			this.next=next;
			this.cost=cost;
		}
	}

	static class Node implements Comparable<Node>{
		int dist;
		int now;
		Node(int dist,int now){
			this.dist = dist;
			this.now = now;
		}
		@Override
		public int compareTo(Main.Node o) {
			// TODO Auto-generated method stub
			return this.dist-o.dist;
		}
	}
	
	public static void dijkstra() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.offer(new Node(0,1));
		int[] distance = new int[n+1];
		Arrays.fill(distance, Integer.MAX_VALUE);
		distance[1]=0;
		
		result = new int[n+1];
		
		int dist,now;
		while(!pq.isEmpty()) {
			Node tmp = pq.poll();
			dist = tmp.dist;
			now = tmp.now;
			
			if(distance[now]<dist)
				continue;
			
			int next,cost;
			for(Data nextNode : graph[now]) {
				next = nextNode.next;
				cost = nextNode.cost;
				int value = dist+cost;
				if(value<distance[next]) {
					distance[next]=value;
					pq.offer(new Node(value,next));
					result[next]=now;
				}	
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[n+1];
		for(int i=1; i<=n; i++)
			graph[i] = new ArrayList<>();
		
		int a,b,c;
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			graph[a].add(new Data(b,c));
			graph[b].add(new Data(a,c));
		}
		
		dijkstra();
		System.out.println(n-1);
		for(int i=2; i<=n; i++)
			System.out.println(i+" "+result[i]);
	}
}