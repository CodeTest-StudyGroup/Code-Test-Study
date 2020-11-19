import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	static boolean[] visited;
	static int answer = -1;
	static boolean[][] already;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int g = Integer.parseInt(st.nextToken());
		int[][] original_map = new int[n][m];
		already = new boolean[n][m];
		int[][][] map = new int[n][m][2]; // 마지막엔 뿌려진 배양액 종류 + 시간 이 필요해서 [2]로 처리		
		LinkedList<Integer[]> pos = new LinkedList(); // 배양액 뿌릴 수 있는 좌표 기억
		for(int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++)
			{
				int temp= Integer.parseInt(st.nextToken());
				if(temp == 2)
				{
					Integer[] point = new Integer[2];
					point[0] = i;
					point[1] = j;
					pos.add(point);
				}
				map[i][j][0] = temp;
				original_map[i][j] = temp;
				map[i][j][1] = 0;
			}
		}
		int rg = r+g;
		visited = new boolean[pos.size()];
		LinkedList<Integer> start = new LinkedList();
		HashSet<LinkedList<Integer>> set = new HashSet();
		rg_permu(0,pos.size(),start,rg,set);
		Iterator sit = set.iterator();
		while(sit.hasNext())
		{
			visited = new boolean[pos.size()];
			LinkedList<Integer> s_cur = (LinkedList)sit.next();
			HashSet<LinkedList<Integer>> r_set = new HashSet();
			LinkedList<Integer> position = new LinkedList<Integer>();
			r_permu(0,s_cur.size(),start,r,r_set,s_cur);
			Iterator rit = r_set.iterator();
			while(rit.hasNext())
			{
				already = new boolean[n][m];
				LinkedList<Integer> rtemp = (LinkedList<Integer>) rit.next(); //빨간색 서순
				int r_idx = 0;
				LinkedList<spread> q = new LinkedList();
				for(int i = 0 ; i < rg; i++)	//배양액 뿌리기 (빨간색 아닌데는 초록색 뿌리기)(pos의 index임)
				{
					int hubo = s_cur.get(i);
					//map에 반영
					LinkedList<Integer[]> queue = new LinkedList();
					if(r_idx < rtemp.size() && hubo == rtemp.get(r_idx))
					{					
						Integer[] p_temp = pos.get(hubo);
						int y = p_temp[0];
						int x = p_temp[1];
						map[y][x][0] = 3; //빨간색은 3, 초록색은 4로 색칠할 예정
						r_idx++;
						spread s = new spread(y,x,3,0);
						q.add(s);
					}
					else
					{
						Integer[] p_temp = pos.get(hubo);
						int y = p_temp[0];
						int x = p_temp[1];
						map[y][x][0] = 4; //빨간색은 3, 초록색은 4로 색칠할 예정
						spread s = new spread(y,x,4,0);
						q.add(s);
					}
				}
				bfs(map,n,m,q);
				for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0; j < m; j++)
					{
						map[i][j][0] = original_map[i][j];
						map[i][j][1] = 0;
					}
				}

				//bfs돌리면서 꽂 피울 수 있는 갯수 계산
				
			}
		}
		System.out.println(answer);
	}
	public static void r_permu(int cur,int size,LinkedList<Integer> made,int r,HashSet<LinkedList<Integer>> r_set,LinkedList<Integer> s)
	{
		if(made.size() == r)
		{
			r_set.add(made);
			return;
		}
		for(int i = cur; i<size; i++)
		{
			int c = s.get(i);
			visited[i] = true;
			LinkedList<Integer> next = new LinkedList();
			Iterator it = made.iterator();
			while(it.hasNext())
			{
				next.add((Integer)it.next());
			}
			next.add(c);
			r_permu(i+1,size,next,r,r_set,s);
			visited[i] = false;
		}		
	}
	public static void rg_permu(int cur,int size,LinkedList<Integer> made,int rg,HashSet<LinkedList<Integer>> set)
	{
		if(made.size() == rg)
		{
			set.add(made);
			return;
		}
		for(int i = cur; i<size; i++)
		{
			visited[i] = true;
			LinkedList<Integer> next = new LinkedList();
			Iterator it = made.iterator();
			while(it.hasNext())
			{
				next.add((Integer)it.next());
			}
			next.add(i);
			rg_permu(i+1,size,next,rg,set);
			visited[i] = false;
		}
	}
	public static void bfs(int[][][] map,int n,int m,LinkedList<spread> q)
	{
		int blossom = 0;
		while(!q.isEmpty())
		{
			spread cur = q.poll();
			int y = cur.y;
			int x = cur.x;
			int c = cur.c;
			int t = cur.t;
			if(map[y][x][0] == -1)
				continue;
			if(y< n-1)
			{
				if(map[y+1][x][0] == 1 || map[y+1][x][0] == 2)
				{
					map[y+1][x][0] = c;
					map[y+1][x][1] = t+1;
					spread next = new spread(y+1,x,c,t+1);
					q.add(next);
				}
				else if(map[y+1][x][0] != 0)
				{
					if(c == 3 && map[y+1][x][0] == 4 && t+1 == map[y+1][x][1])
					{
						if(already[y+1][x]==false)
						{
							blossom++;
							map[y+1][x][0] = -1;
							already[y+1][x] = true;
						}
					}
					else if(c == 4 && map[y+1][x][0] ==3 && t+1 == map[y+1][x][1])
					{
						if(already[y+1][x]==false)
						{
							blossom++;
							map[y+1][x][0] = -1;
							already[y+1][x] = true;
						}
					}
				}
			}
			if(y > 0)
			{
				if(map[y-1][x][0] == 1 || map[y-1][x][0] == 2)
				{
					map[y-1][x][0] = c;
					map[y-1][x][1] = t+1;
					spread next = new spread(y-1,x,c,t+1);
					q.add(next);
				}
				else if(map[y-1][x][0] != 0)
				{
					if(c == 3 && map[y-1][x][0] == 4 && t+1 == map[y-1][x][1])
					{
						if(already[y-1][x]==false)
						{
							blossom++;
							map[y-1][x][0] = -1;
							already[y-1][x] = true;
						}
					}
					else if(c == 4 && map[y-1][x][0] ==3 && t+1 == map[y-1][x][1])
					{
						if(already[y-1][x]==false)
						{
							blossom++;
							map[y-1][x][0] = -1;
							already[y-1][x] = true;
						}
					}
				}
			}
			if(x< m-1)
			{
				if(map[y][x+1][0] == 1 || map[y][x+1][0] == 2)
				{
					map[y][x+1][0] = c;
					map[y][x+1][1] = t+1;
					spread next = new spread(y,x+1,c,t+1);
					q.add(next);
				}
				else if(map[y][x+1][0] != 0)
				{
					if(c == 3 && map[y][x+1][0] == 4 && t+1 == map[y][x+1][1])
					{
						if(already[y][x+1]==false)
						{
							blossom++;
							map[y][x+1][0] = -1;
							already[y][x+1] = true;
						}
					}
					else if(c == 4 && map[y][x+1][0] ==3 && t+1 == map[y][x+1][1])
					{
						if(already[y][x+1]==false)
						{
							blossom++;
							map[y][x+1][0] = -1;
							already[y][x+1] = true;
						}
					}
				}
			}
			if(x > 0)
			{
				if(map[y][x-1][0] == 1 || map[y][x-1][0] == 2)
				{
					map[y][x-1][0] = c;
					map[y][x-1][1] = t+1;
					spread next = new spread(y,x-1,c,t+1);
					q.add(next);
				}
				else if(map[y][x-1][0] != 0)
				{
					if(c == 3 && map[y][x-1][0] == 4 && t+1 == map[y][x-1][1])
					{
						if(already[y][x-1]==false)
						{
							blossom++;
							map[y][x-1][0] = -1;
							already[y][x-1] = true;
						}
					}
					else if(c == 4 && map[y][x-1][0] ==3 && t+1 == map[y][x-1][1])
					{
						if(already[y][x-1]==false)
						{
							blossom++;
							map[y][x-1][0] = -1;
							already[y][x-1] = true;
						}
					}
				}
			}
		}
		answer = Math.max(answer, blossom);
	}
}
class spread
{
	int y;
	int x;
	int c; //색깔
	int t; //시간
	spread(int i, int j, int k, int l)
	{
		y = i;
		x = j;
		c = k;
		t = l;
	}
}