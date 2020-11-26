import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		int testcase = Integer.parseInt(br.readLine());
		for(int i = 0 ; i < testcase; i++)
		{
			String answer="YES";
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k= Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			LinkedList[] link = new LinkedList[k];
			for(int j = 0 ; j < k; j++)
			{
				link[j] = new LinkedList<Integer>();
			}
			for(int j = 0 ; j < v; j++)
			{
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				link[a-1].add(b-1);
				link[b-1].add(a-1);
			}

			int[] number = new int[k]; //0 - 아직 방문 안함, 1- 1번그룹, 2- 2번그룹
			for(int idx = 0; idx < k; idx++)
			{
			Queue<Integer> queue = new LinkedList<>();
			Iterator sit = link[0].iterator();			
			if(number[idx] != 0)
				continue;

			number[idx] = 1;
			queue.add(idx);
			int break_count = 0;
			//그룹 1에속한 애에서 연결된 애들은 2번 그룹으로 지정, child가 이미 1로 마킹되어 있음 -> 이 그래프는 이분 그래프 불가능
			boolean exit_flag = false;
			while(!queue.isEmpty())
			{
				break_count++;
				int cur =queue.poll();
				Iterator cit = link[cur].iterator();
				while(cit.hasNext())
				{
					int next = (Integer)cit.next();
					if(number[cur] == 1)
					{
						if(number[next] == 0)
						{
							number[next] = 2;
							queue.add(next);						
						}
						else if(number[next] == 1)
						{
							answer = "NO";
							exit_flag = true;
							break;
						}
						//number[next] == 2는 이미 큐에 등록된 유효한 child이니 패스 
					}
					else //number[cur] == 2
					{
						if(number[next] == 0)
						{
							number[next] = 1;
							queue.add(next);
						}
						else if(number[next] == 2)
						{
							answer = "NO";
							exit_flag = true;
							break;
						}
						//number[next] == 1는 이미 큐에 등록된 유효한 child이니 패스 
					}	
				}
				if(exit_flag)
					break;
			}
			
			}
			bw.write(answer);
			if(i < testcase-1)
			{
				bw.write("\n");
			}
		}
		bw.close();
	}
}