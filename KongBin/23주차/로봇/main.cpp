#include <bits/stdc++.h>

using namespace std;

int N,M;

struct Data
{
	int x;
	int y;
	int dir;
	int point;
	
	Data(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		dir=c;
		point=d;
	}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cal_dir[4][4];
int res=2147000000;
int visited[101][101][4];

void find_result(Data &start, Data &end, vector< vector<int> > &board)
{	
	fill(visited[0][0],visited[N+1][0],0);
	
	queue<Data> q;
	
	q.push(start);
	visited[start.x][start.y][start.dir]=1;
	
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int dir=q.front().dir;
		int point = q.front().point;
		
		q.pop();
		
		if(x==end.x && y==end.y)
		{
			if(res>point+cal_dir[dir][end.dir])
				res=point+cal_dir[dir][end.dir];
			
			return;
		}
		
		for(int j=1; j<=3 ; j++)
		{
			int next_x=x+dx[dir]*j;
			int next_y=y+dy[dir]*j;
			
			if(next_x<1 || next_x>N || next_y<1 || next_y>M)
				break;
				
			if(board[next_x][next_y]==1)
				break;
				
			if(visited[next_x][next_y][dir]==1)
				continue;
			
			visited[next_x][next_y][dir]=1;
			q.push(Data(next_x, next_y, dir, point+1));
		}
		
		for(int i=0 ; i<4 ; i++)
		{
			if(visited[x][y][i]==1 || i==dir)
				continue;		
			
			visited[x][y][i]=1;
			q.push(Data(x,y,i,point+cal_dir[dir][i]));
		}
	}	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>N>>M;
	
	vector< vector<int> > board(N+1, vector<int>(M+1,0));
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++)
			cin>>board[i][j];
	
	int x,y,dir;
	
	//시작점
	cin>>x>>y>>dir;
	Data start = Data(x,y,dir-1,0);
	
	//도착점
	cin>>x>>y>>dir;
	Data end = Data(x,y,dir-1,0); 
	
	//방향별 점수 초기화
	cal_dir[0][1]=2; cal_dir[0][2]=1; cal_dir[0][3]=1;
	cal_dir[1][0]=2; cal_dir[1][2]=1; cal_dir[1][3]=1;
	cal_dir[2][0]=1; cal_dir[2][1]=1; cal_dir[2][3]=2;
	cal_dir[3][0]=1; cal_dir[3][1]=1; cal_dir[3][2]=2;
	 
	find_result(start,end,board);
	cout<<res;
}
