package 이분탐색;

import java.io.*;
import java.util.*;
public class 반도체설계 {
	static int n;
	static int[] arr;
	static int[] d;
	static int[] dp; 
	static class Node implements Comparable<Node>{
		int x;
		int y;
		int dist;

		public Node(int x, int y, int dist)
		{
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
		@Override
		public int compareTo(Node o)
		{
			return this.dist-o.dist;
			
		}
		@Override
		public String toString()
		{
			return String.format("%s, %s", this.x,this.y);
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new int[n+1];
		d = new int[n+1]; //d[i]값은 a[i]값을 이용해 만들 수 있는 가장 긴 부분 증가 수열을 의미한다.
		dp = new int[n+1]; //세로는 dp[i]는 i까지 길이를 유지할때ㅔ 가장 작은값을 의미한다
//		for(int i=0; i<=n; i++)
//			dp[i] = new int[n+1];
		arr[0]=0;
		d[0] = 0;
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for(int i=1; i<=n; i++)
		{
			int temp =Integer.parseInt(st.nextToken());
			arr[i] = temp;
			int left = 0;
			int right = n;
			int idx=0;
			while(left<=right)
			{
				int mid = (left+right)/2;
				if(dp[mid]>arr[i]) //나보다 크면
				{
					right = mid-1;
				}
				else
				{
					idx = mid;
					left = mid+1;
				}
			}
			d[i] = idx+1; // dp[mid]값을 갱신해나가면서 나 보다 바로 직전으로 작은 ㅣower bound를 찾아 해당 idx가 수열의 길이가 되므로 d[i는 idx+1로 변경해줬다.
			if(dp[d[i]]>arr[i])
				dp[d[i]]=arr[i];
			

		}

		int answer = Integer.MIN_VALUE;
		for(int i=0; i<d.length; i++)
		{
			if(d[i]>answer)
				answer=d[i];
		}
		System.out.println(answer);
		

	}

}
