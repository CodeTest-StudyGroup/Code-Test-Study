package 분류전;

import java.util.*;
import java.io.*;
public class 멀티탭스케쥴링 {
	static int n;
	static int k;
	
	static class Node implements Comparable<Node>{
		public int weight;
		public int idx;
		Node(int weight, int idx)
		{
			this.weight =weight;
			this.idx  =idx;
		}
		@Override
		public int compareTo(Node n)
		{
			return	n.weight-this.weight;
		}
		public String toString()
		{
			return idx+" + "+weight;
			
		}

		
	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		ArrayList<Integer> list = new ArrayList<>();
		int[] check =  new int[101];
		ArrayList<Integer> input = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		PriorityQueue<Node> queue = new PriorityQueue<>();
		while(st.hasMoreTokens())
			input.add(Integer.parseInt(st.nextToken()));
		ArrayList<Node> arr = new ArrayList<>();
		for(int i=0; i<input.size(); i++)
		{
			boolean flag = false;
			for(int j=i+1; j<input.size(); j++)
			{
				if(input.get(j)==input.get(i))
				{
					arr.add(new Node(j,input.get(i)));
					flag=true;
					break;
				}
			}
			if(flag==false)
				arr.add(new Node(99999,input.get(i)));
				
		}


		int cnt=0;
		int answer=0;
		for(int i=0; i<arr.size(); i++)
		{
			if(cnt<n)
			{
				boolean flag=false;
				Iterator ite =queue.iterator();
				while(ite.hasNext())
				{
					Node node = (Node)ite.next();
					if(node.idx==arr.get(i).idx)
					{
						ite.remove();
						queue.offer(arr.get(i));
						flag=true;
						break;
					}
				}
				if(flag==false)
				{
					queue.offer(arr.get(i));
				cnt+=1;
				}
			}
			else
			{
				boolean flag=false;
				Iterator ite = queue.iterator();
				while(ite.hasNext())
				{
					Node node = (Node)ite.next();
					if(node.idx==arr.get(i).idx)
					{
						ite.remove();
						queue.offer(arr.get(i));
						flag=true;
						break;
					}
				}
				if(flag==false)
				{
					queue.poll();
					answer+=1;
					queue.offer(arr.get(i));
					
				}
			}
			
		}
		System.out.println(answer);
	}

}
