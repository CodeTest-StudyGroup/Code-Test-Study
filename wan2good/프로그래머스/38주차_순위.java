class Solution {
	int[][] distance;
	
    public int solution(int n, int[][] results) {
        int answer = 0;
        this.distance = new int[n][n];
        for(int[] result: results) {
        	int x = result[0]-1;
        	int y = result[1]-1;
        	distance[x][y] = 1;
        	distance[y][x] = -1;
        }
        
        for(int k=0; k<n; k++) {
        	for(int i=0; i<n; i++) {
        		for(int j=0; j<n; j++) {
        			if(distance[i][j]==0) {
        				if(distance[i][k]==1 && distance[k][j]==1)
        					distance[i][j] = 1;
        				else if(distance[i][k] == -1 && distance[k][j]==-1)
        					distance[i][j] = -1;
        			}
        		}
        	}
        }
        
        for(int[] row : distance) {
        	int cnt=0;
        	for(int i=0; i<n; i++) {
        		if(row[i]==0)
        			cnt++;
        	}
        	if(cnt==1) {
        		answer++;
        	}
        }
        
        return answer;
    }
}

public class Main {	
	public static void main(String[] args){
		int n = 5;
		int[][] results = {
				{4,3},
				{4,2},
				{3,2},
				{1,2},
				{2,5}
		};
		
		System.out.println(new Solution().solution(n,results));
	}
	
}