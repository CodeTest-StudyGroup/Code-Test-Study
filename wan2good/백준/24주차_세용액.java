import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    
	static int n;
	static long[] data;
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        data = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
        	data[i] = Long.parseLong(st.nextToken());
        }
        
        Arrays.sort(data);
        long ans = Long.MAX_VALUE;
        long tmp;
        int x=0,y=0,z=0;
        
        for(int l=0; l<n; l++)
        {
        	int r=n-1;
        	int mid=l+1;
        	
        	while(mid<r) {
        		tmp = data[l]+data[r]+data[mid];
            	if(Math.abs(tmp)<Math.abs(ans)) {
            		ans=Math.abs(tmp);
            		x=l;
            		y=r;
            		z=mid;
            	}
            	
            	if(tmp<0)
            		mid++;
            	else
            		r--;
        	}
        }
        
        long[] result = new long[3];
        result[0] = data[x];
        result[1] = data[y];
        result[2] = data[z];
        Arrays.sort(result);
        for(int i=0; i<3; i++) {
        	System.out.print(result[i]+" ");
        }
        System.out.println();
        
	}
}