import java.io.*;
import java.util.*;
/*
 *아래처럼 곱하게 해서 해결했음
2
2 		3		5		7
2 3 5 7		3 5 7		5 7		7

3
3 5 7

5
5 7

7
7 
*/
public class Main {
	public static void main (String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		double[] sosu = new double[n];
		PriorityQueue<node> pq = new PriorityQueue();
		for(int i = 0 ; i < n ; i ++)
		{
			double temp =Integer.parseInt(st.nextToken()); 
			sosu[i] = temp;
			node no = new node(temp,i);
			pq.add(no);
		}
		int count = 0 ; //counter가 m이상이면 종료
		while(!pq.isEmpty())
		{
			count++;
			node cur = pq.poll();
//			System.out.println("cur : "+cur.num);
			if(count == m)
			{
				System.out.printf("%.0f",cur.num);
				break;
			}
			for(int i = cur.range; i < n; i++)
			{
				node next = new node(cur.num*sosu[i],i);
				pq.add(next);
			}
		}
	}
}
class node implements Comparable<node>
{
	double num;
	int range;
	node(double i, int j)
	{
		num = i;
		range = j;
	}
	@Override
	public int compareTo(node o) {
		if(this.num < o.num)
			return -1;
		else if(this.num > o.num)
			return 1;
		// TODO Auto-generated method stub
		return 0;
	}
}