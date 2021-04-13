#include bitsstdc++.h

using namespace std;

int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int res=1;
int area_num=2;

void DFS(vector vectorint  &board, vector vectorint  &visited, int start_x, int start_y)
{
	
	for(int i=0 ; i4 ; i++)
	{
		if(start_x+dx[i]0  start_x+dx[i]=n  start_y+dy[i]0  start_y+dy[i]=m)
			continue;
		
		if(visited[start_x+dx[i]][start_y+dy[i]]0)
			continue;
			
		if(board[start_x+dx[i]][start_y+dy[i]]==0)
		{
			visited[start_x+dx[i]][start_y+dy[i]] = area_num;
			res++;
			DFS(board,visited,start_x+dx[i],start_y+dy[i]);
		}
	}
	
}

int main(void)
{	
	iossync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cinnm;
	
	vector vectorint  board(n);
	vector vectorint  visited(n);
	vector pairint,int  one_set;
	vectorint res_set;
	int idx=0;
	
	res_set.push_back(-2147000000); res_set.push_back(-2147000000);
	 
	for(int i=0 ; in ; i++)
	{
		for(int j=0 ; jm ; j++)
		{
			char temp;
			
			cintemp;
			board[i].push_back(temp-'0');
			visited[i].push_back(0);
		}
	}

	for(int i=0 ; in ; i++)
	{
		for(int j=0 ; jm ; j++)
		{
			if(board[i][j] == 1)
				one_set.push_back({i,j});
			if(board[i][j]==0 && visited[i][j]==0)
			{

				visited[i][j] = area_num;
		
				DFS(board,visited,i,j);
				res = (res)%10;
				area_num++;
				res_set.push_back(res);
				res=1;
			}
		}
	}

	for(int i=0 ; ione_set.size() ; i++)
	{
		int x=one_set[i].first;
		int y=one_set[i].second;
		
		setint check;
		
		for(int j=0 ; j4 ; j++)
		{
			if(x+dx[j]0  x+dx[j]=n y+dy[j]0  y+dy[j]=m)
				continue;
			
			if(visited[x+dx[j]][y+dy[j]]==0)
				continue;	
				
			if(check.find(visited[x+dx[j]][y+dy[j]]) != check.end())
				continue;
			
			board[x][y] = (board[x][y]+res_set[visited[x+dx[j]][y+dy[j]]])%10;
			check.insert(visited[x+dx[j]][y+dy[j]]);
		}
	}
	
	for(int i=0 ; in ; i++)
	{
		for(int j=0 ; jm ; j++)
			coutboard[i][j];
		coutn;
	}
}
