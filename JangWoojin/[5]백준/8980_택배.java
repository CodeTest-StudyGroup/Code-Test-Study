import java.io.*;
import java.util.*;

class Box {

    int src, dest, num;

    public Box(int src, int dest, int num) {
        this.src = src;
        this.dest = dest;
        this.num = num;
    }
}

public class Main {

    static List<Box> list = new ArrayList<>();
    static int[] capacity;
    static int n, c, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(br.readLine());
        capacity = new int[n + 1];
        Arrays.fill(capacity, c);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int src = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());
            list.add(new Box(src, dest, num));
        }

        list.sort(Comparator.comparingInt(o -> o.dest));

        int ans = 0;
        for (Box box : list) {
            int min = capacity[box.src];
            for (int i = box.src + 1; i < box.dest; i++) {
                min = Math.min(min, capacity[i]);
            }
            int num = Math.min(min, box.num);
            ans += num;
            for (int i = box.src; i < box.dest; i++) {
                capacity[i] -= num;
            }
        }
        System.out.println(ans);
    }
}
