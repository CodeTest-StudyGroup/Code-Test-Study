// 2024-07-09 정여진
package week1;

import java.util.*;

public class 퇴사 {

	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);
	
		n = sc.nextInt();
		
		int[] T = new int[n];
		int[] P = new int[n];
		
		for(int i = 0; i < n; i++) {
			T[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
		int[] dp = new int[n + 1];
		
		for(int i = 0; i < n; i++) {
			if(i > 0) {
				dp[i] = Math.max(dp[i], dp[i - 1]);
			}
			int next = i + T[i];
			if(next <= n) {
				dp[next] = Math.max(dp[next], dp[i] + P[i]);
			}
		}
		int maxProfit = 0;
        for (int i = 0; i <= n; i++) {
            maxProfit = Math.max(maxProfit, dp[i]);
        }
        
        System.out.println(maxProfit);  // 결과 출력
        
        sc.close();
	}
}
