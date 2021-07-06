import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 네트워크복구 {

	static int N, M, K;
	static ArrayList<ArrayList<Edge>> edges;
	static int INF = 1000 * 10;
	static PriorityQueue<Edge> q;
	static int[] dist;
	static boolean visit[];
	static List<int[]> path;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new FileReader(new File("input/G_2211.txt")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		edges = new ArrayList<ArrayList<Edge>>();
		dist = new int[N + 1];
		visit = new boolean[N + 1];
		path = new ArrayList<int[]>();
		for (int i = 0; i <= N; i++) {
			edges.add(new ArrayList<Edge>());
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			edges.get(x).add(new Edge(y, p, p));
			edges.get(y).add(new Edge(x, p, p));
			path.add(new int[] { x, y, p });

		}
		trip(1);
	}

	public static void trip(int start) {
		q = new PriorityQueue<Edge>();
		q.add(new Edge(start, 0, 0));
		Arrays.fill(dist, INF);
		visit = new boolean[N + 1];
		dist[start] = 0;
		int count = 0;
		StringBuffer sb = new StringBuffer();
		while (!q.isEmpty()) {
			Edge e = q.poll();
			if (visit[e.n]) {
				continue;
			}
			visit[e.n] = true;
			if (e.o != 0) {
				sb.append(e.o + " " + e.n).append("\n");
				count++;
			}
			for (Edge next : edges.get(e.n)) {
				if (dist[next.n] > dist[e.n] + next.p) {
					dist[next.n] = dist[e.n] + next.p;
					q.add(new Edge(next.n, dist[next.n], e.n));

				}
			}
		}
		System.out.println(count);
		System.out.println(sb.toString());

	}

	public static class Edge implements Comparable<Edge> {
		int n;
		int p;
		int o;

		public Edge(int n, int p, int o) {
			this.n = n;
			this.p = p;
			this.o = o;
		}

		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return Long.compare(this.p, o.p);
		}
	}
}
