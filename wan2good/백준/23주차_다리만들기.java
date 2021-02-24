import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static int[][] board;
	static boolean[][] visited;
	static class Pos{
		int x,y;
		Pos(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	static ArrayList<Pos>[] groups;
	
	public static int solve(int cnt) {
		int minV=Integer.MAX_VALUE;
		
		Pos groupI,groupJ;
		for(int i=0; i<cnt; i++) {
			for(int j=i+1; j<cnt; j++) {
				for(int x=0; x<groups[i].size(); x++) {
					for(int y=0; y<groups[j].size(); y++) {
						groupI = groups[i].get(x);
						groupJ = groups[j].get(y);
						minV = Math.min(minV,(Math.abs(groupI.x-groupJ.x)+Math.abs(groupI.y-groupJ.y))-1);
					}
				}
			}
		}
		return minV;
	}
	
	public static void bfs(int i,int j,int cnt) {
		Queue<Pos> q = new LinkedList<>();
		q.offer(new Pos(i,j));
		
		visited[i][j]=true;
		groups[cnt].add(new Pos(i,j));
		int x,y,nx,ny;
		while(!q.isEmpty()) {
			Pos tmp = q.poll();
			x=tmp.x; y=tmp.y;
			for(int idx=0; idx<4; idx++) {
				nx=x+dx[idx]; ny=y+dy[idx];
				if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny] && board[nx][ny]==1) {
					q.offer(new Pos(nx,ny));
					groups[cnt].add(new Pos(nx,ny));
					visited[nx][ny]=true;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		groups = new ArrayList[10001];
		for(int i=0; i<10001; i++) {
			groups[i] = new ArrayList<>();
		}
		
		board = new int[n][n];
		for(int i=0; i<n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		visited = new boolean[n][n];
		int cnt=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(board[i][j]==1 && !visited[i][j]) {
					bfs(i,j,cnt);
					cnt++;
				}
			}
		}
		
		System.out.println(solve(cnt));
		
	}

}
