import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[][] map = new int[m][m];
        int[] psum = new int[m * 2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int zero = Integer.parseInt(st.nextToken());
            int one = Integer.parseInt(st.nextToken());
            int two = Integer.parseInt(st.nextToken());
            psum[zero]++;
            psum[zero + one]++;
        }

        int sum = 0, idx = 0;
        for (int i = m-1; i >= 0; i--) {
            sum += psum[idx++];
            map[i][0] = sum + 1;
        }
        for (int i = 1; i < m; i++) {
            sum += psum[idx++];
            map[0][i] = sum + 1;
        }

        for (int i = 1; i < m; i++) {
            System.arraycopy(map[0], 1, map[i], 1, m - 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}
