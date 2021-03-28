import java.io.*;
import java.util.*;

public class Main {

	static int[][] board = new int[3][3];
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static HashMap<String, Integer> map = new HashMap<>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<3 ;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				sb.append(st.nextToken());
			}
		}
		String num = sb.toString();
		map.put(num, 0);
		bfs(num);
		
		if(!map.containsKey("123456780")) {
			System.out.println(-1);
		}
		else
			System.out.println(map.get("123456780"));
	}
	
	private static void bfs(String num) {
		Queue<String> q = new LinkedList<>();
		q.offer(num);
		
		StringBuffer sb;
		while(!q.isEmpty()) {
			String cur = q.poll();
			int idx = cur.indexOf("0");
			int row = idx/3;
			int col = idx%3;
			
			int nx,ny;
			for(int i=0; i<4; i++) {
				nx = row + dx[i];
				ny = col + dy[i];
				sb = new StringBuffer(cur);
				if(check(nx,ny)) {
					char tmp = sb.toString().charAt(nx*3+ny);
					sb.setCharAt(nx*3+ny, '0');
					sb.setCharAt(idx, tmp);
				}
				else
					continue;
				
				if(!map.containsKey(sb.toString())) {
					map.put(sb.toString(), map.get(cur)+1);
					q.offer(sb.toString());
				}
			}
		}
	}
	
	private static boolean check(int nx, int ny) {
		if(0<=nx && nx<3 && 0<=ny && ny<3)
			return true;
		return false;
	}
	
	
}