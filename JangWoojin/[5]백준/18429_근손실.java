import java.io.*;
import java.util.*;

public class Main {

    static final int MIN = 500;
    static int[] kit;
    static boolean[] chk;
    static int n, k, ans;

    static void dfs(int weight, int cnt) {
        if (cnt == n) {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!chk[i] && weight + kit[i] - k >= MIN) {
                chk[i] = true;
                dfs(weight + kit[i] - k, cnt + 1);
                chk[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        kit = new int[n];
        chk = new boolean[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            kit[i] = Integer.parseInt(st.nextToken());
        }

        dfs(500, 0);

        System.out.println(ans);
    }
}
