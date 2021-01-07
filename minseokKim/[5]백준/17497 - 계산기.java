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
		//������� �ϴ� ���� Ȧ���� �ϴ� ���ؼ� ¦���� ����
		if(n%2 == 1)
		{
//			while(n*2 > max) // 10^13���� 2�� �Ѵٰ� �ص� 2^63���ٴ� �۾Ƽ� ó������ �ʿ� x
//			{				 // ���࿡ �ٸ� �������� n*2�� ���� �ʰ��� *2�ص� �ʰ� �ȳ������� n�� ���ش�.
//				cnt++;
//				n-=2;
//				op.add("[+]");
//			}
			cnt++;
			n*=2; //
			op.add('/');
		}
		
//�̺κ��� �߸� ������ �ǵ� �������� �Ȱ��� �Ǽ� �ұ�� ���ܳ���
//ó�� ������ 2�� ���������� +/-�� ���ؼ� �̵��� �� �����⸦ ����ϴ°� �ּ��̶� �����ߴµ�
//�����غ��� +/-�� ������� �� �ɸ� ���̶�°� ���� ���߾���..�̤�
/*		long n_exp = (long)Math.ceil(Math.log(n)/Math.log(2));
		long top = (long)Math.pow(2, n_exp);
		long bottom = (long)Math.pow(2, n_exp-1);
		long top_gap = top - n;
		long bottom_gap = n - bottom;
		if(top_gap < bottom_gap) // 2^x-1 < n < 2^x�� ������ ��ŭ + / - �� �̵�
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
			//���� exp��ŭ ������ (������ ���ϱ�� ��������)
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

// ���κ��� �߸� �����ߴ�. �����¿� ����� ��� �̵��ϴµ� cnt�� �� ��� �Դ´�.
// �׳� ¦������ ó�����ִ°� �̵��̾���.
// ¦���� ó���ϴµ� ������ 2���� �� Ȧ�� �̸� -2
// ������ 2 �ص� ¦���̸� ������ 2
		while(n>2)
		{
			if((n/2)%2 == 0) // ������ ¦���̸� ������
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