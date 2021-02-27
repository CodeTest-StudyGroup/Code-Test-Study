#include <bits/stdc++.h>

using namespace std;

int N,M;

int check[101];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>N>>M;
	
	vector<int> multitap;
	vector<int> task;
	
	int visited[101];
	fill(visited,visited+101,0);
	
	int cnt=0;
	int s_idx=0;
	
	for(int i=0 ; i<M ; i++)
	{
		int temp;
		
		cin>>temp;
		
		task.push_back(temp);
		
		if(cnt<N)
		{
			s_idx++;
			if(visited[temp]==0)
			{	
				visited[temp]=1;
				multitap.push_back(temp);
				check[temp]=1;
				cnt++;
			}
		}
		
	}
	
	int result=0;
	
	for(int i=s_idx ; i<M ; i++)
	{
		int temp;
		
		temp=task[i];
		
		if(find(multitap.begin(),multitap.end(),temp) != multitap.end())
			continue;
		vector<int> temp_multi;
		
		temp_multi.resize(multitap.size());
		copy(multitap.begin(), multitap.end(), temp_multi.begin());
		
	
		int j;
			
		fill(visited,visited+101,0);
		for(j=i+1 ; j<M ; j++)
		{
			
			if(check[task[j]]==1 && visited[task[j]]==0)
			{
				temp_multi.erase(find(temp_multi.begin(), temp_multi.end(), task[j]));
				visited[task[j]]=1;
			}
			
			if(temp_multi.size()==1)
			{
				multitap.erase(find(multitap.begin(), multitap.end(), temp_multi[0]));
				check[temp_multi[0]]=0;
				multitap.push_back(temp);
				check[temp]=1;
				result++;
				break;
			}
		}
		
		if(j==M)
		{
			multitap.erase(find(multitap.begin(), multitap.end(), temp_multi[0]));
			check[temp_multi[0]]=0;
			multitap.push_back(temp);
			check[temp]=1;
			result++;
		}
	}
	cout<<result;
	return 0;
}
