import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main (String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		LinkedList<node> list = new LinkedList();
		LinkedList<line> made = new LinkedList();
		int made_count = 0;
		for(int i = 0 ; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			node no = new node(i,y,x);
			list.add(no);
			for(int j = 0; j < i; j++)
			{
				node temp = list.get(j);
				double len = Math.sqrt(Math.pow(y-temp.y, 2)+Math.pow(x-temp.x, 2));
				line l;
				if(temp.idx < i)
					l = new line(temp.idx, i, len);
				else 
					l = new line(i,temp.idx,len);
				made.add(l);
			}
		}
		for (int i = 0 ; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			line l;
			if(a < b)
				l = new line(a-1,b-1,0);
			else
				l = new line(b-1,a-1,0);
			made.add(l);
		}
		Collections.sort(made,new myc());
		System.out.printf("%.2f",kruskal(n, made));
	}
	public static double kruskal(int n,LinkedList<line> made)
	{
		double answer = 0;
		int[] parent = new int[n];
		Arrays.fill(parent, -1);
		Iterator it = made.iterator();
		int break_count = 0;
		while(it.hasNext())
		{
			line temp = (line) it.next();
			int s = temp.start;
			int e = temp.end;
			int ps = find(s,parent);
			int pe = find(e,parent);
			int count = parent[ps] + parent[pe];
			if(ps == pe)
			{
				if(ps == -1) //둘다 -1로 같은 상황
				{
					if(s < e)
					{
						parent[e] = s;
						parent[s] = count;
					}
					else
					{
						parent[s] = e;
						parent[e] = count;
					}
					break_count++;
					answer+=temp.len;
					
				}
				else; //사이클 형성이라 무시해야함.
			}
			else
			{
				if(parent[ps] < parent[pe]) //ps에 더 많은 애들 연결되어 있음
				{
					parent[pe] = ps;
					parent[ps] = count;
				}
				else
				{
					parent[ps] = pe;
					parent[pe] = count;
				}
				break_count++;
				answer+=temp.len;
			}
			if(break_count == n-1)
			{
				break;
			}
		}
		return answer;
	}
	public static int find(int a, int[] p)
	{
		int pa = a;
		while(p[pa] > -1)
		{
			pa = p[pa];
		}
		return pa;
	}
}
class myc implements Comparator<line>
{

	@Override
	public int compare(line o1, line o2) {
		if(o1.len < o2.len)
			return -1;
		else if(o1.len > o2.len)
			return 1;
		return 0;
	}
}
class line
{
	int start;
	int end;
	double len;
	line(int s, int e, double l)
	{
		start = s;
		end = e;
		len = l;
	}
}
class node
{
	int idx;
	int y;
	int x;
	node(int i, int j ,int k)
	{
		idx = i;
		y = j;
		x = k;
	}
}