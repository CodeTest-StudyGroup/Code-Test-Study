import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static int[][] board,dp;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static int ans = Integer.MIN_VALUE;
	
	static PriorityQueue<Data> pq = new PriorityQueue<>();
	
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st ;
    	
    	n = Integer.parseInt(br.readLine());
    	board = new int[n][n];
    	dp = new int[n][n];
    	
    	for(int i=0; i<n; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=0; j<n; j++) {
    			int num = Integer.parseInt(st.nextToken()); 
    			board[i][j] = num;
    			dp[i][j] = -1;
    			pq.offer(new Data(i,j,num));
    		}
    	}
    	
    	solve();
    	System.out.println(ans);
    	
	}
	
	private static void solve() {
		while(!pq.isEmpty()) {
			Data cur = pq.poll();
			int x = cur.x;
			int y = cur.y;
			ans = Math.max(dfs(x,y), ans);
		}
	}
	
	private static int dfs(int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        dp[x][y] = 1;
 
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(check(nx,ny)) {
            	if (board[x][y] > board[nx][ny]) {
                    dp[x][y] = Math.max(dp[x][y], dfs(nx,ny)+1);
                }
            }
        }
        return dp[x][y];
	}
	
	private static boolean check(int nx, int ny) {
		if(0<=nx && nx<n && 0<=ny && ny<n)
			return true;
		return false;
	}
	
	static class Data implements Comparable<Data>{
		int x,y,cnt;
		Data(int x,int y,int cnt){
			this.x=x;
			this.y=y;
			this.cnt=cnt;
		}
		
		@Override
		public int compareTo(Main.Data o) {
			return o.cnt-this.cnt;
		}
	}
}