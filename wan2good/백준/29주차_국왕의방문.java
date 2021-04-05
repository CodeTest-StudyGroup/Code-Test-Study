import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m;
	static int a,b,k,g;
	static int[] king;
	static int[][] map;
	static int[][] start_king_distance;
	static int[][] end_king_distance;
	static ArrayList<Data>[] graph;
	static PriorityQueue<Data> pq;
	
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	
    	map = new int[n+1][n+1];
    	graph = new ArrayList[n+1];
    	for(int i=1; i<=n; i++) {
    		graph[i] = new ArrayList<>();
    	}
    	
    	st = new StringTokenizer(br.readLine());
    	a = Integer.parseInt(st.nextToken());
    	b = Integer.parseInt(st.nextToken());
    	k = Integer.parseInt(st.nextToken());
    	g = Integer.parseInt(st.nextToken());
    	
    	king = new int[g];
    	st = new StringTokenizer(br.readLine());
    	for(int i=0; i<g; i++) {
    		king[i] = Integer.parseInt(st.nextToken());
    	}
    	
    	for(int i=0; i<m; i++) {
    		st = new StringTokenizer(br.readLine());
    		int u = Integer.parseInt(st.nextToken());
    		int v = Integer.parseInt(st.nextToken());
    		int l = Integer.parseInt(st.nextToken());
    		
    		graph[u].add(new Data(v,l));
    		graph[v].add(new Data(u,l));
    		map[u][v] = l;
    		map[v][u] = l;
    	}
    	
    	start_king_distance = new int[n+1][n+1];
    	end_king_distance = new int[n+1][n+1];
    	int king_dist = 0;
    	for(int i=0; i<g-1; i++) {
    		start_king_distance[king[i]][king[i+1]] = king_dist;
    		end_king_distance[king[i]][king[i+1]] = king_dist + map[king[i]][king[i+1]];
    		
    		start_king_distance[king[i+1]][king[i]] = king_dist;
    		end_king_distance[king[i+1]][king[i]] = king_dist + map[king[i]][king[i+1]];
    		king_dist += map[king[i]][king[i+1]];
    	}
    	
    	
    	pq = new PriorityQueue<>((a,b) -> a.cost - b.cost);
    	int[] result = dijkstra(a);
    	System.out.println(result[b]-k);
	}
	
	private static int[] dijkstra(int start) {
		int[] distance = new int[n+1];
		Arrays.fill(distance, 987654321);
		pq.offer(new Data(a,k));
		distance[start]=k;
		while(!pq.isEmpty()) {
			Data cur = pq.poll();
			int now = cur.cur;
			int dist = cur.cost;
			
			if(dist > distance[now])
				continue;
			
			for(Data next : graph[now]) {
				int cost = dist+next.cost;
				if(start_king_distance[now][next.cur]<=dist && dist<end_king_distance[now][next.cur]) {
					cost += end_king_distance[now][next.cur]-dist;
				}
				
				if(cost < distance[next.cur]) {
					distance[next.cur] = cost;
					pq.offer(new Data(next.cur, cost));
				}
			}
		}
		
		return distance;
	}
	
	static class Data{
		int cur,cost;
		Data(int cur, int cost){
			this.cur = cur;
			this.cost = cost;
		}
	}
}