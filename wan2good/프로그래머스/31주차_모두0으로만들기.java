import java.util.*;

class Solution {
    public static long solution(int[] a, int[][] edges) {
        long answer = 0;
        long sum = 0;
        long[] cost = new long[a.length];
        
        for(int i=0; i<a.length; i++) {
        	sum+=a[i];
        	cost[i] = a[i];
        }
        
        if(sum!=0)
        	return -1;
        
        int[] indegree = new int[a.length];
        boolean[] visited = new boolean[a.length];
        ArrayList<Integer>[] graph = new ArrayList[a.length];
        for(int i=0; i<a.length; i++) {
        	graph[i] = new ArrayList<>();
        }
        
        for(int[] edge : edges) {
        	graph[edge[0]].add(edge[1]);
        	graph[edge[1]].add(edge[0]);
        	indegree[edge[0]]++;
        	indegree[edge[1]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<a.length; i++) {
        	if(indegree[i]==1)
        		q.offer(i);
        }
        
        while(!q.isEmpty()) {
        	int cur = q.poll();
        	visited[cur] = true;
        	
        	for(int parent : graph[cur]) {
        		if(!visited[parent]) {
        			answer += Math.abs(cost[cur]);
        			cost[parent]+=cost[cur];
        			cost[cur]=0;
        			if(--indegree[parent]==1)
        				q.offer(parent);
        		}
        	}
        }
        
        return answer;
    }
}

public class Main {
	public static void main(String[] args){
		
		Solution solution = new Solution();
		int[] a = {-5,0,2,1,2};
		int[][] edges = {{0,1},{3,4},{2,3},{0,3}};
		System.out.println(solution.solution(a, edges));
		
	}
}