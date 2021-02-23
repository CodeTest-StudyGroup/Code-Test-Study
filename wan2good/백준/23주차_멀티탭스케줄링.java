import java.util.*;
import java.io.*;

public class Main {

   static int n,k;
   static int[] order;
   static int[][] count;
   static int[] multiTap;
   
   public static void main(String[] args) throws IOException{
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   StringTokenizer st = new StringTokenizer(br.readLine());
	   n = Integer.parseInt(st.nextToken());
	   k = Integer.parseInt(st.nextToken());
	   
	   order = new int[k];
	   
	   st = new StringTokenizer(br.readLine());
	   for(int i=0; i<k; i++) 
	   {
		   int num = Integer.parseInt(st.nextToken());
		   order[i] = num;
	   }
	   
	   int last=0;
	   multiTap = new int[n];
	   int cur,cnt=0;
	   for(int i=0; i<k; i++) {
		   boolean flag=false;
		   cur = order[i];
		   for(int idx=0; idx<n; idx++) {
			   if(multiTap[idx]==cur) {
				   flag=true;
				   break;
			   }
			   else if(multiTap[idx]==0) {
				   flag=true;
				   multiTap[idx]=cur;
				   break;
			   }
		   }
		   if(flag)
			   continue;
		   
		   cnt+=1;
		   int resultMultitapIdx=0;
		   int orderIdx=Integer.MIN_VALUE;
		   for(int idx=0; idx<n; idx++) {
			   int len=0;
			   for(int x=i+1; x<k; x++) {
				   if(multiTap[idx]!=order[x])
					   len++;
				   else
					   break;
			   }
			   if(len > orderIdx) {
				   resultMultitapIdx = idx;
				   orderIdx = len;
			   }
		   }
		   
		   multiTap[resultMultitapIdx]=cur;
			   
		   
	   }
      
      System.out.println(cnt);
   }

}