import java.io.*;
import java.util.*;

public class Main {
   
	static int n,m;
	static int[][] board; static int[][] copy_board;
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static ArrayList<Pos> zeros = new ArrayList<>();
	static ArrayList<Integer> group = new ArrayList<>();
	static int group_num = 1,sum=1;
	static boolean[][] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	       
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		copy_board = new int[n][m];
		visited = new boolean[n][m];
		for(int i=0; i<n; i++) {
			String data = br.readLine();
			for(int j=0; j<m; j++) {
				int num = data.charAt(j)-'0';
				copy_board[i][j] = num;
				if(num==0) {
					zeros.add(new Pos(i,j));
					board[i][j]=0;
				}
				else if(num==1) {
					board[i][j]=9;
				}
			}
		}
		
		group.add(0);
		for(Pos zero : zeros) {
			if(board[zero.x][zero.y]==0) {
				board[zero.x][zero.y]=group_num;
				bfs(zero);
				group_num++;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(copy_board[i][j]==1) {
					Pos wall = new Pos(i,j);
					HashSet<Integer> set = new HashSet<>();
					sum=1;
					for(int idx=0; idx<4; idx++) {
						int nx = wall.x + dx[idx];
						int ny = wall.y + dy[idx];
						if(check(nx,ny)) {
							if(copy_board[nx][ny]!=1 && !set.contains(board[nx][ny])) {
								set.add(board[nx][ny]);
								sum+=group.get(board[nx][ny]);
							}
						}
					}
					sb.append(sum%10);
				}
				else {
					sb.append(0);
				}
			}
			sb.append('\n');
		}
		System.out.println(sb.toString());
	}
	
	private static void bfs(Pos zero) {
		Queue<Pos> q = new LinkedList<>();
		q.offer(zero);
		visited[zero.x][zero.y]=true;
		
		int cnt=1;
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			int x,y;
			x = cur.x;
			y = cur.y;
			for(int idx=0; idx<4; idx++) {
				int nx = x+dx[idx];
				int ny = y+dy[idx];
				if(check(nx,ny) && board[nx][ny]==0 && !visited[nx][ny]) {
					visited[nx][ny]=true;
					q.offer(new Pos(nx,ny));
					board[nx][ny]=group_num;
					cnt++;
				}
			}
		}
		group.add(cnt);
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
}