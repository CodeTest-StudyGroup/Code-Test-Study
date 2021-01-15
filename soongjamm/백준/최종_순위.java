import java.util.*;

/**
 * 백준 3665 - 최종 순위
 * https://www.acmicpc.net/problem/3665
 */

public class 최종_순위 {

    public static void solution(Scanner scanner) {
        int n = scanner.nextInt(); // 팀의 개수
        int[] entry = new int[n + 1]; // 진입 차수. 1부터 n 까지를 인덱스를 사용하기 위해 +1 크기로 할당.
        int[][] matrix = new int[n + 1][n + 1];
        List<Integer> lastRank = new ArrayList<>();
        // 작년의 순위를 등록
        for (int i = 0; i < n; i++) {
            int target = scanner.nextInt();
            lastRank.add(target);
        }

        // 간선 정보 등록
        for (int i = 0; i < n; i++) {
            int now = lastRank.get(i);
            for (int j = i + 1; j < lastRank.size(); j++) { // now 순위는 자신의 다음 순위부터 간선으로 등록해야 하기 때문에 j = i + 1.
                int target = lastRank.get(j);
                matrix[now][target] = 1;
                entry[target]++;
            }
        }

        int m = scanner.nextInt(); // 상대 등수가 바뀐 쌍의 수
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            if (matrix[a][b] == 1) {
                matrix[a][b] = 0;
                matrix[b][a] = 1;
                entry[a]++;
                entry[b]--;
            } else if (matrix[b][a] == 1) {
                matrix[a][b] = 1;
                matrix[b][a] = 0;
                entry[a]--;
                entry[b]++;
            }
        }

        // 위상정렬 시작
        // 1등이 큐에 담긴다.
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (entry[i] == 0) {
                q.offer(i);
            }
        }

        // 본격적으로 순위를 정한다.
        // 각 팀의 순위를 정해주는 과정이고 불가능이면 메소드를 종료하는 과정이니까 팀의 수만큼만 진행하면 된다.
        List<Integer> finalRank = new ArrayList<>();
        for (int k=1; k<=n; k++) {
            if (q.size() > 1) { // 결과가 여러개 - ?
                System.out.println("?");
                return;
            }
            if (q.size() == 0) { // 정렬 불가능 - IMPOSSIBLE
                System.out.println("IMPOSSIBLE");
                return;
            }

            int now = q.poll();
            finalRank.add(now);

            for (int i = 1; i <= n; i++) {
                if (matrix[now][i] == 1) {
                    matrix[now][i] = 0;
                    entry[i]--;
                    if (entry[i] == 0) { // 일련의 과정을 처리 후 진입차수가 0이된 정점이 다음 순위이므로 큐에 담는다.
                        q.offer(i);
                    }
                }
            }

        }

        finalRank.stream().forEach(x -> System.out.print(String.format("%d ", x)));
        System.out.println();

//        // 테스트
//        // 간선
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                System.out.print(matrix[i][j] + " ");
//            }
//            System.out.println();
//        }
//        //노드
//        for (int i = 1; i <= n; i++) {
//            System.out.print(entry[i] + " ");
//        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        while (tc-- > 0) {
            solution(scanner);
        }
    }
}
