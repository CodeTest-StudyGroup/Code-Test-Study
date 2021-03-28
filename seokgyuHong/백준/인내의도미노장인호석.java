package 구현;
import java.io.*;
import java.util.*;
public class 인내의도미노장인호석 {
	static boolean[][] check;
	static int[][] map;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static char[] dir_arr = {'N','E','S','W'};
	static int n;
	static int m;
	static int answer=0;
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		 n = Integer.parseInt(st.nextToken());
		 m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		 
		check = new boolean[n+1][m+1];
		map = new int[n+1][m+1];
		for(int i=1; i<=n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=m; j++)
			{
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	
		for(int k=1; k<=r; k++)
		{
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			char dir = st.nextToken().charAt(0);
			attack(x,y,dir);
			st = new StringTokenizer(br.readLine());
			int def_x = Integer.parseInt(st.nextToken());
			int def_y = Integer.parseInt(st.nextToken());
			defense(def_x,def_y);
		}
		System.out.println(answer);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(check[i][j])
					System.out.print("F"+" ");
				else
					System.out.print("S"+" ");
			}
			System.out.println();
		}
		
	}
	static void defense(int x, int y)
	{
		if(check[x][y])
		{
			check[x][y]=false;
		}
		
	}
	static void attack(int x, int y, char dir)
	{
		if(check[x][y]) //이미 넘어졌다면
			return;
		int idx=0;
		for(int i=0; i<dir_arr.length; i++)
		{
			if(dir==dir_arr[i]) 
			{
				idx=i;
				break;
			}
		
		}
		int length = map[x][y];
		check[x][y]=true;
		answer++;
		length--;
		if(length<0)
			return;
		while(true)
		{
			int dir_x = x+dx[idx]; //밑에서 변경 해줘야함 
			int dir_y = y+dy[idx];
			length--;
			if(length<0)
				break;
			if(dir_x<1 || dir_x>n | dir_y<1 || dir_y>m)
				break;
			if(!check[dir_x][dir_y])
			{
				check[dir_x][dir_y]=true;
				answer++;
				if(map[dir_x][dir_y]-1>length)
					length =map[dir_x][dir_y]-1;
			}

			x = dir_x;
			y = dir_y;
			
			
		}
		
	}
}
