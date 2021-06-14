import java.util.*;
import java.io.*;

class Data{
	int x,y,cost;
	Data(int x, int y,int cost){
		this.x=x;
		this.y=y;
		this.cost=cost;
	}
}

class Solution {
	Queue<Data> q;
	boolean visited[][];
	int[] dx = {-1,0,1,0}; int[] dy = {0,-1,0,1};
	int row,col;
	
    public int solution(int[][] maps) {
        int answer = -1;
        this.q = new LinkedList<>();
        this.row = maps.length;
        this.col = maps[0].length;
        this.visited = new boolean[row][col];
        
        int sx = 0, sy=0;
        q.offer(new Data(sx,sy,1));
        visited[sx][sy]=true;
        
        while(!q.isEmpty()) {
        	Data cur = q.poll();
        	int x = cur.x;
        	int y = cur.y;
        	int cost = cur.cost;
        	if(x==this.row-1 && y==this.col-1)
        	{
        		answer = cost;
        		break;
        	}
        	for(int idx=0; idx<4; idx++) {
        		int nx = x + this.dx[idx];
        		int ny = y + this.dy[idx];
        		if(check(nx,ny) && !this.visited[nx][ny] && maps[nx][ny]==1) {
        			this.visited[nx][ny] = true;
        			q.offer(new Data(nx,ny,cost+1));
        		}
        	}
        }
        
        return answer;
    }
    
    public boolean check(int nx, int ny) {
    	if(0<=nx && nx<this.row && 0<=ny && ny<this.col) {
    		return true;
    	}
    	return false;
    }
}

public class Main {	
	public static void main(String[] args){
		int[][] maps = {
				{1,0,1,1,1},
				{1,0,1,0,1},
				{1,0,1,1,1},
				{1,1,1,0,1},
				{0,0,0,0,1}
		};
		
		System.out.println(new Solution().solution(maps));
	}
	
}