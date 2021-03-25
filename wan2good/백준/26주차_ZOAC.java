import java.io.*;
import java.util.*;

public class Main {

	static String inputData;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		inputData = br.readLine();
		visited = new boolean[inputData.length()];
		
		solve(0,inputData.length());
	}
	
	private static void solve(int start, int end) {
		int minIdx=101;
		int min=Integer.MAX_VALUE;
		for(int i=start; i<end; i++) {
			if(!visited[i] && min>inputData.charAt(i)-'0') {
				min=inputData.charAt(i)-'0';
				minIdx=i;
			}
		}
		if(minIdx==101)
			return;
		visited[minIdx]=true;
		for(int i=0; i<inputData.length(); i++) {
			if(visited[i])
				System.out.print(inputData.charAt(i));
		}
		System.out.println();
		solve(minIdx+1,end);
		solve(start,minIdx);
	}
}
