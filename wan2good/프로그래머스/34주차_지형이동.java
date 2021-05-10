import java.util.*;

class Solution {
	static int n,m;
	static int[][] visited;
	static int[] parent;
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static Queue<Pos> q = new LinkedList<>();
	
    public int solution(int[][] land, int height) {
        int answer = 0;
        n = land.length; m = land[0].length;
        visited = new int[n][m];
        
        int component=1;
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(visited[i][j]==0) {
        			q.offer(new Pos(i,j));
        			visited[i][j] = component;
        			while(!q.isEmpty()) {
        				Pos cur = q.poll();
        				int x = cur.x;
        				int y = cur.y;
        				for(int idx=0; idx<4; idx++) {
        					int nx = x + dx[idx];
        					int ny = y + dy[idx];
        					if(check(nx,ny) && Math.abs(land[nx][ny]-land[x][y])<=height && visited[nx][ny]==0) {
        						visited[nx][ny] = component;
        						q.offer(new Pos(nx,ny));
        					}
        				}
        			}
        			component++;
        		}
        	}
        }
        
        component--;
        
        ArrayList<Data> edges = new ArrayList<>();
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		for(int idx=0; idx<4; idx++) {
        			int nx = i + dx[idx];
        			int ny = j + dy[idx];
        			if(check(nx,ny) && visited[i][j]!=visited[nx][ny]) {
        				int dist = Math.abs(land[nx][ny] - land[i][j]);
        				edges.add(new Data(visited[i][j],visited[nx][ny],dist));
        			}
        			
        		}
        	}
        }
        
        Collections.sort(edges, new Comparator<Data>() {
        	@Override
        	public int compare(Solution.Data a, Solution.Data b) {
        		return a.cost - b.cost;
        	}
        });
        
        parent = new int[component+1];
        for(int i=1; i<=component; i++)
        	parent[i] = i;
        
        int cnt=0;
        for(Data edge : edges) {
        	int a = edge.a;
        	int b = edge.b;
        	int cost = edge.cost;
        	if(find(a)!=find(b)) {
        		union(a,b);
        		answer+=cost;
        		cnt++;
        	}
        	if(cnt==component-1)
        		break;
        }
        
        return answer;
    }
    
    public void union(int a, int b) {
    	int x = find(a);
    	int y = find(b);
    	if(x<y)
    		parent[y] = x;
    	else
    		parent[x] = y;
    }
    
    public int find(int a) {
    	if(a!=parent[a])
    		parent[a] = find(parent[a]);
    	return parent[a];
    }
    
    public boolean check(int nx, int ny) {
    	if(0<=nx && nx<n && 0<=ny && ny<m)
    		return true;
    	return false;
    }
    
    static class Data{
    	int a,b,cost;
    	Data(int a, int b, int cost)
    	{
    		this.a=a;
    		this.b=b;
    		this.cost=cost;
    	}
    }
    
    static class Pos{
    	int x,y;
    	Pos(int x, int y){
    		this.x=x;
    		this.y=y;
    	}
    }
}

public class Main {	
	public static void main(String[] args){
		int[][] land = {
				{1,4,8,10},
				{5,5,5,5},
				{10,10,10,10},
				{10,10,10,20}
		};
		
		int height = 3;
		System.out.println(new Solution().solution(land,height));
	}
	
}