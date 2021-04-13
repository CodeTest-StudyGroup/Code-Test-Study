#include<bits/stdc++.h>

using namespace std;

int N,M,K;
int p[30001];


int find(int a)
{
	if(p[a]==a)
		return a;
		
	return p[a] = find(p[a]);		
}

void Union(int a, int b)
{
	int p_a = find(a);
	int p_b = find(b);
	
	p[p_b] = p_a; 	
}

int main() 
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>N>>M>>K;
	
	vector<int> child(N+1,0);
	vector<int> dp(K,0);
	vector<int> visited(N+1,0);
	
	vector< vector<int> > graph(N+1);
	
	for(int i=1 ; i<=N ; i++)
	{
		cin>>child[i];	
		//p[i] = i;
	}
	
	for(int i=0 ; i<M ; i++)
	{
		int s,e;
		
		cin>>s>>e;
		graph[s].push_back(e);
		graph[e].push_back(s);
		//Union(s,e);
	}
	
		
	//knapsack
	for(int i=1 ; i<=N ; i++)
	{
		if(visited[i] == 1)
			continue;
			
		int candy=child[i];
		int child_cnt=1;
		
		//몇명인지 찾아 
		queue<int> q;
		
		q.push(i);
		visited[i]=1;
		
		bool flag = false;
		

		while(!q.empty())
		{
			int cur = q.front();
			q.pop();
		
			for(int j=0 ; j<graph[cur].size() ; j++)
			{
				if(visited[graph[cur][j]] == 1)
				{
					continue;
				}
				
				visited[graph[cur][j]]=1;
				q.push(graph[cur][j]);
				candy+=child[graph[cur][j]];
				child_cnt++;
			}
			
		}

		if(flag)
			continue;
		
		
		if(dp.size()-1 < child_cnt)
			continue;
			
		for(int j=dp.size()-1 ; j>=child_cnt ; j--)
		{
			dp[j] = max(dp[j], dp[j-child_cnt]+candy);
		}
	}

	cout<<dp[dp.size()-1];
	
}

