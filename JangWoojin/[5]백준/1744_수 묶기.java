import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0, i, j;
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        for (i = 0; i+1 < n && arr[i+1] < 1; i += 2) {
            ans += arr[i] * arr[i+1];
        }
        for (j = n-1; j-1 >= 0 && arr[j-1] > 1; j -= 2) {
            ans += arr[j] * arr[j-1];
        }
        for (; i <= j; i++) ans += arr[i];

        System.out.println(ans);
    }
}
