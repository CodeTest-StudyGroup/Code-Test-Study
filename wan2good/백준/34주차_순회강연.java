import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Data> pq = new PriorityQueue<>();
        int p,d;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            p = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            pq.offer(new Data(p,d));
        }

        int[] visit = new int[10001];
        int ans=0,start=0;
        while(!pq.isEmpty()){
            Data cur = pq.poll();
            for (int i = cur.d; i >=1 ; i--) {
                if(visit[i] < cur.p){
                    visit[i] = cur.p;
                    break;
                }
            }

        }
        int sum = 0;
        for (int i = 0; i < visit.length; i++) {
            sum += visit[i];
        }
        System.out.println(sum);
    }

    static class Data implements Comparable<Data>{
        int p,d;
        Data(int p, int d){
            this.p=p;
            this.d=d;
        }

        @Override
        public int compareTo(Data o){
            return o.p - this.p;
        }
    }
}