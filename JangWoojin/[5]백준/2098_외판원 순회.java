import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 987654321;
    static int[][] cost;
    static int[][] cache;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        cost = new int[n][n];
        cache = new int[n][1 << n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(tsp(0, 1));
    }

    public static int tsp(int cur, int visited) {
        if (visited == (1 << n) - 1)
            return cost[cur][0] == 0 ? INF : cost[cur][0];

        if (cache[cur][visited] != 0)
            return cache[cur][visited];

        int ret = INF;
        for (int i = 1; i < n; i++) {
            if ((visited & 1<<i) != 0 || cost[cur][i] == 0)
                continue;
            ret = Math.min(ret, tsp(i, visited | 1<<i) + cost[cur][i]);
        }

        return cache[cur][visited] = ret;
    }

}
