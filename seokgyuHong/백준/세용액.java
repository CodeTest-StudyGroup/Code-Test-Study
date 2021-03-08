package 투포인터;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class 세용액 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		long[] arr;
		int n = Integer.parseInt(br.readLine());
		arr = new long[n];
		st =new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++)
			arr[i] = Long.parseLong(st.nextToken());

		Arrays.sort(arr);
		
		
		
		int left = 0;
		int right = n-1;
		long answer=4000000000L;
		long answer_1 = 0L;
		long answer_2 = 0L;
		long answer_3 = 0L;
		for(int i=0; i<n; i++)
		{
			long mid = arr[i];
			left = 0;
			if(left==i)left++;
			right=n-1;
			if(right==i)right--;
			while(left<right)
			{
				long temp = arr[left]+arr[right];
				long sum = temp+mid;
				if(Math.abs(sum)<Math.abs(answer))
				{
					answer=sum;
					answer_1 = arr[left];
					answer_2 = arr[i];
					answer_3 = arr[right];
					
				}
				if(sum<0)
				{
					left++;
					if(left==i)left++;
				}
				else
				{
					right--;
					if(right==i)right--;
				}
			}
		}

		long[] answer_arr = new long[3];
		answer_arr[0] = answer_1;
		answer_arr[1] = answer_2;
		answer_arr[2] = answer_3;
		Arrays.sort(answer_arr);
		for(int i=0; i<3; i++)
		{
			System.out.print(answer_arr[i]+" ");
		}

	}

}
