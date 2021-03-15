import java.io.*;
import java.util.*;

public class Main {

	static class Info implements Comparable<Info>{
		int i,x;
		Info(int i,int x){
			this.i = i;
			this.x = x;
		}
		
		@Override
		public int compareTo(Main.Info o) {
			return this.i-o.i;
		}
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		ArrayList<Info> list = new ArrayList<>();
		
		long people_sum = 0;
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			people_sum += b;
			list.add(new Info(a,b));
		}
		Collections.sort(list);
		
		int idx=0;
		long tmp=0;
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			tmp+=list.get(i).x;
			if(tmp*(long)2>=people_sum) {
				sb.append(list.get(i).i);
				break;
			}
				
		}
		System.out.println(sb.toString());
	}

}
