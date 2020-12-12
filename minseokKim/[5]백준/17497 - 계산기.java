import java.util.*;
import java.io.*;

public class Main {
	static int[] visited;
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = Long.parseLong(br.readLine());
//		long max = (long)Math.pow(2, 63)-1;
		int cnt = 0;
		LinkedList<Character> op = new LinkedList();
		//만들려고 하는 수가 홀수면 일단 곱해서 짝수로 만듬
		if(n%2 == 1)
		{
//			while(n*2 > max) // 10^13에서 2배 한다고 해도 2^63보다는 작아서 처리해줄 필요 x
//			{				 // 만약에 다른 예제에서 n*2가 범위 초과면 *2해도 초과 안날때까지 n을 빼준다.
//				cnt++;
//				n-=2;
//				op.add("[+]");
//			}
			cnt++;
			n*=2; //
			op.add('/');
		}
		
//이부분은 잘못 생각한 건데 다음에도 똑같은 실수 할까봐 남겨놓음
//처음 접근은 2의 지수승으로 +/-를 통해서 이동한 후 나누기를 계속하는게 최선이라 생각했는데
//생각해보니 +/-의 연산수가 더 걸릴 것이라는걸 생각 못했었음..ㅜㅜ
/*		long n_exp = (long)Math.ceil(Math.log(n)/Math.log(2));
		long top = (long)Math.pow(2, n_exp);
		long bottom = (long)Math.pow(2, n_exp-1);
		long top_gap = top - n;
		long bottom_gap = n - bottom;
		if(top_gap < bottom_gap) // 2^x-1 < n < 2^x중 가까운거 만큼 + / - 로 이동
		{
			for(int i = (int)n; i<top; i+=2)
			{
				cnt++;
				if(cnt>99)
				{
					System.out.println("-1");
					return;
				}
				op.add("[-]");
				n+=2;
			}
			//이제 exp만큼 나누기 (연산은 곱하기로 찍혀야함)
		}
		else
		{
			for(int i = (int)n; i>bottom; i-=2)
			{
				cnt++;	
				op.add("[+]");
				n-=2;
				if(cnt>99)
				{
					System.out.println("-1");
					return;
				}
			}				
		}
*/

// 윗부분은 잘못 생각했다. 지수승에 가까운 대로 이동하는데 cnt를 더 잡아 먹는다.
// 그냥 짝수에서 처리해주는게 이득이었다.
// 짝수를 처리하는데 나누기 2했을 때 홀수 이면 -2
// 나누기 2 해도 짝수이면 나누기 2
		while(n>2)
		{
			if((n/2)%2 == 0) // 나눠도 짝수이면 나누기
			{
				n/=2;
				op.add('*');
			}
			else
			{
				n-=2;
				op.add('+');
			}
			cnt++;
		}
		if(n == 2)
		{
			op.add('+');
			cnt++;
		}
		if(n == 1)
		{
			cnt+=2;
			op.add('/');
			op.add('+');
		}
		if(cnt>99)
		{
			System.out.println("-1");
			return;
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter (System.out));
		bw.write(cnt+"\n");
		for(int j = op.size()-1; j >= 0; j--)
		{
			bw.write("["+op.get(j)+"] ");
		}
		bw.close();
	}

}