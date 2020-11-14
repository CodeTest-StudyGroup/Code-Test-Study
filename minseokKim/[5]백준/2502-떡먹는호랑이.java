import java.util.Scanner;

public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[] arr_A = new int[n+1];
		int[] arr_B = new int[n+1];
		arr_A[3] = 1;
		if(n > 3)
			arr_A[4] = 1;
		if(n > 4)
			arr_A[5] = 2;
		arr_B[3] = 1;

		if(n>3)
			arr_B[4] = 2;
		for(int i = 5; i<= n; i++)
		{
			if(i >= 6 )
				arr_A[i] = arr_A[i-1]+arr_A[i-2];
			arr_B[i] = arr_B[i-1]+arr_B[i-2];
		}
		int xa = arr_A[n];
		int xb = arr_B[n];
		for(int i = 1; i <= m/2+1; i++)
		{
			for(int j = i; j <= m/2+1; j++)
			{
				if(m == (i*xa + j *xb))
				{
					System.out.println(i);
					System.out.println(j);
					return;
				}
			}
		}
	}
}
