#include <bits/stdc++.h>

using namespace std;

int N;
long long res1,res2,res3;
long long result;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>N;

	vector<long long> arr;
	
	for(int i=0 ; i<N ; i++){
		long long temp;
		
		cin>>temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(),arr.end());
	
	
	int left=0;
	int right=arr.size()-1;
	result=abs(arr[0]+arr[1]+arr[2]);

	for(int i=0 ; i<arr.size()-2 ; i++)
	{
		left=i+1;
		right=arr.size()-1;
		
		while(left<right)
		{
			long long cur = arr[left]+arr[right]+arr[i];
			
			if(abs(cur)<=result){
				result=abs(cur);
				
				res1=arr[i];
				res2=arr[left];
				res3=arr[right];
			}
			
			if(cur == 0)
			{
				cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right];
				return 0;	
			}	
			else if(cur>0)	
				right--;
			else
				left++;	
		}
	
	}
	
	cout<<res1<<" "<<res2<<" "<<res3;
}
