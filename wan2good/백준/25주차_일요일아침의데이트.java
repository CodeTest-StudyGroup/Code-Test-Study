import java.io.*;
import java.util.*;

public class Main {
	
	static int sx,ex,sy,ey;
	static int n,m;
	static char[][] board;
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static int[] result = new int[2];
	
	static class Node implements Comparable<Node>{
		int x,y,on_trash,side_trash;
		Node(int x, int y,int on_trash, int side_trash){
			this.x = x;
			this.y = y;
			this.on_trash = on_trash;
			this.side_trash = side_trash;
		}
		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			if(this.on_trash == o.on_trash)
				return this.side_trash-o.side_trash;
			return this.on_trash - o.on_trash;
		}
	}
	
	public static void bfs() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[][] visited = new boolean[n][m];
		for(int i=0; i<n; i++)
			Arrays.fill(visited[i], false);
		
		pq.offer(new Node(sx,sy,0,0));
		visited[sx][sy]=true;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			int x,y,on_trash,side_trash;
			x = cur.x;
			y = cur.y;
			on_trash = cur.on_trash;
			side_trash = cur.side_trash;
			
			if(x==ex && y==ey)
			{
				result[0] = on_trash;
				result[1] = side_trash;
				return;
			}
			
			int nx,ny,non_trash,nside_trash;
			for(int idx=0; idx<4; idx++) {
				nx = x+dx[idx];
				ny = y+dy[idx];
				non_trash = on_trash;
				nside_trash = side_trash;
				if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]) {
					if(board[nx][ny]=='g')
						non_trash++;
					if(board[nx][ny]=='q')
						nside_trash++;
					visited[nx][ny]=true;
					pq.offer(new Node(nx,ny,non_trash,nside_trash));
				}
			}
		}
	}
	
	public static void set_side(ArrayList<int[]> trash) {
		for(int i=0; i<trash.size(); i++) {
			int[] tmp =trash.get(i); 
			int x,y;
			x=tmp[0]; y=tmp[1];
			int nx,ny;
			for(int idx=0; idx<4; idx++) {
				nx=x+dx[idx];
				ny=y+dy[idx];
				if(0<=nx && nx<n && 0<=ny && ny<m && board[nx][ny]=='.')
					board[nx][ny]='q';
			}
			
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		ArrayList<int[]> trash = new ArrayList<>();
		board = new char[n][m];
		for(int i=0; i<n; i++) {
			String data = br.readLine();
			for(int j=0; j<m; j++) {
				char tmp = data.charAt(j);
				board[i][j] = tmp;
				if(tmp=='S') {
					sx=i; sy=j;
				}
				if(tmp=='F') {
					ex=i; ey=j;
				}
				if(tmp=='g') {
					trash.add(new int[]{i,j});
				}
				
			}
		}
		
		set_side(trash);
		bfs();
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<2; i++)
			sb.append(result[i]+" ");
		
		System.out.println(sb.toString());
	}
}