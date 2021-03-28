import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m,r;
	static int[][] board;
	static int[][] copy_board;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static int point;
	
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	r = Integer.parseInt(st.nextToken());
    	
    	board = new int[n+1][m+1];
    	copy_board = new int[n+1][m+1];
    	for(int i=1; i<=n; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=1; j<=m; j++) {
    			int num = Integer.parseInt(st.nextToken());
    			board[i][j] = num;
    			copy_board[i][j] = num;
    		}
    	}
    	
    	int row,col;
    	String dir;
    	for(int i=0; i<r; i++) {
    		st = new StringTokenizer(br.readLine());
    		row = Integer.parseInt(st.nextToken());
    		col = Integer.parseInt(st.nextToken());
    		dir = st.nextToken();
    		
    		attack(row,col,dir);
    		
    		st = new StringTokenizer(br.readLine());
    		row = Integer.parseInt(st.nextToken());
    		col = Integer.parseInt(st.nextToken());
    		
    		defence(row,col);
    	}
    	
    	StringBuilder sb = new StringBuilder();
    	sb.append(point).append('\n');
    	for(int i=1; i<=n; i++) {
    		for(int j=1; j<=m; j++) {
    			if(copy_board[i][j]!=-9)
    				sb.append('S').append(" ");
    			else
    				sb.append('F').append(" ");
    		}
    		sb.append('\n');
    	}
    	
    	System.out.println(sb.toString());
	}
	
	private static void attack(int row,int col,String dir) {
		int start_x=row;
		int start_y=col;
		int cnt;
		switch (dir) {
		case "N":
			cnt=copy_board[start_x][start_y];
			if(cnt==-9)
				return;
			while(cnt>0) {
				cnt = Math.max(copy_board[start_x][start_y], cnt);
				if(copy_board[start_x][start_y]==-9) {
					cnt--;
					start_x--;
					if(start_x<1)
						return;
				}
				else {
					copy_board[start_x][start_y]=-9;
					point++;
					cnt--;
					start_x--;
					if(start_x<1)
						return;
				}
			}
			break;
		case "W":
			cnt=copy_board[start_x][start_y];
			if(cnt==-9)
				return;
			while(cnt>0) {
				cnt = Math.max(copy_board[start_x][start_y], cnt);
				if(copy_board[start_x][start_y]==-9) {
					cnt--;
					start_y--;
					if(start_y<1)
						return;
				}
				else {
					copy_board[start_x][start_y]=-9;
					point++;
					cnt--;
					start_y--;
					if(start_y<1)
						return;
				}
			}
			break;
		case "S":
			cnt=copy_board[start_x][start_y];
			if(cnt==-9)
				return;
			while(cnt>0) {
				cnt = Math.max(copy_board[start_x][start_y], cnt);
				if(copy_board[start_x][start_y]==-9) {
					start_x++;
					cnt--;
					if(start_x>n)
						return;
				}
				else {
					copy_board[start_x][start_y]=-9;
					point++;
					cnt--;
					start_x++;
					if(start_x>n)
						return;
				}
				
			}
			break;
		case "E":
			cnt=copy_board[start_x][start_y];
			if(cnt==-9)
				return;
			while(cnt>0) {
				cnt = Math.max(copy_board[start_x][start_y], cnt);
				if(copy_board[start_x][start_y]==-9) {
					start_y++;
					cnt--;
					if(start_y>m)
						return;
				}
				else {
					copy_board[start_x][start_y]=-9;
					point++;
					cnt--;
					start_y++;
					if(start_y>m)
						return;
				}
			}
			break;
		}
	}
	
	private static void defence(int row, int col)
	{
		copy_board[row][col] = (char)board[row][col];
	}
}