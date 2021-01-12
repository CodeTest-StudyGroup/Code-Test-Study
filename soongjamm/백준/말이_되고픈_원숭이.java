import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class 말이_되고픈_원숭이 {

    private static class Monkey {
        int x;
        int y;
        int k;
        int count;

        public Monkey(int x, int y, int k, int count) {
            this.x = x;
            this.y = y;
            this.k = k;
            this.count = count;
        }
    }

    public static void solution() {
        final int[] horse_dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        final int[] horse_dy = {1, 2, 2, 1, -1, -2, -2, -1};
        final int[] dx = {-1, 0, 1, 0};
        final int[] dy = {0, 1, 0, -1};
        final Scanner scanner = new Scanner(System.in);

        int horse = Integer.parseInt(scanner.next());
        int col = Integer.parseInt(scanner.next());
        int row = Integer.parseInt(scanner.next());

        String[][] board = new String[row][col];
        boolean[][][] visit = new boolean[row][col][horse + 1];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = scanner.next();
            }
        }

        Queue<Monkey> q = new LinkedList<>();
        q.add(new Monkey(0, 0, horse, 0));
        visit[0][0][horse] = true;

        while (!q.isEmpty()) {
            Monkey pos = q.poll();
            int x = pos.x;
            int y = pos.y;

            if (x == row - 1 && y == col - 1) {
                System.out.println(pos.count);
                return;
            }

            // 원숭이로 움직일 때
            for (int i = 0; i < dx.length; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!(0 <= nx && nx < row && 0 <= ny && ny < col)) {
                    continue;
                }
                if (!board[nx][ny].equals("0")) {
                    continue;
                }

                if (visit[nx][ny][pos.k]) {
                    continue;
                }

                visit[nx][ny][pos.k] = true;
                q.add(new Monkey(nx, ny, pos.k, pos.count + 1));
            }

            // 말처럼 움직일 때
            for (int i = 0; i < horse_dx.length; i++) {
                if (pos.k <= 0) {
                    break;
                }
                int nx = x + horse_dx[i];
                int ny = y + horse_dy[i];

                if (!(0 <= nx && nx < row && 0 <= ny && ny < col)) {
                    continue;
                }
                if (!board[nx][ny].equals("0")) {
                    continue;
                }

                if (visit[nx][ny][pos.k - 1]) {
                    continue;
                }

                visit[nx][ny][pos.k - 1] = true;
                q.add(new Monkey(nx, ny, pos.k - 1, pos.count + 1));
            }
        }
        System.out.println(-1);
    }

    public static void main(String[] args) {
        solution();
    }

}
