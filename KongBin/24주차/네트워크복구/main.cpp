#include <bits/stdc++.h>

using namespace std;

int N,M;

struct Data
{
	int start;
	int end;
	int cost;
	
	Data(int a, int b, int c)
	{
		start=a;
		end=b;
		cost=c;
	}
	
	bool operator<(const Data &b)const{
		return cost>b.cost;
	}
};

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>N>>M;
	vector<Data> data[N+1];
	
	for(int i=0 ; i<M ; i++)
	{
		int s,e,c;
		
		cin>>s>>e>>c;
		data[s].push_back(Data(s,e,c));
		data[e].push_back(Data(e,s,c));
	}
	
	vector<int> distance(N+1,2147000000);
	vector<pair<int,int> > res;
	int cnt=0;

	priority_queue<Data> pq;
	pq.push(Data(1,1,0));
	distance[1]=0;
	
	while(!pq.empty())
	{
		int start=pq.top().start;
		int new_start=pq.top().end;
		int cost=pq.top().cost;
		
		pq.pop();
		
		if(cost>distance[new_start])
			continue;
	
		if(new_start!=1)
		{
			cnt++;
			res.push_back(make_pair(start,new_start));
		}
		

			
		for(int j=0 ; j<data[new_start].size() ; j++)
		{
			int next_pos = data[new_start][j].end;
			int next_cost = cost+data[new_start][j].cost;
				
			if(distance[next_pos] > next_cost){
				distance[next_pos] = next_cost;
				pq.push(Data(new_start, data[new_start][j].end, cost+data[new_start][j].cost));
			}
		}
	}
	cout<<cnt<<"\n";

	for(int i=0 ; i<res.size() ; i++)
		cout<<res[i].first<<" "<<res[i].second<<"\n";

	
}
