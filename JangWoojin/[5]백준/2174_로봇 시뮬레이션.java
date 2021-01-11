import java.io.*;
import java.util.*;

class Robot {
    int x, y, d;

    public Robot(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }
};

public class Main {

    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static int[][] map;
    static Robot[] robots;
    static int a, b, n, m;

    static int getDirection(char d) {
        if (d == 'E') return 0;
        else if (d == 'S') return 1;
        else if (d == 'W') return 2;
        else if(d == 'N') return 3;
        return -1;
    }

    static int pass(int idx, int num) {
        int x = robots[idx].x;
        int y = robots[idx].y;
        int d = robots[idx].d;
        map[x][y] = 0;
        for (int i = 0; i < num; i++) {
            x += dx[d];
            y += dy[d];
            if (x < 0 || x >= b || y < 0 || y >= a) return -1;
            if (map[x][y] != 0) return map[x][y];
        }
        robots[idx].x = x;
        robots[idx].y = y;
        map[x][y] = idx;
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[b][a];
        robots = new Robot[n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);

            map[b-y][x-1] = i;
            robots[i] = new Robot(b-y, x-1, getDirection(d));
        }

        boolean flag = true;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);
            int num = Integer.parseInt(st.nextToken());

            if (d == 'L') {
                robots[idx].d = (robots[idx].d + 3 * num) % 4;
            } else if (d == 'R') {
                robots[idx].d = (robots[idx].d + num) % 4;
            } else if (d == 'F') {
                int res = pass(idx, num);
                if (res == -1) {
                    System.out.printf("Robot %d crashes into the wall\n", idx);
                    flag = false;
                    break;
                } else if (res > 0) {
                    System.out.printf("Robot %d crashes into robot %d\n", idx, res);
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            System.out.println("OK");
        }
    }
}
