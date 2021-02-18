package 백준_단계별로풀어보기.정렬;

import java.io.*;
import java.util.*;

public class 컬러볼 {
    static class Node{
        int size;
        int color;
        int number;

        public Node(int size, int color, int number) {
            this.size = size;
            this.color = color;
            this.number = number;
        }
    }

    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        n = Integer.parseInt(bf.readLine());

        int[] answer = new int[n + 1];
        int[] color = new int[n + 1];

        List<Node> sort_node = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(bf.readLine());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            sort_node.add(new Node(s, c, i));
        }
        Collections.sort(sort_node, (a, b) -> {
            return a.size - b.size;
        });
        int sum = 0;
        for (int i = 0, j = 0; i < sort_node.size(); i++) {
            for (; sort_node.get(j).size < sort_node.get(i).size; j++) {
                sum += sort_node.get(j).size;
                color[sort_node.get(j).color] += sort_node.get(j).size;
            }
            answer[sort_node.get(i).number] = sum - color[sort_node.get(i).color];
        }
        for (int i = 1; i < n + 1; i++)
            System.out.println(answer[i]);

    }


}
