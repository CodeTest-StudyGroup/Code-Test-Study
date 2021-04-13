#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>N;

	vector<int> arr(N,0);
	vector<int> res;
	
	cin>>arr[0];
	res.push_back(arr[0]);
	
	for(int i=1 ; i<N ; i++)
	{
		cin>>arr[i];	
		if(res[res.size()-1] < arr[i])
			res.push_back(arr[i]);
		else
		{
			vector<int>::iterator iter = lower_bound(res.begin(),res.end(),arr[i]);
			res[iter-res.begin()]=arr[i];
		}
	}
	
	cout<<res.size();
}
