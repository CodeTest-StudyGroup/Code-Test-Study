#include <bits/stdc++.h>

using namespace std;

int N;
int board[101][101];
int visited[101][101];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int earth_cnt=1;
vector< pair<int,int> > sub_res[10000];

void BFS(int x, int y)
{
	queue<pair<int,int> > q;
	
	q.push(make_pair(x,y));
	visited[x][y]=1;
	board[x][y]=earth_cnt;
	
	while(!q.empty())
	{
		int cur_x=q.front().first;
		int cur_y=q.front().second;
		
		q.pop();
		
		for(int i=0; i<4 ; i++)
		{
			if(cur_x+dx[i]<0 || cur_x+dx[i]>=N || cur_y+dy[i]<0 || cur_y+dy[i]>=N)
				continue;
			if(board[cur_x+dx[i]][cur_y+dy[i]]==0)
			{
				board[cur_x][cur_y]=-earth_cnt;
				sub_res[earth_cnt].push_back(make_pair(cur_x,cur_y));
				continue;
			}
			if(visited[cur_x+dx[i]][cur_y+dy[i]]==1)
				continue;
				
			visited[cur_x+dx[i]][cur_y+dy[i]]=1;
			board[cur_x+dx[i]][cur_y+dy[i]]=earth_cnt;
			q.push(make_pair(cur_x+dx[i], cur_y+dy[i]));
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>N;
	
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			cin>>board[i][j];
			
	
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<N ; j++)
		{
			if(visited[i][j]==0 && board[i][j]==1)
			{
				BFS(i,j);
				earth_cnt++;
			}
		}
	}
	
	if(earth_cnt==1)
	{
		cout<<0;
		return 0;
	}
	
	int result=10000;
	
	for(int i=0 ; i<earth_cnt ; i++)
	{	
		for(int j=i+1 ; j<earth_cnt ; j++)
		{
			for(int k=0 ; k<sub_res[i].size() ; k++)
			{
				for(int l=0 ; l<sub_res[j].size() ; l++)
				{
					int distance=abs(sub_res[i][k].first-sub_res[j][l].first)+abs(sub_res[i][k].second-sub_res[j][l].second);
					
					if(result > distance)
						result=distance;	
				}
			}
		}
	}
	
	if(result==10000)
		cout<<0;
	else
		cout<<result-1;
}
