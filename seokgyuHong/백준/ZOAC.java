package 분류전;

import java.io.*;
import java.util.*;

public class ZOAC {

	static StringBuilder answer;
	static boolean[] check;
	static char[] arr;
	static int count;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder a;
		StringBuilder b;
		String input = br.readLine();
		arr = new char[input.length()];
		check = new boolean[input.length()];
		for(int i=0; i<arr.length; i++)
			arr[i] = input.charAt(i);

		int cnt=0;
		
		int start =0;
		int max=987654321;
		for(int i=0; i<arr.length; i++)
		{
			if((int)arr[i]<max)
			{
				max=arr[i];
				start=i;
			}
			
		}
		System.out.println(arr[start]);
		check[start]=true;
		dfs(start,0);
		

		
	}
	static void dfs(int start,int cnt)
	{
//		if(cnt>arr.length-1)
//			return;
		int max=987654321;
		int idx=0;
		boolean flag = false;
		for(int i=start; i<arr.length; i++)
		{
			if(check[i]==false)
			{
				if((int)arr[i]<max)
				{
					max=arr[i];
					idx=i;
					flag=true;
				}
				
			}
		}
		if(flag==true)
		{

			check[idx]=true;
			for(int i=0; i<arr.length; i++)
			{
				if(check[i])
					System.out.print(arr[i]);
				
			}
			System.out.println();

			dfs(idx,cnt+1);
		}

		int answer=0;
		for(int i=0; i<check.length; i++)
		{
			if(check[i])
				answer++;
			
		}
		if(answer==check.length)
			return;

		int ptr=start-1;
		max = 987654321;
		int idx2=0;
		boolean flag2 = false;
		
		while(true)
		{
			if(ptr==0)
				break;
			if(check[ptr])
				break;
			ptr--;
		}
		for(int i=ptr; i<start; i++)
		{
			if(!check[i])
			{
				flag2=true;
				if(max>(int)arr[i])
				{
					max=arr[i];
					idx2=i;
					
				}
			}
		}
		if(flag2)
		{
		check[idx2]=true;
		for(int i=0; i<arr.length; i++)
		{
			if(check[i])
				System.out.print(arr[i]);
		}
		System.out.println();
		dfs(idx2,cnt+2);
		}
		


				
		}
		
		
	

}
