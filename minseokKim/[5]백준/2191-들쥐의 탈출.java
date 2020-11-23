import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception
	{
		//y는 쥐의 갯수 x는 구멍의 갯수
		//map[y][x]는 각 구멍까지 가는데 쥐들이 걸리는 시간
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); //쥐 갯수
		int m = Integer.parseInt(st.nextToken()); //땅굴 갯수
		int s = Integer.parseInt(st.nextToken());//매 도착까지 시간
		int v = Integer.parseInt(st.nextToken()); //쥐 이동속도
		int d = s*v; //매 도착 전까지 쥐들이 이동 가능한 거리
		double[][] mouse = new double[n][2];
		double[][] hole = new double[m][2];
		double[][] map = new double[n][m];
		for(int i = 0 ; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			mouse[i][0] = Double.parseDouble(st.nextToken());
			mouse[i][1] = Double.parseDouble(st.nextToken());			
		}
		for(int i = 0 ; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			hole[i][0] = Double.parseDouble(st.nextToken());
			hole[i][1] = Double.parseDouble(st.nextToken());			
		}
		LinkedList<node> list = new LinkedList(); //갈 수 있는 구멍의 수가 작은애 부터 갈 수 있도록 해줄거임.
		int[] visited = new int[m];//이미 쥐가 차있는지 check
		int[] hole_count = new int[m];
		for(int i = 0 ; i < n; i++)
		{
			int count = 0;
			LinkedList<Integer> possible = new LinkedList<Integer>();
			for(int j = 0 ; j < m; j++)
			{				
				map[i][j] = Math.sqrt(Math.pow(mouse[i][0]-hole[j][0], 2)+Math.pow(mouse[i][1]-hole[j][1], 2));
//				System.out.print(map[i][j]+" ");
				if(map[i][j] <= d)
				{
					count++;
					hole_count[j]++;
					possible.add(j);
				}
			}
			node temp = new node(i,count,possible);
			list.add(temp);
//			System.out.println();			
		}
		if(!list.isEmpty())
			Collections.sort(list);	
		Iterator<node> it = list.iterator();
		int live = 0; // 살 수 있는 쥐의 수 
		while(it.hasNext())
		{
			node cur = (node)it.next();
			int min = 101;
			int idx = -1;
			for(int j = cur.hole.size()-1; j>= 0; j--)
			{
				if(visited[cur.hole.get(j)]!=1 && hole_count[cur.hole.get(j)] < min)
				{
					min = hole_count[cur.hole.get(j)];
					idx = j;
				}
			}
			if(idx != -1)
			{
				live++;
				visited[cur.hole.get(idx)] = 1;				
			}
		}
		System.out.println(n-live);
	}
}
class node implements Comparable<node>
{
	int idx; //몇 번째 쥐인가.
	int count;
	LinkedList<Integer> hole = new LinkedList<Integer>();
	node(int i ,int j,LinkedList<Integer> li)
	{
		idx = i;
		count = j;		
		hole = li;
//		Collections.sort(hole);
	}
	@Override
	public int compareTo(node o) {
		if(this.count < o.count)
			return -1;
		else if(this.count > o.count)
			return 1;
		else
			return 0;
	}
}