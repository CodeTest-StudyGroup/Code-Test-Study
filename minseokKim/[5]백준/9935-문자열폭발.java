import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		String input = br.readLine();
		String bomb = br.readLine();
		int n = input.length();
		int m = bomb.length();
		String answer="";
		Stack<Character> input_l =new Stack();
		int j = 0;
		int n0 = n;
		int c = 0;
		boolean more = true;
		int back = 0;
		for(int i = 0 ; i < n; i++)
		{
			if(i >= input_l.size())
				input_l.push(input.charAt(c++));
			if(input_l.get(i) == bomb.charAt(j))
			{
				j++;
				back++;
			}
			else 
			{
				if(back > 0)
					i -= (back);
				j = 0;
				back = 0;
			}
			
			if(j == m)
			{
				for(int r = i; r > i-m; r--)
					input_l.pop();
				more = true;
				n-=m;
				i-= 2*m-1;
				j = 0;
				back = 0;
				if(i < 0)
					i = -1;
			}
		}
		Iterator it = input_l.iterator();
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter (System.out));
		int ans_size = 0;
		while(it.hasNext())
		{
			bw.write((Character)it.next());
			ans_size ++;
		}
		if(ans_size == 0)
			System.out.println("FRULA");
		else
			bw.close();
	}
}