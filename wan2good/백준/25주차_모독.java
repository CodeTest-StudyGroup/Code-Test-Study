import java.io.*;
import java.util.*;

public class Main { 
	
	public static void main(String[] args) throws Exception { 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] data = new int[n];
		for(int i=0; i<n; i++) {
			data[i] = Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(data);
		long sum=0;
		if(data[0]>1) {
			sum=data[0]-1;
			data[0]=1;
		}
		
		for(int i=1; i<n; i++) {
			if(data[i]>data[i-1])
			{
				sum+=data[i]-(data[i-1]+1);
				data[i]=data[i-1]+1;
			}
		}
		System.out.println(sum);
	} 
}