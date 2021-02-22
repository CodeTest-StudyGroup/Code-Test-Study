package unionfind;
import java.util.*;

import java.io.*;
public class 친구네트워크 {
	static int t;
	static int cnt=1;
	static int[] parent;
	static int[] sum;
	static int root;
	static int answer;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		HashMap<String,Integer> map = new HashMap<>();
		ArrayList<Integer> graph[];
		t= Integer.parseInt(br.readLine());
		
		for(int z=0; z<t; z++)
		{
			int f = Integer.parseInt(br.readLine());
			graph = new ArrayList[f*2+1];
			
			parent = new int[f*2+1]; 
			sum = new int[f*2+1];
			for(int i=1; i<(f*2+1); i++)
			{
				sum[i] = 1;
				parent[i] = i;
			}
				
			for(int i=1; i<=f*2; i++)
			{
				graph[i] = new ArrayList<>();
			}
			String a;
			String b;
			int from;
			int to;
			int a_root;
			int b_root;
			//int answer;
			for(int i=0; i<f; i++)
			{
				answer=0;
				root=0;
				st = new StringTokenizer(br.readLine());
				a = st.nextToken();
				b= st.nextToken();
				if(map.getOrDefault(a, 0)==0)
				{
					map.put(a, cnt++);
				}
				if(map.getOrDefault(b, 0)==0)
				{
					map.put(b, cnt++);
				}
				from = map.get(a);
				to = map.get(b);

				a_root = find(from);
				b_root = find(to);
				
				if(a_root>b_root)
				{
					parent[a_root]=b_root;
					sum[b_root]+=sum[a_root];
					answer=sum[b_root];
				}
				else if(a_root<b_root)
				{
					parent[b_root]=a_root;
					sum[a_root]+=sum[b_root];
					answer=sum[a_root];
				}
				else
				{
					answer=sum[a_root];
				}
				
					
				
				bw.append(""+answer+"\n");

				
			}
			
			

		}
		bw.flush();
		bw.close();
		
		
	

	}
	static int find(int start)
	{

		if(parent[start]==start)
			return start;
		else
		return parent[start] = find(parent[start]);
			
			
	}


}
