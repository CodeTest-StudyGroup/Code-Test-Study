import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int time = Integer.parseInt(st.nextToken());
		int[][] map = new int[m][m];
//		int[][] grow_gap = new int[m][m];

		for(int t = 0 ; t < time; t++)
		{
			st = new StringTokenizer(br.readLine());
			int g = 0;
			int start = 0;
			int row = m-1;
			int col = 0;
///////////////////////////
/*
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			row-=a;
			if(row<0)
			{
				col = Math.abs(row);
				row = 0;
			}
			
			for(int i = a; i < a+b; i++)
			{
				map[row][col] += 1;
//				grow_gap[row][col] += 1;
				if(row == 0)
				{
					col++;
				}
				else
				{
					row--;
				}
			}
			for(int i = a+b; i< 2*m-1; i++)
			{
				map[row][col] += 2;
//				grow_gap[row][col] += 2;				
				if(row == 0)
				{
					col++;
				}
				else
				{
					row--;
				}
			}
*/
///////////////////////////
			
			int num = Integer.parseInt(st.nextToken());
 			row-=(num);
			if(row < 0)
			{
				col = Math.abs(row);
				row = 0;
			}				
			
			int number = 1;
			for(int j = 1; j <3; j++)
			{
				num = Integer.parseInt(st.nextToken());
				for(int k = 0; k <num;k++)
				{
					map[row][col]+=number;
//					grow_gap[row][col] += number;
					if(row == 0)
					{
						col++;
					}
					else
					{
						row--;
					}
				}
				number++;
			}

////////////////////////////////////
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i = 0; i<m;i++)
		{
			for(int j = 0; j<m;j++)
			{
//				map[i][j] += 1;
				if(i>0 && j> 0)
				{
//					int temp = Math.max(grow_gap[i-1][j-1], grow_gap[i][j-1]); // 왼쪽위, 왼쪽과 비교
//					grow_gap[i][j] = Math.max(grow_gap[i-1][j],temp); // 위에거중 큰거와 바로 위를 비교
//					map[i][j] += grow_gap[i-1][j];
//					grow_gap[i][j] = grow_gap[i-1][j];
					map[i][j] = map[i-1][j];
				}
				bw.write((map[i][j]+1)+" ");
			}
			bw.write("\n");
		}
		bw.close();
	}
}
