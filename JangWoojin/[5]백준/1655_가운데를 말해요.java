import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        maxHeap.offer(Integer.parseInt(br.readLine()));
        sb.append(maxHeap.element()).append(System.lineSeparator());

        for (int i = 0; i < n - 1; i++) {
            int x = Integer.parseInt(br.readLine());
            if (maxHeap.size() == minHeap.size()) {
                if (x <= minHeap.element()) {
                    maxHeap.offer(x);
                } else {
                    maxHeap.offer(minHeap.poll());
                    minHeap.offer(x);
                }
            } else {
                if (x >= maxHeap.element()) {
                    minHeap.offer(x);
                } else {
                    minHeap.offer(maxHeap.poll());
                    maxHeap.offer(x);
                }
            }
            sb.append(maxHeap.element()).append(System.lineSeparator());
        }

        System.out.println(sb.toString());
    }
}
