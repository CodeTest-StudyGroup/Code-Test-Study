import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
		{
			arr[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(arr);
		int sum =0;
		for(int i = n-1; i >=0; i--)
		{
			int temp = arr[i];
			//양*양,둘다 1보다 클때 곱
			if(i>0 && arr[i] >0 )
			{
				if(arr[i-1] >0)
				{
					if(arr[i] == 1 || arr[i-1] == 1)
					{
						sum+=temp;
						continue;
					}
					else
					{
						temp*=arr[i-1];
						i--;
						sum+=temp;
						continue;	
					}				
				}
				else
				{
					sum+=temp;
					continue;
				}
			}
			//음*양 패스
			else if(i>0 && arr[i] >0 && arr[i-1] < 0)
			{
				sum+=temp;
				continue;				
			}
			//영일때는 뒤에가 홀수 양수인지 체크
			else if(i>0 && arr[i] == 0)
			{
				//영일때 뒤에가 홀수이면 뒤에거 걍 곱해줌
				//영일때 뒤에가 짝수이면 그냥 안곱하고 패스
				if(i%2 == 0)
				{
					continue;
				}
				else
				{
					temp*=arr[i-1];
					i--;
				}
				sum+=temp;
				continue;
			}
			//음*음
			else if(i > 0 && arr[i] <0 && arr[i-1]<0)
			{
				if(i%2 == 0)
				{
					sum+=temp;
					continue;
				}
				else
				{
				temp*=arr[i-1];
				i--;
				sum+=temp;
				continue;
				}
			}
			else
			{
				sum+=temp;
				continue;
			}
		}
		System.out.println(sum);
	}
}
