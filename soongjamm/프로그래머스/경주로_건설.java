import java.util.LinkedList;
import java.util.Queue;

/**
 * board의 크기는 n * n
 * board의 값 0은 이동 가능, 1은 벽
 * 직선도로는 비용이 100, 코너는 비용이 500
 * (0.0) 에서 (n-1. n-1)로 가는 최저비용을 계산해라.
 * <p>
 * 최단경로 찾기는 BFS를 사용하면 된다.
 * 단, 이동하면서 방향에 따라 비용을 계산할 수 있도록 총 비용 정보와 직전 방향 정보를 담는 객체가 필요하다.
 */

class Solution {
    public int solution(int[][] board) {
        int answer = Integer.MAX_VALUE;
        int N = board.length;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        int[][] visited = new int[N][N];
        Queue<Road> q = new LinkedList<>();

        // 시작점 설정
        q.add(new Road(0, 0, 0, -1));
        board[0][0] = 1;

        while (!q.isEmpty()) {
            Road road = q.poll();
            int x = road.x;
            int y = road.y;

            if (x == N - 1 && y == N - 1) {
                answer = Math.min(answer, road.cost);
                continue;
            }

            for (int dir = 0; dir < dx.length; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) {
                    continue;
                }

                if (board[nx][ny] == 1) {
                    continue;
                }

                int cost = 100;
                if (road.beforeDir != -1 || road.beforeDir != dir) {
                    cost += 500;
                }

                if (visited[nx][ny] == 0 // 방문한 적이 없는 경우
                        || road.cost + cost <= visited[nx][ny]) {  // 방문한 적이 있으나, 새로운 값이 더 작은 경우. 같아도 if문에 들어가는 이유는, 같은 경우에도 q에 새로운 객체를 넣어서 이동해봐야 하니까.
                    visited[nx][ny] = road.cost + cost;
                    q.offer(new Road(nx, ny, road.cost + cost, dir));
                }
            }
        }
        return answer;
    }

}

class Road {
    int x;
    int y;
    int cost;
    int beforeDir;

    public Road(int x, int y, int cost, int beforeDir) {
        this.x = x;
        this.y = y;
        this.cost = cost;
        this.beforeDir = beforeDir;
    }
}