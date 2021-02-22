
import java.util.*;
import java.io.*;

public class Main {
	
	static int m,n;
	static int[][] board;
	static int[] dx = {0,0,0,1,-1}; static int[] dy = {0,1,-1,0,0};
	static boolean[][][] visited;
	static int sx,sy,sDir; static int ex,ey,eDir;
	static class Data{
		int x,y,dir,cnt;
		Data(int x,int y,int dir,int cnt){
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.cnt = cnt;
		}
	}
	
	public static int bfs() {
		Queue<Data> q = new LinkedList<>();
		q.offer(new Data(sx,sy,sDir,0));
		visited = new boolean[5][n+1][m+1];
		int res=-1;
		int x,y,cDir,cur;
		int nx,ny,nDir;
		while(!q.isEmpty()) {
			Data tmp = q.poll();
			x = tmp.x; y = tmp.y; cDir = tmp.dir; cur = tmp.cnt; 
			if(x==ex && y==ey && cDir==eDir) {
				res=cur;
				break;
			}
			
			for(int k=1; k<=3; k++) {
				nx = x + dx[cDir]*k;
				ny = y + dy[cDir]*k;
				
				if(nx<1 || nx>n || ny<1 || ny>m)
					continue;
				
				if(board[nx][ny]==0){
					if(!visited[cDir][nx][ny]) {
						visited[cDir][nx][ny]=true;
						q.offer(new Data(nx,ny,cDir,cur+1));
					}
				}
				else
					break;
			}
			
			for(int idx=1; idx<=4; idx++) {
				if(cDir!=idx && !visited[idx][x][y]) {
					if((cDir==1 && idx==2) || (cDir==2 && idx==1) || (cDir==3 && idx==4) || (cDir==4 && idx==3))
						q.offer(new Data(x,y,idx,cur+2));
					else
						q.offer(new Data(x,y,idx,cur+1));
					visited[idx][x][y]=true;
				}
			}
		}
		return res;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		board = new int[n+1][m+1];
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				board[i][j+1]=Integer.parseInt(st.nextToken());
			}
		}
		
		st = new StringTokenizer(br.readLine());
		sx = Integer.parseInt(st.nextToken());
		sy = Integer.parseInt(st.nextToken());
		sDir = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		ex = Integer.parseInt(st.nextToken());
		ey = Integer.parseInt(st.nextToken());
		eDir = Integer.parseInt(st.nextToken());
		
		System.out.println(bfs());
	}
}
