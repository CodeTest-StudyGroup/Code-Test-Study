import java.io.*;
import java.util.*;

public class 최솟값_찾기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int L = Integer.parseInt(input[1]);
        int[] numbers = new int[N];

        StringTokenizer numbersToken = new StringTokenizer(br.readLine(), " ");
        Deque<Integer> answerIndices = new LinkedList<>();

        for(int i=0; i<N; i++) {
            numbers[i] = Integer.parseInt(numbersToken.nextToken());
            while(!answerIndices.isEmpty() && numbers[answerIndices.getLast()] > numbers[i]) {
                answerIndices.removeLast();
            }
            answerIndices.addLast(i);
            if(!answerIndices.isEmpty() && answerIndices.getFirst() <= i-L) {
                answerIndices.removeFirst();
            }
            sb.append(numbers[answerIndices.getFirst()]).append(" ");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();

    }
}
