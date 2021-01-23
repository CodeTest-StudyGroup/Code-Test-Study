import java.io.*;
import java.util.*;

class Edge {
    int src, dst, cost;

    public Edge(int src, int dst, int cost) {
        this.src = src;
        this.dst = dst;
        this.cost = cost;
    }
}

public class Main {

    static int m, n;
    static int[] parent;
    static Edge[] edges;

    static int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            if (m == 0 && n == 0) {
                break;
            }

            parent = new int[m];
            edges = new Edge[n];

            for (int i = 0; i < m; i++) {
                parent[i] = i;
            }

            int total = 0;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int src = Integer.parseInt(st.nextToken());
                int dst = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                edges[i] = new Edge(src, dst, cost);
                total += cost;
            }

            Arrays.sort(edges, Comparator.comparingInt(o -> o.cost));

            int cnt = 0, sum = 0;
            for (Edge e : edges) {
                int pu = find(e.src);
                int pv = find(e.dst);
                if (pu != pv) {
                    parent[pu] = pv;
                    cnt++;
                    sum += e.cost;
                }
                if (cnt == m - 1) {
                    break;
                }
            }
            System.out.println(total - sum);
        }
    }
}
