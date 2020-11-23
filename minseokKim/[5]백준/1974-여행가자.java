import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][n];
		int INF = Integer.MAX_VALUE/2-1;
		for(int i = 0 ; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++)
			{
				int temp = Integer.parseInt(st.nextToken());
				if(temp == 1)	
					map[i][j] = 1;
				else
					map[i][j] = INF;
			}
		}
		for(int k = 0 ; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					map[i][j] = Math.min(map[i][j],map[i][k]+map[k][j]);
				}
			}
		}
//		System.out.println();
//		for(int i = 0 ; i < n; i++)
//		{
//			for(int j = 0 ; j < n; j++)
//			{
//				System.out.print(map[i][j] +" ");
//			}
//			System.out.println();
//		}
		String answer = "YES";
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken()) -1;
		for(int i = 0 ; i < m-1; i++)
		{
			int dest = Integer.parseInt(st.nextToken()) -1;
			if(dest == start)
			{
				start = dest;
				continue;
			}
			if(map[start][dest] == INF)
			{
				answer = "NO";
				break;
			}
			start = dest;
		}
		System.out.print(answer);
	}
}
