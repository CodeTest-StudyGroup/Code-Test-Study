import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class 키패드_누르기 {

    public static Map<Integer, Pos> getPad() {
        Map<Integer, Pos> map = new HashMap<>();
        map.put(1, new Pos(0, 0, "left"));
        map.put(2, new Pos(0, 1, "center"));
        map.put(3, new Pos(0, 2, "right"));
        map.put(4, new Pos(1, 0, "left"));
        map.put(5, new Pos(1, 1, "center"));
        map.put(6, new Pos(1, 2, "right"));
        map.put(7, new Pos(2, 0, "left"));
        map.put(8, new Pos(2, 1, "center"));
        map.put(9, new Pos(2, 2, "right"));
        map.put(0, new Pos(3, 1, "center"));

        return map;
    }

    static Map<Integer, Pos> map;
    static String handed;

    public static String solution(int[] numbers, String hand) {
        String answer = "";
        handed = hand.equals("left") ? "L" : "R";
        map = getPad();

        Pos left = new Pos(3, 0, "left");
        Pos right = new Pos(3, 2, "right");

        for (int number : numbers) {
            Pos p = map.get(number);
            if (p.side.equals("left")) {
                answer += "L";
                left = p;
            } else if (p.side.equals("right")) {
                answer += "R";
                right = p;
            } else {
                String next = decideFinger(left, right, number);
                if (next.equals("L")) {
                    left = p;
                } else {
                    right = p;
                }
                answer += next;
            }

        }
        return answer;
    }

    private static String decideFinger(Pos left, Pos right, int number) {
        int l = bfs(left, number);
        int r = bfs(right, number);
        if (l < r) {
            return "L";
        } else if (l > r) {
            return "R";
        } else {
            return handed;
        }
    }

    private static int bfs(Pos finger, int number) {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        boolean[][] visited = new boolean[4][3];
        Pos target = map.get(number);

        Queue<bfsPos> q = new LinkedList<>();
        q.offer(new bfsPos(finger.x, finger.y, 0));

        while (!q.isEmpty()) {
            bfsPos p = q.poll();
            if (p.x == target.x && p.y == target.y) {
                return p.count;
            }
            for (int i=0; i<4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (0 <= nx && nx < 4 && 0 <= ny && ny < 3
                        && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.offer(new bfsPos(nx, ny, p.count+1));
                }

            }
        }

        return -1;
    }


    public static void main(String[] args) {
        solution(new int[]{1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
    }

    private static class bfsPos {
        int x;
        int y;
        int count;

        public bfsPos(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }

    private static class Pos {
        int x;
        int y;
        String side;

        public Pos(int x, int y, String side) {
            this.x = x;
            this.y = y;
            this.side = side;
        }
    }
}
