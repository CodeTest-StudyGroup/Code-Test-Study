import java.util.*;

class Data implements Comparable<Data>{
	int b,cost;
	Data(int b, int cost){
		this.b=b;
		this.cost = cost;
	}
	
	@Override
	public int compareTo(Data o) {
		return this.cost - o.cost;
	}
}

class Solution {
	
	static ArrayList<Data>[] graph;
	
    public int solution(int n, int[][] edge) {
        int answer = 0;
        graph = new ArrayList[n+1];
        for(int i=1; i<=n; i++) graph[i] = new ArrayList<>();
        
        for(int[] row : edge) {
        	int a = row[0];
        	int b = row[1];
        	graph[a].add(new Data(b,1));
        	graph[b].add(new Data(a,1));
        }
        
        answer = dijkstra(n,1);
        
        return answer;
    }
    
    public int dijkstra(int n,int start) {
    	PriorityQueue<Data> pq = new PriorityQueue<>();
    	int[] distance = new int[n+1];
    	Arrays.fill(distance, Integer.MAX_VALUE);
    	
    	distance[start] = 0;
    	pq.offer(new Data(1,0));
    	while(!pq.isEmpty()) {
    		Data cur = pq.poll();
    		int dist = cur.cost;
    		int now = cur.b;
    		if(dist < distance[now])
    			continue;
    		
    		for(Data next : graph[now]) {
    			int cost = dist + next.cost;
    			if(cost < distance[next.b]) {
    				distance[next.b]= cost;
    				pq.offer(new Data(next.b,cost));
    			}
    		}
    	}
    	
    	int maxValue = Integer.MIN_VALUE;
    	for(int i=1; i<=n; i++) {
    		maxValue = Math.max(maxValue, distance[i]);
    	}
    	
    	int cnt=0;
    	for(int i=1; i<=n; i++)
    		if(distance[i]==maxValue) cnt++;
    	return cnt;
    }
}

public class Main {	
	public static void main(String[] args){
		int n = 6;
		int[][] edge = {
				{3,6},
				{4,3},
				{3,2},
				{1,3},
				{1,2},
				{2,4},
				{5,2}
		};
	}
	
}