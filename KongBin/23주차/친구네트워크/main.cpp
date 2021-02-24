#include <bits/stdc++.h>

using namespace std;

int N,M;

int find(int a,vector<int> &parent)
{
	if(parent[a] == a)
		return a;
	else
		return parent[a]=find(parent[a],parent);
}

int Union(int a, int b, vector<int> &parent, vector<int> &count)
{
	int p_a = find(a,parent);
	int p_b = find(b,parent);
	
	if(p_a == p_b)
	{
		return count[p_a];
	}
	else
	{
		parent[p_b]=p_a;
		count[p_a]+=count[p_b];
		return count[p_a];
	}
}

int main() {
	cin>>N;
	
	for(int i=0 ; i<N ; i++)
	{
		cin>>M;
	
		map<string,int> m;
		int idx=1;
		vector<int> count(M*2+1,1);
		vector<int> parent(M*2+1);
		 
		//ÃÊ±â 
		for(int j=1 ; j<=M*2 ; j++)
			parent[j]=j;
		
		for(int j=0 ; j<M ; j++)
		{
			string a,b;
			int idx_a,idx_b;
			
			cin>>a>>b;
			
			if(m[a]==0)
				m[a]=idx++;
			if(m[b]==0)
				m[b]=idx++;
			idx_a=m[a];
			idx_b=m[b];
			
			cout<<Union(idx_a,idx_b,parent,count);
		}
	}
}
