package 트리dp;

import java.io.*;
import java.util.*;
public class 모두0으로만들기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] a= {-1,1};
		int[][] edges = {{0,1}};
		Solution.solution(a,edges);
		
	}

}

class Solution {
	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	static long[] check;
	static long count=0;
	static long answer=0;
    public static long solution(int[] a, int[][] edges) {
    	
        graph = new ArrayList[a.length];
        visited = new boolean[a.length];
        check = new long[a.length];
        for(int i=0; i<a.length; i++)
        	graph[i] = new ArrayList<>();
        for(int i=0; i<edges.length; i++)
        {
        	int from = edges[i][0];
        	int to = edges[i][1];
        	graph[from].add(to);
        	graph[to].add(from);
        }
        visited[0] = true;
        dfs(0,a);
        
        
        System.out.println(answer);
        return answer;
    }
    public static void dfs(int cur,int[] a)
    {
    	for(int i=0; i<graph[cur].size(); i++)
    	{
    		if(visited[graph[cur].get(i)]==false)
    		{
    			visited[graph[cur].get(i)]=true;
    			dfs(graph[cur].get(i),a);
    			check[cur] = check[cur]+check[graph[cur].get(i)];
    			answer = answer+Math.abs(check[graph[cur].get(i)]);

    				
    		}
    	}
    	check[cur] = check[cur]+a[cur];

    	if(cur==0)
    	{
    		if(check[cur]!=0)
    			answer=-1;

    	}

    	
    	
    	
    	
    }
	
	
}