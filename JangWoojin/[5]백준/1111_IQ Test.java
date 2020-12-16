import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if (n == 1) {
            System.out.println('A');
        } else if (n == 2) {
            if (arr[0] == arr[1]) {
                System.out.println(arr[0]);
            } else {
                System.out.println('A');
            }
        } else {
            int a, b;
            if (arr[0] == arr[1]) {
                a = 1;
                b = 0;
            } else {
                a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
                b = arr[1] - arr[0] * a;
            }
            boolean flag = true;
            for (int i = 1; i < n; i++) {
                if (arr[i-1] * a + b != arr[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(arr[n-1] * a + b);
            } else {
                System.out.println('B');
            }
        }
    }
}
