import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args)throws Exception
	{
		long sum = 0;
		HashMap<Character,Integer> map = new HashMap();
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		//중요도를 계산해서 입력 쭉 받았을 때 중요도가 높은 알파벳 부터 10, 9 부여
		//중요도는 10^자리수 * 해당 자리수에서 나온 수
		node[] index = new node[26];
		int[] score = new int[26]; // A-Z에 10~1점 중 무엇인가가 기록될 배열, 중요도에 의해 결정됨
		String[] input = new String[n];
		for(int i = 0 ; i < 26; i++)
		{
			index[i] = new node((char)(65+i));
		}
		for(int i = 0 ; i < n; i++)
		{
			int pow_count = 0;
			String cur_input = br.readLine();
			input[i] = cur_input;
			char[] input_c = cur_input.toCharArray();
			for(int j = input_c.length-1; j >= 0; j--)
			{
				index[input_c[j] - 65].value += Math.pow(10, pow_count++);
			}
		}
		Arrays.sort(index);
		int max_score = 9;
		for(int i = 25; i > 16; i--)
		{
			score[index[i].alpha-65] = max_score--;
		}
		for(int i = 0 ; i < n; i++)
		{
			char[] input_c = input[i].toCharArray();
			int pow_count = 0;
			long cur = 0;
			for(int j = input_c.length-1; j >= 0; j--)
			{
				cur += Math.pow(10, pow_count++)*score[input_c[j]-65];				
			}
			sum+=cur;
		}
		System.out.println(sum);
	}
}
class node implements Comparable<node>
{
	char alpha = 0;
	long value;
	node(char c)
	{
		alpha = c;
	}
	@Override
	public int compareTo(node o2) {
		if(this.value < o2.value)
			return -1;
		else if(this.value > o2.value)
			return 1;
		// TODO Auto-generated method stub
		return 0;
	}
}