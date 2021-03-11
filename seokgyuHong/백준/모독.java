package 그리디;
import java.io.*;
import java.util.*;

public class 모독 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		Stack<Integer> stack = new Stack<>();
		int n = Integer.parseInt(br.readLine());
		int[] check = new int[200000];
		
		for(int i=0; i<n; i++)
		{
			int temp =Integer.parseInt(br.readLine());

			pq.offer(temp);


		}
		
		long answer=0;
		int idx=1;

		while(!pq.isEmpty())
		{
			int temp = pq.poll();
			if(idx==temp)
			{
				if(check[idx]==0)
					check[idx]+=1;
				idx++;
			}
			else if(idx<temp)
			{
				if(check[idx]==0)
				{
				answer+=(temp-idx);
				check[idx]+=1;
				}
				idx++;
			}
				
			
		}
		


		System.out.println(answer);
	}

}
