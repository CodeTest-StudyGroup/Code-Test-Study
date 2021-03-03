import java.io.*;
import java.util.*;

public class Main {
    
	static int n;
	static class Pos{
		int x,y;
		Pos(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		Pos[] pos = new Pos[n];
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			pos[i] = new Pos(x,y);
		}
		
		int min = Integer.MAX_VALUE;
		int mini = 0;
		for(int i=0; i<n; i++) {
			int max = Integer.MIN_VALUE;
			int maxi = i;
			for(int j=0; j<n; j++) {
				if(i==j)
					continue;
				if(max<( (pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y) )){
					max = (pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y) ;
					maxi = i;
				}		
			}
			if(min>max)
			{
				min = max;
				mini = maxi;
			}
		}
		System.out.println(pos[mini].x+" "+pos[mini].y);
	}
}