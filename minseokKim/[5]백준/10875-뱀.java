import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long l = Long.parseLong(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int count = Integer.parseInt(st.nextToken());		
		long top = -l;
		long bottom = l;
		long left = -l;
		long right = l;
		long cur_y = 0;
		long cur_x = 0;
		long cur_d = 1; //뱀이 바라보고 있는 방향
		//1 오른쪽 2 위쪽 3 왼 4 아래 보고 있는거임.
		long answer = 0;
		LinkedList<line> list = new LinkedList();
		LinkedList<order> o = new LinkedList();

		for(int i = 0 ; i < count; i++)
		{
			st = new StringTokenizer(br.readLine());
			long len = Long.parseLong(st.nextToken());
			char dir = st.nextToken().charAt(0);
			order inp = new order(len,dir);
			o.add(inp);
		}

		Iterator<order> it = o.iterator();
		while(true)
		{
			long len = 2*l+1;
			char dir = ' ';
			if(it.hasNext())
			{
			order now = (order)it.next();
			len = now.len;
			dir = now.dir;			
			}
			if(cur_d == 1) //우측을 바라보고 있었음
			{
				boolean collapse = false;
				long temp_min = Long.MAX_VALUE;
				for(int j = 0 ; j < list.size(); j++)
				{
					line temp = list.get(j);
					long x1 = Math.min(temp.x1, temp.x2);
					long x2 = Math.max(temp.x1, temp.x2);
					long y1 = Math.min(temp.y1, temp.y2);
					long y2 = Math.max(temp.y1, temp.y2);
					if(y1 == y2 && x1 > cur_x && y1 == cur_y && x1 <= cur_x+len ) // 통과
					{					
						long k = 0;
						if(temp_min > (k = Math.abs(x1 - cur_x)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					if(x1 == x2 && x1 > cur_x && y1 <= cur_y && y2 >= cur_y && cur_x +len >= x1) // 수직
					{
						long k = 0;
						if(temp_min > (k = Math.abs(x1 - cur_x)))
						{
							temp_min = k;
						}
						collapse = true;
					}
					//지나간 선과 충돌
				}
				if(collapse)
				{
					answer += temp_min;
					System.out.println(answer);
					return;					
				}

				if(cur_x+len > right) //벽과 충돌
				{
					answer+= Math.abs(right-cur_x)+1;
					System.out.println(answer);
					return;						
				}
				if(dir == 'R')
				{
					cur_d = 4;
				}
				if(dir =='L')
				{
					cur_d = 2;
				}				

				line li = new line(cur_y,cur_x,cur_y,cur_x+len);
				list.add(li);
				cur_x+=len;
			}
			else if(cur_d == 2) //위쪽 보고 있음
			{
				boolean collapse = false;
				long temp_min = Long.MAX_VALUE;
				for(int j = 0 ; j < list.size(); j++)
				{
					line temp = list.get(j);
					long x1 = Math.min(temp.x1, temp.x2);
					long x2 = Math.max(temp.x1, temp.x2);
					long y1 = Math.min(temp.y1, temp.y2);
					long y2 = Math.max(temp.y1, temp.y2);

					if(x1 == x2&& y2 < cur_y && x1 == cur_x && y2 >= cur_y-len) //통과
					{		
						long k = 0;
						if(temp_min > (k = Math.abs(y2 - cur_y)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					if(y1 == y2 && y2 < cur_y && x1 <= cur_x && x2 >= cur_x && cur_y-len <= y1) //수직
					{
						long k = 0;
						if(temp_min > (k = Math.abs(y2 - cur_y)))
						{
							temp_min = k;
						}
						collapse = true;
					}
					//지나간 선과 충돌
				}
				if(collapse)
				{
					answer += temp_min;
					System.out.println(answer);
					return;					
				}

				if(cur_y-len < top)
				{
					answer+= Math.abs(top - cur_y)+1;
					System.out.println(answer);
					return;						
				}
				if(dir == 'R')
				{
					cur_d = 1;
				}
				if(dir =='L')
				{
					cur_d = 3;
				}
				line li = new line(cur_y,cur_x,cur_y-len,cur_x);
				list.add(li);	
				cur_y-= len;
			}
			else if(cur_d == 3)
			{
				boolean collapse = false;
				long temp_min = Long.MAX_VALUE;

				for(int j = 0 ; j < list.size(); j++)
				{	
					line temp = list.get(j);
					long x1 = Math.min(temp.x1, temp.x2);
					long x2 = Math.max(temp.x1, temp.x2);
					long y1 = Math.min(temp.y1, temp.y2);
					long y2 = Math.max(temp.y1, temp.y2);
					
					if(y1 == y2&& x2 < cur_x && cur_y == y1 && x2 >= cur_x-len)
					{						
						long k = 0;
						if(temp_min > (k = Math.abs(x2 - cur_x)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					if(x1 == x2 && x2 < cur_x && y1 <= cur_y && y2 >= cur_y && cur_x -len <= x1)
					{
						long k = 0;
						if(temp_min > (k = Math.abs(x2 - cur_x)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					//지나간 선과 충돌
				}
				if(collapse)
				{
					answer += temp_min;
					System.out.println(answer);
					return;					
				}
				if(cur_x-len < left)
				{
					answer+= Math.abs(left - cur_x)+1;
					System.out.println(answer);
					return;						
				}
				if(dir == 'R')
				{
					cur_d = 2;
				}
				if(dir =='L')
				{
					cur_d = 4;
				}
				line li = new line(cur_y,cur_x,cur_y,cur_x-len);
				list.add(li);
				cur_x-= len;
			}
			else
			{
				boolean collapse = false;
				long temp_min = Long.MAX_VALUE;

				for(int j = 0 ; j < list.size(); j++)//-1하는이유는 직전은 상관 X이기 때문
				{
					line temp = list.get(j);
					long x1 = Math.min(temp.x1, temp.x2);
					long x2 = Math.max(temp.x1, temp.x2);
					long y1 = Math.min(temp.y1, temp.y2);
					long y2 = Math.max(temp.y1, temp.y2);
					
					if(x1 == x2&& y1 > cur_y && x1 == cur_x && y1 <= cur_y+len)
					{						
						long k = 0;
						if(temp_min > (k = Math.abs(y1 - cur_y)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					if(y1 == y2 && y1 > cur_y && x1 <= cur_x && x2 >= cur_x && cur_y+len >= y1)
					{
						long k = 0;
						if(temp_min > (k = Math.abs(y1 - cur_y)))
						{
							temp_min = k;
						}
						collapse = true;
						//충돌
					}
					//지나간 선과 충돌
				}
				if(collapse)
				{
					answer += temp_min;
					System.out.println(answer);
					return;					
				}
				if(cur_y +len > bottom)
				{
					answer+= Math.abs(bottom - cur_y)+1;
					System.out.println(answer);
					return;						
				}
				if(dir == 'R')
				{
					cur_d = 3;
				}
				if(dir =='L')
				{
					cur_d = 1;
				}
				line li = new line(cur_y,cur_x,cur_y+len,cur_x);
				list.add(li);
				cur_y+=len;
			}
			answer+=len;
		}
		//1 오른쪽 2 위쪽 3 왼 4 아래 보고 있는거임.
//		if(cur_d == 1)
//		{
//			answer+= Math.abs(right-cur_x)+1;
//		}
//		else if(cur_d == 2)
//		{
//			answer+= Math.abs(top-cur_y)+1;
//		}
//		else if(cur_d == 3)
//		{
//			answer += Math.abs(left - cur_x)+1;
//		}
//		else
//		{
//			answer+= Math.abs(right - cur_y)+1;
//		}
//		System.out.println(answer);
	}
}
class line
{
	long y1;
	long x1;
	long y2;
	long x2;
	line(long i1, long j1, long i2, long j2)
	{
		y1 = i1;
		x1 = j1;
		y2 = i2;
		x2 = j2;
	}
}
class order
{
	long len;
	char dir;
	order(long i, char c)
	{
		len = i;
		dir = c;
	}
}