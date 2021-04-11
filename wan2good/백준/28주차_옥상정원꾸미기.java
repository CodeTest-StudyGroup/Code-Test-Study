import java.io.*;
import java.util.*;

public class Main { 
	
	public static void main(String[] args) throws Exception { 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		long[] data = new long[n];
		
		Queue<Integer> q = new LinkedList<>();
		for(int i=0; i<n; i++) {
			data[i] = Integer.parseInt(br.readLine());
			q.offer(i);
		}
		
		int[] result = new int[n];
		long sum=0;
		Arrays.fill(result, 0);
		for(int i=1; i<n; i++) {
			int idx=i;
			while(idx<n && data[q.peek()]>data[idx]) {
				sum++;
				idx++;
			}
			q.poll();
		}
		System.out.println(sum);
	} 
}