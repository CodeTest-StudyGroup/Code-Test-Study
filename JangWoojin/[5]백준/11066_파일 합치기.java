import java.io.*;
import java.util.*;

public class Main {

    static final int INF = Integer.MAX_VALUE;
    static int[][] dp;
    static int[] psum, file;
    static int n;

    static int go(int i, int j) {
        if (dp[i][j] != INF) {
            return dp[i][j];
        }

        for (int k = i; k < j; k++) {
            dp[i][j] = Math.min(dp[i][j], go(i, k) + go(k + 1, j));
        }
        
        return dp[i][j] += psum[j] - psum[i - 1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            dp = new int[n + 1][n + 1];
            psum = new int[n + 1];
            file = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            
            for (int i = 1; i <= n; i++) {
                file[i] = Integer.parseInt(st.nextToken());
                psum[i] = psum[i - 1] + file[i];
                Arrays.fill(dp[i], INF);
                dp[i][i] = 0;
                dp[i - 1][i] = file[i - 1] + file[i];
            }
            System.out.println(go(1, n));
        }
    }
}
