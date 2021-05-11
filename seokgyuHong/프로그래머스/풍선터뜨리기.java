package 월간코드챌린지1;

import java.util.*;
public class 풍선터뜨리기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] a= {-16,27,65,-2,58,-92,-71,-68,-61,-33};
		Solution.solution(a);
	}

}

class Solution {
	static int answer = 0;
	static int[] tree;
    public static int solution(int[] a) {

    	tree = new int[a.length*5];
    	insert(a,1,0,a.length-1);
    	
    	for(int i=0; i<a.length; i++)
    	{
    		int left = find(a,1,0,a.length-1,0,i);
    		int right= find(a,1,0,a.length-1,i,a.length-1);
    		System.out.println(left + " " + right);
    		if(left>= a[i] || right>=a[i])
    			answer++;
    	}
    	System.out.println(answer);
        return answer;
    }
    
    public static int insert(int[] a,int node, int start,int end)
    {
    	if(start==end)
    		return tree[node] = a[end];
    	else
    	{
    		int mid = (start+end)/2;
    		return tree[node] = Math.min(insert(a,node*2, start,mid),insert(a,node*2+1,mid+1,end));
    		
    	}
    	
    }
    public static int find(int[] a, int node, int start, int end, int left, int right )
    {
    	if(end<left || start>right)
    		return Integer.MAX_VALUE;
    	if(left<=start && end<=right)
    		return tree[node];
    	int mid = (start+end)/2;
    	return Math.min(find(a,node*2,start,mid,left,right),find(a,node*2+1,mid+1,end,left,right));
    }

}
