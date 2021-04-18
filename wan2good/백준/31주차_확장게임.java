import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m,p;
	static char[][] board;
	static int[] s, result;
	static int[] dx = {-1,0,1,0}; static int[] dy = {0,-1,0,1};
	static Queue<Pos>[] list;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		
		s = new int[p+1];
		result = new int[p+1];
		board = new char[n][m];
		list = new LinkedList[p+1];
		
		for(int i=1; i<=p; i++)
			list[i] = new LinkedList<>();
		
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=p; i++) {
			s[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<n; i++) {
			String input = br.readLine();
			for(int j=0; j<m; j++) {
				char ch = input.charAt(j);
				if('0'<=ch && ch<='9') {
					list[ch-'0'].add(new Pos(i,j,ch));
					result[ch-'0']++;
				}
				board[i][j] = ch;
			}
		}
		
		bfs();
		StringBuilder sb = new StringBuilder();
		for(int i=1; i<=p; i++)
			sb.append(result[i]).append(" ");
		System.out.println(sb.toString());
	}
	
	private static void bfs() {
		while(true) {
			for(int i=1; i<=p; i++) {
				int cost=0;
				while(list[i].size()>0) {
					int size=list[i].size();
					while(size-->0) {
						Pos cur = list[i].poll();
						int x = cur.x;
						int y = cur.y;
						char num = cur.num;
						for(int idx=0; idx<4; idx++) {
							int nx = x + dx[idx];
							int ny = y + dy[idx];
							if(check(nx,ny) && board[nx][ny]=='.') {
								result[i]++;
								list[i].add(new Pos(nx,ny,num));
								board[nx][ny]=num;
							}
						}
					}
					cost++;
					if(cost==s[i])
						break;
				}
			}
			boolean flag=false;
			for(int i=1; i<=p; i++) {
				if(list[i].size()>0)
					flag=true;
			}
			if(!flag)
				break;
		}	
	}
	
	private static boolean check(int nx, int ny) {
		if(0<=nx && nx<n && 0<=ny && ny<m)
			return true;
		return false;
	}
	
	static class Pos{
		int x,y;
		char num;
		Pos(int x, int y,char num){
			this.x=x;
			this.y=y;
			this.num = num;
		}
	}
}