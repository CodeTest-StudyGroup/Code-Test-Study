import java.io.*;
import java.util.*;

class Main {
	
	static int[][] distance;
	
	public static void main(String[] args) throws IOException{	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			distance = new int[n+1][n+1];
			for(int i=1; i<=n; i++) {
				Arrays.fill(distance[i], 987654321);
				distance[i][i] = 0;
			}
			
			for(int i=0; i<m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				distance[a][b]=c;
				distance[b][a]=c;
			}
			
			int K = Integer.parseInt(br.readLine());
			int people[] = new int[K];
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<K; i++) {
				people[i] = Integer.parseInt(st.nextToken());
			}
			
			for(int k=1; k<=n; k++) {
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=n; j++) {
						distance[i][j] = Math.min(distance[i][j], distance[i][k]+distance[k][j]);
					}
				}
			}
			int answer = Integer.MAX_VALUE;
			int node=0;
			for(int i=1; i<=n; i++) {
				int sum = 0;
				for(int j=0; j<K; j++) {
					sum+=distance[people[j]][i];
				}
				if(answer > sum) {
					answer = sum;
					node= i;
				}
			}
			System.out.println(node);
		}
	}
}