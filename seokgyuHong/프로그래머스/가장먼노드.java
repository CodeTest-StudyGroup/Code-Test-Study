package 그래프;

import java.util.*;
public class 가장먼노드 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

			int n = 6;
			int[][] vertex = {{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
		Solution.solution(n, vertex);
	}

}

class Solution {
	static ArrayList<Integer>[] graph;
	static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static int solution(int n, int[][] edge) {
        int answer = 0;
        
        graph = new ArrayList[n+1];
        
        for(int i=1; i<=n; i++)
        	graph[i] = new ArrayList<>();
        
        for(int[] arr : edge)
        {
        	graph[arr[0]].add(arr[1]);
        	graph[arr[1]].add(arr[0]);
        }

        
        int[] distance = new int[n+1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[1] = 0;
        pq.offer(new Node(1,0));
        
        
        while(!pq.isEmpty())
        {
        	Node cur = pq.poll();
        	
        	if(distance[cur.x]<cur.weight)
        		continue;
        	
        	for(int i : graph[cur.x])
        	{
        		if(distance[i]>cur.weight+1)
        		{
        			distance[i] = cur.weight+1;
        			pq.offer(new Node(i, cur.weight+1));
        		}
        	}
        }
        
        int max = -1;
        for(int i=1; i<=n; i++)
        	if(distance[i]>max) max=distance[i];
        
        for(int i=1; i<=n; i++)
        	if(distance[i]==max) answer++;
        
        
        return answer;
        
        
        
    }
}


class Node implements Comparable<Node>{
	int x;
	int weight;
	public Node(int x, int weight)
	{
		this.x = x;
		this.weight = weight;
	}
	
	@Override
	public int compareTo(Node o)
	{
		return this.weight-o.weight;
		
	}
	
	
}