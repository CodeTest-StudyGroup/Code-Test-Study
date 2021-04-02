import java.util.*;
import java.io.*;

public class Main
{	
	static int n;
	static char[][] board;
	static Pos[] tree = new Pos[3];
	static Pos[] dest = new Pos[3];
	static Queue<Data> q = new LinkedList<>();
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static int ans;
	static boolean[][][] visited;
	
	public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new char[n][n];
        visited = new boolean[2][n][n];
        
        int tree_idx=0;
        int dest_idx=0;
        for(int i=0; i<n; i++) {
        	String input = br.readLine();
        	for(int j=0; j<n; j++) {
        		char ch = input.charAt(j);
        		if(ch=='B') {
        			tree[tree_idx++]=new Pos(i,j);
        			board[i][j]='0';
        		}
        			
        		else if(ch=='E') {
        			dest[dest_idx++]=new Pos(i,j);
        			board[i][j]='0';
        		}
        		else {
        			board[i][j]=ch;
        		}
        		
        	}
        }
        int cx = tree[1].x;
        int cy = tree[1].y;
        if(cy==tree[0].y) {
        	q.offer(new Data(tree[1],0,true)); // 세로
        	visited[1][tree[1].x][tree[1].y]=true;
        }
        else {
        	q.offer(new Data(tree[1],0,false)); // 가로
        	visited[0][tree[1].x][tree[1].y]=true;
        }
        bfs();
        System.out.println(ans);
    }
	
	private static void bfs() {
		while(!q.isEmpty()) {
			Data tmp = q.poll();
			Pos cur = tmp.pos;
			int cnt = tmp.cnt;
			boolean flag = tmp.flag;
			int idx=0;
			if(flag)
				idx=1;
			
			if(finish_check(cur,flag)) {
				ans=cnt;
				return;
			}
				
			for(int i=0; i<5; i++) {
				if(movePossible(cur,i,flag)) {
					if(i==4) {
						if(idx==1) {
							if(!visited[0][cur.x][cur.y]) {
								q.offer(new Data(cur,cnt+1,!flag));
								visited[0][cur.x][cur.y]=true;
							}
						}
						else {
							if(!visited[1][cur.x][cur.y]) {
								q.offer(new Data(cur,cnt+1,!flag));
								visited[1][cur.x][cur.y]=true;
							}
						}
						
					}
					else {
						int cx = cur.x;
						int cy = cur.y;
						int nx,ny;
						nx = cx+dx[i];
						ny = cy+dy[i];
						if(!visited[idx][nx][ny]) {
							q.offer(new Data(new Pos(nx,ny), cnt+1,flag));
							visited[idx][nx][ny]=true;
						}
					}
				}
			}
		}
	}

	private static boolean movePossible(Pos cur, int dir,boolean flag) {
		int cx,cy;
		cx = cur.x;
		cy = cur.y;
		
		if(dir==4) {
			int[] dx = {-1,-1,0,1,1,1,0,-1};
			int[] dy = {0,-1,-1,-1,0,1,1,1};
			int nx,ny;
			for(int i=0; i<8; i++) {
				nx = cx+dx[i];
				ny = cy+dy[i];
				if(check(nx,ny)) {
					if(board[nx][ny]=='1')
						return false;
				}
				else
					return false;
			}
		}
		else {
			int x1,y1,x2,y2;
			int nx1,ny1,nx2,ny2;
			int ncx,ncy;
			if(flag) {
				x1 = cx + dx[0]; y1 = cy + dy[0];
				x2 = cx + dx[2]; y2 = cy + dy[2];
				nx1 = x1 + dx[dir]; ny1 = y1 + dy[dir];
				ncx = cx + dx[dir]; ncy = cy + dy[dir];
				nx2 = x2 + dx[dir]; ny2 = y2 + dy[dir];
			}
			else {
				x1 = cx + dx[1]; y1 = cy + dy[1];
				x2 = cx + dx[3]; y2 = cy + dy[3];
				nx1 = x1 + dx[dir]; ny1 = y1 + dy[dir];
				ncx = cx + dx[dir]; ncy = cy + dy[dir];
				nx2 = x2 + dx[dir]; ny2 = y2 + dy[dir];
			}
			
			if(!check(nx1,ny1) || !check(ncx,ncy) || !check(nx2,ny2))
				return false;
		}
		return true;
	}
	
	private static boolean check(int nx, int ny) {
		if(0<=nx && nx<n && 0<=ny && ny<n) {
			if(board[nx][ny]!='1')
				return true;
		}
			
		return false;
	}
	
	private static boolean finish_check(Pos cur,boolean flag) {
		int cx = cur.x;
		int cy = cur.y;
		int nx1,ny1,nx2,ny2;
		
		if(flag) {
			nx1 = cx + dx[0]; ny1 = cy + dy[0];
			nx2 = cx + dx[2]; ny2 = cy + dy[2];
		}
		else {
			nx1 = cx + dx[1]; ny1 = cy + dy[1];
			nx2 = cx + dx[3]; ny2 = cy + dy[3];
		}
		
		if(nx1==dest[0].x && ny1==dest[0].y &&
				cx==dest[1].x && cy==dest[1].y &&
				nx2==dest[2].x && ny2==dest[2].y)
			return true;
		return false;
	}
}

class Pos{
	int x,y;
	Pos(int x,int y){
		this.x=x;
		this.y=y;
	}
}

class Data{
	Pos pos;
	int cnt;
	boolean flag;
	Data(Pos pos, int cnt, boolean flag) {
		this.pos = pos;
		this.cnt = cnt;
		this.flag = flag;
	}
}