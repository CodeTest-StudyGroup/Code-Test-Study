import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		int input_size = 4;		
		for(int i = 0 ; i < t; i++)
		{
			String[] visited = new String[10001];
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			Queue<Integer> queue = new LinkedList();
			queue.add(start);
			
			for(int re = 0; re < 10001; re++)
				visited[re] = "";
			while(!queue.isEmpty())
			{
				int cur = queue.poll();
				if(cur == end)
				{
					bw.write(visited[end]+"\n");
					break;
				}
				
				{	//D
					int temp = cur;
					temp*=2;
					if(temp > 9999)
					{
						temp %= 10000;
					}
					if(temp != cur)
					{
					if(visited[temp].equals(""))
					{
						visited[temp] = visited[cur]+"D";
						queue.add(temp);
					}
					else if(visited[temp].length() > visited[cur].length()+1)
					{
						visited[temp] = visited[cur]+"D";
						queue.add(temp);						
					}
					}
				}
				{	//S
					int temp = cur;
					temp-=1;
					if(temp == -1 )
					{
						temp = 9999;
					}
					if(temp != cur)
					{
					if(visited[temp].equals(""))
					{
						queue.add(temp);
						visited[temp] = visited[cur]+"S";
					}
					else if(visited[temp].length() > visited[cur].length()+1)
					{
						visited[temp] = visited[cur]+"S";
						queue.add(temp);						
					}
					}
				}
				{	//L
					int temp = cur;
					int div = (int) Math.pow(10, input_size-1);
					int moc = temp/div;
					int na = temp % div;
					temp = na*10+moc;
					if(temp != cur)
					{
					if(visited[temp].equals(""))
					{
						queue.add(temp);
						visited[temp] = visited[cur]+"L";
					}					
					else if(visited[temp].length() > visited[cur].length()+1)
					{
						visited[temp] = visited[cur]+"L";
						queue.add(temp);						
					}
					}
				}
				{	
					//R
					int temp = cur;
					int mul = (int) Math.pow(10, input_size-1);
					int na = temp % 10; //일의 자리					
					int moc = temp/10;
					temp = na*mul+moc;
					if(temp != cur)
					{
					if(visited[temp].equals(""))
					{
						queue.add(temp);
						visited[temp] = visited[cur]+"R";
					}
					else if(visited[temp].length() > visited[cur].length()+1)
					{
						visited[temp] = visited[cur]+"R";
						queue.add(temp);						
					}
					}
				}
			}
		}
		bw.close();
	}
}
