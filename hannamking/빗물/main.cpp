#include <bits/stdc++.h>

using namespace std;


int main(void) 
{
	int arr[500];
	int res=0;
	int N,M;
	
	cin>>N>>M;
	
	for(int i=0 ; i<M ; i++)
		cin>>arr[i];
	
	for(int i=1 ; i<M-1; i++){
		int val = min(*max_element(arr,arr+i),*max_element(arr+i,arr+M));
		
		res+=abs(arr[i]-val);
	}
	cout<<res;

}
	

	
	


