import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static int[] data;
	static Stack<Data> stack = new Stack<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		data = new int[n+1];
		st = new StringTokenizer(br.readLine());
		
		for(int i=1; i<=n; i++)
			data[i] = Integer.parseInt(st.nextToken());
		
		StringBuilder sb = new StringBuilder();
		for(int i=1; i<=n; i++) {
			if(stack.isEmpty()) {
				sb.append(0).append(" ");
				stack.push(new Data(i,data[i]));
			}
			else {
				while(true) {
					if(stack.isEmpty()) {
						sb.append(0).append(" ");
						stack.push(new Data(i,data[i]));
						break;
					}
					else {
						Data top = stack.peek();
						if(top.value>data[i]) {
							sb.append(top.idx).append(" ");
							stack.push(new Data(i,data[i]));
							break;
						}
						else {
							stack.pop();
						}
					}
				}
			}
		}
		System.out.println(sb.toString());
	}
	
	static class Data{
		int idx;
		int value;
		Data(int idx, int value){
			this.idx= idx;
			this.value = value;
		}
	}
}