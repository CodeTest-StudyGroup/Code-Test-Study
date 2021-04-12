import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static int[] data,arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
	       
		n = Integer.parseInt(br.readLine());
		data = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			data[i] = Integer.parseInt(st.nextToken());
		}
		
		arr = new int[n];
		int cur=0;
		arr[cur++] = data[0];
		
		for(int i=1; i<n; i++) {
			if(arr[cur-1]<data[i]) {
				arr[cur++] = data[i];
			}
			else {
				int idx = Arrays.binarySearch(arr, 0, cur, data[i]);
				if(idx<0)
					idx=-idx-1;
				arr[idx]=data[i];
			}
		}
		
		int cnt=0;
		for(int i=0; i<n; i++) {
			if(arr[i]!=0) {
				cnt++;
			}
		}
		for(int i=0; i<n; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println(cnt);
	}
	
}