
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 1. 처음 주어진 path로 0부터 출발하는 BFS를 이용하여 방향그래프를 만든다.
 * 2. order를 방향그래프에 추가해준다.
 * 3. 각 노드에 대해 싸이클이 존재하는지 여부를 검사한다.
 * 싸이클이 존재한다는 것은 자기 자신을 방문하기 위해 반드시 자기 자신을 거쳐가야 한다는 모순이 발생한다.
 * 즉, 싸이클이 존재하면 해당 노드에 진입할 수가 없다.
 * =================> 효율성 테스트를 통과하지 못했는데 해결하지 못해서, 위상정렬로 다시 풀었음.
 * 2번까지 동일
 * 3. 위상 정렬
 */
class Solution {

    boolean answer = true;
    int[] entry;

    public boolean solution(int n, int[][] path, int[][] order) {

        entry = new int[n];

        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // 초기 설정
        for (int i = 0; i < path.length; i++) {
            int from = path[i][0];
            int to = path[i][1];
            graph.get(from).add(to);
            graph.get(to).add(from);
        }

        // 방향그래프
        // 각 노드가 갈 수 있는 방향을 가리키고 있다.
        graph = bfs(graph);

        // order 적용
        for (int i = 0; i < order.length; i++) {
            int prereq = order[i][0]; // 먼저 들려야
            int target = order[i][1]; // 갈수 있다.

            if (target == 0) {
                return false;
            }

            graph.get(prereq).add(target);
            entry[target] += 1;
        }

        // cycle 여부 확인 - X안함X

        // 위상 정렬
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);

        for (int i = 0; i < n; i++) {
            if (q.size() == 0) {
                answer = false;
                break;
            }

            int now = q.poll();

            for (int j = 0; j < graph.get(now).size(); j++) {
                int target = graph.get(now).get(j);
                entry[target] -= 1;
                if (entry[target] == 0) {
                    q.offer(target);
                }
            }

        }

        return answer;
    }

    private ArrayList<ArrayList<Integer>> bfs(ArrayList<ArrayList<Integer>> graph) {
        int len = graph.size();
        boolean[] visited = new boolean[len];
        ArrayList<ArrayList<Integer>> dGraph = new ArrayList<>();

        for (int i = 0; i < len; i++) {
            dGraph.add(new ArrayList<>());
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = true;

        while (!q.isEmpty()) {
            int now = q.poll();
            for (int i = 0; i < graph.get(now).size(); i++) {
                int next = graph.get(now).get(i);
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                dGraph.get(now).add(next);
                q.offer(next);

                entry[next] += 1;
            }
        }

        return dGraph;
    }

}
