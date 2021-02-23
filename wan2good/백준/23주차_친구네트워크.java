import java.util.*;
import java.io.*;

public class Main {

	static HashMap<String,Integer> mymap;
	static int friendNum=1;
	static int[] parent;
	static int[] count;
	
	public static int find_parent(int x) {
		if(x!=parent[x]) {
			parent[x] = find_parent(parent[x]);
		}
		return parent[x];
	}
	
	public static int union(int a, int b) {
		int x, y;
		x = find_parent(a);
		y = find_parent(b);

		if(x==y) {
			return count[x];
		}
		
		if(x<y) {
			parent[y]=x;
			count[x]+=count[y];
			return count[x];
		}
		else {
			parent[x]=y;
			count[y]+=count[x];
			return count[y];
		}
	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int t;
		t = Integer.parseInt(br.readLine());
		String a,b;
		StringBuilder sb = new StringBuilder();
		while(t-->0)
		{
			mymap = new HashMap<>();
			friendNum=1;
			int n = Integer.parseInt(br.readLine());
			parent = new int[2*n+1];
			count = new int[2*n+1];
			for(int i=1; i<=2*n; i++) {
				parent[i]=i;
				count[i]=1;
			}
			
			
			for(int i=0; i<n; i++) {
				st = new StringTokenizer(br.readLine());
				a = st.nextToken(); b = st.nextToken();
				
				if(!mymap.containsKey(a)) {
					mymap.put(a, friendNum++);
				}
				if(!mymap.containsKey(b)) {
					mymap.put(b, friendNum++);
				}
				
				sb.append(union(mymap.get(a),mymap.get(b))).append('\n');
			}
			
		}
		System.out.println(sb.toString());
	}

}
