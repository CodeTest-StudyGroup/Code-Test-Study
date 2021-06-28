import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] dp = new int[n + 1][m + 1];
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 1; j <= m; j++) {
                if (input[j - 1] == '1') {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    answer = Math.max(answer, dp[i][j]);
                }
            }
        }
        System.out.println(answer * answer);
    }
}
