package p1167;

import java.util.*;
import java.io.*;

class Edge {
    int v, d;

    public Edge(int v, int d) {
        this.v = v;
        this.d = d;
    }
}

class Main {
    static ArrayList<Edge>[] edges;
    static int n;
    static int farthestNode;
    static int maxDistance;

    public static void dfs(int node, int prev, int distance) {
        if (distance > maxDistance) {
            maxDistance = distance;
            farthestNode = node;
        }

        for (Edge e : edges[node]) {
            if (e.v != prev) {
                dfs(e.v, node, distance + e.d);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        edges = new ArrayList[n + 1];

        for (int i = 0, u, v, d; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            edges[u] = new ArrayList<>();
            while (st.hasMoreTokens()) {
                v = Integer.parseInt(st.nextToken());
                if (v == -1) break;
                d = Integer.parseInt(st.nextToken());
                edges[u].add(new Edge(v, d));
            }
        }

        dfs(1, 1, 0);
        dfs(farthestNode, farthestNode, 0);

        System.out.println(maxDistance);
    }
}