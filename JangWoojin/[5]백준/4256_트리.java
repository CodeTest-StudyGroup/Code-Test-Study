import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static StringBuilder sb;
    static int n;
    static int[] pre, inIdx;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            input();
            sb = new StringBuilder();
            postOrder(0, 0, n-1);
            System.out.println(sb.toString());
        }
    }

    static void postOrder(int root, int left, int right) {
        if (left > right) return;

        int idx = inIdx[pre[root]];
        postOrder(root + 1, left, idx - 1);
        postOrder(root + idx - left + 1, idx + 1, right);
        sb.append(pre[root]).append(" ");
    }



    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        pre = new int[n];
        inIdx = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pre[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            inIdx[Integer.parseInt(st.nextToken())] = i;
        }
    }
}
