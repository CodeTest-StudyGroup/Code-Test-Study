#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
int res[500001];

int main() 
{
	int N;
	
	cin>>N;
		
	stack<int> s;
	
	arr.push_back(100000001);
	
	for(int i=1 ; i<=N ; i++)
	{
		int data;
		
		cin>>data;
		
		arr.push_back(data);	
	}	
	
	s.push(0);
	
	for(int i=1 ; i<=N ; i++)
	{
		if(arr[s.top()]>arr[i])
		{
			res[i] = s.top();
			s.push(i);	
		}
		else
		{
			while(!s.empty() && arr[s.top()]<=arr[i])
			{
				s.pop();
			}
			res[i] = s.top();
			s.push(i);
		}	
	}

	
	for(int i=1 ; i<=N ; i++)
		cout<<res[i]<<" ";
	
	

}
