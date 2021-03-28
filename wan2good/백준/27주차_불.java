import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m;
	static char[][] board;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static int sx,sy;
	static boolean[][] visited;
	static boolean[][] visited2;
	static ArrayList<Pos> fire;
	static int answer=Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st;
    	
    	int t = Integer.parseInt(br.readLine());
    	while(t-->0) {
    		st = new StringTokenizer(br.readLine());
    		m = Integer.parseInt(st.nextToken());
    		n = Integer.parseInt(st.nextToken());
    		
    		fire = new ArrayList<>();
    		board = new char[n][m];
    		for(int i=0; i<n; i++) {
    			String input = br.readLine();
    			for(int j=0; j<m; j++) {
    				char cur = input.charAt(j);
    				if(cur=='@') {
    					sx=i; sy=j;
    					board[i][j] = '.';
    				}
    				else if(cur=='*') {
    					fire.add(new Pos(i,j));
    					board[i][j] = cur;
    				}
    				else {
    					board[i][j] = cur;
    				}
    			}
    		}
    		
    		bfs();
    		if(answer==Integer.MAX_VALUE) {
    			System.out.println("IMPOSSIBLE");
    		}
    		else
    			System.out.println(answer);
    		
    		answer = Integer.MAX_VALUE;
    	}
    	
    }
	private static void bfs() {
		Queue<Pos> fire_q = new LinkedList<>();
		Queue<Pos2> q = new LinkedList<>();
		
		visited = new boolean[n][m];
		visited2 = new boolean[n][m];
		for(Pos cur : fire) {
			fire_q.offer(cur);
		}
		
		q.offer(new Pos2(sx,sy,0));
		
		while(true) {
			int size = fire_q.size();
			for(int i=0; i<size; i++) {
				Pos cur = fire_q.poll();
				int x,y;
				x = cur.x;
				y = cur.y;
				int nx,ny;
				for(int idx=0; idx<4; idx++) {
					nx = x + dx[idx];
					ny = y + dy[idx];
					if(check(nx,ny) && board[nx][ny]!='#' && !visited[nx][ny]) {
						board[nx][ny]='*';
						visited[nx][ny]=true;
						fire_q.offer(new Pos(nx,ny));
					}
				}
			}
			
			int size2 = q.size();
			for(int i=0; i<size2; i++) {
				Pos2 cur2 = q.poll();
				int x2,y2,cnt=0;
				x2 = cur2.x;
				y2 = cur2.y;
				cnt= cur2.cnt;
				int nx2,ny2;
				for(int idx2=0; idx2<4; idx2++) {
					nx2 = x2+dx[idx2];
					ny2 = y2+dy[idx2];
					
					if(!check(nx2,ny2)) {
						answer = Math.min(answer, cnt+1);
						return;
					}
					if(board[nx2][ny2]=='.' && !visited2[nx2][ny2]) {
						q.offer(new Pos2(nx2,ny2,cnt+1));
						visited2[nx2][ny2]=true;
					}
				}
			}
			if(q.size()==0)
				return;
		}
	}
	
	private static boolean check(int nx, int ny) {
		if(0<=nx && nx<n && 0<=ny && ny<m)
			return true;
		return false;
	}
	
	static class Pos{
		int x,y;
		Pos(int x, int y){
			this.x=x;
			this.y=y;
		}
	}
	
	static class Pos2{
		int x,y,cnt;
		Pos2(int x,int y,int cnt){
			this.x=x;
			this.y=y;
			this.cnt=cnt;
		}
	}
}