import java.io.*;
import java.util.StringTokenizer;
public class Main
{
	static int[] arr;
	static int[] max_tree;
	static int[] min_tree;

	public static void main(String[] args)throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		arr = new int[n];
		int m = Integer.parseInt(st.nextToken());
		int x = (int)Math.pow(2,Math.ceil(Math.log(n)/Math.log(2)+1));
		max_tree = new int[x];
		min_tree = new int[x];
		for(int i = 0; i< n; i++)
		{
			arr[i] = Integer.parseInt(br.readLine());			
		}
		make(0,n-1,1);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i = 0 ; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());			
			int[] value = find(0,n-1,a-1,b-1,1);
			bw.write(value[0]+" "+value[1]+"\n");
		}
		bw.close();
	}
	public static int[] find(int start, int end, int left, int right, int node)
	{
		if(left<= start && end <= right)
		{
			int[] r = new int[2];
			r[0] = min_tree[node];
			r[1] = max_tree[node];			
			return r;
		}
		else if(start > right || end <left)
		{
			int[] zero = new int[2];
			zero[0] = Integer.MAX_VALUE;
			zero[1] = 0;
			return zero;
		}
		int mid = (start+end)/2;
		int[] left_a = find(start,mid,left,right,node*2);
		int[] right_a = find(mid+1,end,left,right,node*2+1);
		int[] return_a = new int[2];
		return_a[0] = Math.min(left_a[0], right_a[0]);
		return_a[1] = Math.max(left_a[1], right_a[1]);
		return return_a;
	}
	public static int[] make(int start,int end, int node)
	{
		if(start == end)
		{
			max_tree[node] = arr[start];
			min_tree[node] = arr[start];
			int[] r = new int[2];
			r[0] = arr[start];
			r[1] = arr[start];
			return r;
		}
		int mid = (start+end)/2;
		int[] left = make(start,mid,node*2);
		int[] right = make(mid+1,end,node*2+1);
		int[] ret = new int[2];
		min_tree[node] = ret[0] = Math.min(left[0], right[0]);
		max_tree[node] = ret[1] = Math.max(left[1], right[1]);
		return ret;
	}
}