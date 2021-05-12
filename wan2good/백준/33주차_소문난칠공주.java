import java.io.*;
import java.util.*;

class Pos{
	int x,y;
	
	Pos(int x, int y){
		this.x = x;
		this.y = y;
	}
}

class Main {
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static char[][] board;
	static boolean[] visited;
	static int ans = 0;
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		board = new char[5][5];
		for(int i=0; i<5; i++){
			String input = br.readLine();
			for(int j=0; j<5; j++){
				board[i][j] = input.charAt(j);
			}
		}
		visited = new boolean[25];
		comb(0, 0);
		System.out.println(ans);
	}

	private static void comb(int start, int depth){
		if(depth == 7){
			int[][] copyBoard = new int[5][5];
			int x=0,y=0;
			int cntS=0,cnt=0;
			boolean first = true;
			
			for(int i=0; i<25; i++){
				if(visited[i]){
					int row = i/5;
					int col = i%5;
					copyBoard[row][col] = 1;
					if(first) {
						x = row;
						y = col;
						first=false;
					}
				
					if(board[row][col]=='S')
						cntS++;
					cnt++;	
				}
				if(cnt==7)
					break;
			}

			if(cntS>=4 && bfs(x,y,copyBoard)){
				ans++;
			}
				
			return;
		}

		for(int i=start; i<25; i++){
			if(!visited[i]){
				visited[i] = true;
				comb(i+1, depth+1);
				visited[i] = false;
			}
		}
	}

	private static boolean bfs(int a, int b, int[][] copyBoard){
		Queue<Pos> q = new LinkedList<>();
		boolean[][] visited2 = new boolean[5][5];
		
		q.offer(new Pos(a,b));
		visited2[a][b] = true;
		
		int num=1;
		while(!q.isEmpty()){
			Pos cur = q.poll();
			int x = cur.x;
			int y = cur.y;

			for(int idx=0; idx<4; idx++){
				int nx = x + dx[idx];
				int ny = y + dy[idx];
				if(check(nx,ny) && copyBoard[nx][ny]==1 && !visited2[nx][ny]){
					q.offer(new Pos(nx, ny));
					visited2[nx][ny] = true;
					num++;
				}
			}
		}

		if(num == 7)
			return true;
		return false;
	}
	
	private static boolean check(int nx, int ny){
		if(0<=nx && nx<5 && 0<=ny && ny<5) 
			return true;
		return false;
	}
}